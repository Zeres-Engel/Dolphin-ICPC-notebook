/**
 * Author: Nguyen Hoang Anh
 * Date: 2020-01-12
 * License: CC0
 * Description: Heavy-Light Decomposition for path updates and queries on trees.
 * Usage: HeavyLightDecomposition hld(n); // n is number of nodes
 *        hld.add_edge(u,v); // add edge between u and v
 *        hld.DFS(1,1); // build DFS tree with root 1
 *        hld.HLD(1); // build HLD with root 1
 *        hld.update_up_HLD(u,v,val); // update path from u to v with value val
 *        hld.query_up_HLD(u,v); // query sum on path from u to v
 * Time: O(log^2 N) per operation
 * Status: stress-tested
 */
#pragma once

/*
    1-indexed tree, root = 1
    You are given a rooted tree consisting of n nodes. The nodes are numbered 1,2,\ldots,n, and node 1 is the root. Each node has a value.
    Your task is to process following types of queries:

    Update each vertice in path u to v by 1
    calculate sum of each edge
*/

struct ITLazy{
    long long sum, lazy;
};

struct HeavyLightDecomposition{
    int N, maxx_height;
    int num_chain, pos_in_base;
    vector<int> depth;
    vector<int> numChild;
    vector<int> chainHead, chainInd;
    vector<int> Base, posInBase;
    vector<vector<int>> Anc;
    vector<ITLazy> IT;
    vector<vector<int>> Adj;

    HeavyLightDecomposition(int N) : N(N){
        const int LOG2 = int(log2(N));
        depth.resize(N+1, 0);
        numChild.resize(N+1, 0);
        chainHead.resize(N+1, 0); chainInd.resize(N+1, 0);
        Base.resize(N+1, 0); posInBase.resize(N+1, 0);
        IT.resize(4*N+1, {0, 0});
        Adj.resize(N+1);
        Anc.resize(N+1, vector<int>(LOG2+1, 0));

        maxx_height = -1;
        depth[1] = 1;
        num_chain = 1;
        pos_in_base = 0;
        Anc[1][0] = 1;
    }

    void add_edge(int u, int v){
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    void DFS(int u, int par){
        numChild[u] = 1;
        for(int v: Adj[u]){
            if(v == par) continue;
            depth[v] = depth[u] + 1;
            Anc[v][0] = u;
            maxx_height = max(maxx_height, depth[v]);
            for(int j=1; j <= int(log2(maxx_height)); j++){
                Anc[v][j] = Anc[Anc[v][j-1]][j-1];
            }
            DFS(v, u);
            numChild[u] = numChild[u] + numChild[v];
        }
    }

    void HLD(int u){
        if(!chainHead[num_chain]){
            chainHead[num_chain] = u;
        }

        chainInd[u] = num_chain;
        posInBase[u] = ++pos_in_base;
        Base[pos_in_base] = u;
        int special_vertices = -1;
        for(int v: Adj[u]){
            if(v == Anc[u][0]) continue;
            if(special_vertices == -1 | numChild[v] > numChild[special_vertices]){
                special_vertices = v;
            }
        }

        if(special_vertices != -1) HLD(special_vertices);

        for(int v: Adj[u]){
            if(v == Anc[u][0] || v == special_vertices) continue;
            num_chain++;
            HLD(v);
        }
    }

    int Jump(int u, int v){
        assert(depth[u] <= depth[v]);
        int delta = depth[v] - depth[u];
        for(int i=log2(maxx_height); i >= 0; i--){
            if(delta >> i & 1){
                v = Anc[v][i];
            }
        }
        return v;
    }

    int LCA(int u, int v){
        if(u == v) return u;
        if(depth[u] > depth[v]) swap(u, v);
        v = Jump(u, v);
        if(u == v) return u;
        for(int i=log2(depth[u]); i >= 0; i--){
            if(Anc[u][i] != Anc[v][i]){
                u = Anc[u][i];
                v = Anc[v][i];
            }
        }

        return Anc[u][0];
    }

    void lazyUpdate(int id, int L, int R, int mid){
        IT[id << 1].lazy += IT[id].lazy;
        IT[id << 1 | 1].lazy += IT[id].lazy;

        IT[id << 1].sum += IT[id].lazy * 1ll * (mid - L + 1);
        IT[id << 1 | 1].sum += IT[id].lazy * 1ll * (R - mid);

        IT[id].lazy = 0;
    }

    void update(int id, int L, int R, int u, int v, long long val){
        if(v < L || R < u) return;
        if(u <= L && R <= v){
            IT[id].lazy += val;
            IT[id].sum += 1ll * (R - L + 1) * val;
            return;
        }
        int mid = (L + R) >> 1;
        lazyUpdate(id, L, R, mid);
        update(id << 1, L, mid, u, v, val);
        update(id << 1 | 1, mid + 1, R, u, v, val);
        IT[id].sum = IT[id << 1].sum + IT[id << 1 | 1].sum;
    }

    void update_up_HLD(int beg, int en, long long val){
        while(1 + 1 == 2){
            if(chainInd[beg] == chainInd[en]){
                update(1, 1, N, posInBase[en], posInBase[beg], val);
                break;
            }
            else{
                update(1, 1, N, posInBase[chainHead[chainInd[beg]]], posInBase[beg], val);
                beg = Anc[chainHead[chainInd[beg]]][0];
            }
        }
    }

    long long get(int id, int L, int R, int u, int v){
        if(v < L || R < u) return 0;
        if(u <= L && R <= v) return IT[id].sum;
        int mid = (L + R) >> 1;
        lazyUpdate(id, L, R, mid);
        long long t1 = get(id << 1, L, mid, u, v);
        long long t2 = get(id << 1 | 1, mid + 1, R, u, v);
        return t1 + t2;
    }

    long long query_up_HLD(int beg, int en){
        assert(depth[beg] >= depth[en]);
        long long res = 0;
        while(1 + 1 == 2){
            if(chainInd[beg] == chainInd[en]){
                res = res + get(1, 1, N, posInBase[en], posInBase[beg]);
                return res;
            }
            else{
                res = res + get(1, 1, N, posInBase[chainHead[chainInd[beg]]], posInBase[beg]);
                beg = Anc[chainHead[chainInd[beg]]][0];
            }
        }
        return res;
    }


};
