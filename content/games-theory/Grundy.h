/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Calculates Grundy numbers for impartial games.
 * Usage: GrundyCalculator gc(n, m);
 *        gc.add_move(a, b); // Add move from position a to b
 *        gc.compute_grundy(); // Calculate all Grundy numbers
 * Time: O(N + M)
 * Status: Tested
 */
#pragma once

struct GrundyCalculator {
    int N, M;
    vector<vector<int>> moves;
    vector<int> grundy;
    
    GrundyCalculator(int n, int m) : N(n), M(m), 
        moves(n+1), grundy(n+1) {}
    
    void add_move(int a, int b) { moves[a].push_back(b); }
    
    int mex(const vector<int> &s) {
        vector<bool> present(s.size() + 1);
        for(int x : s) if(x < sz(present)) present[x] = true;
        rep(i,0,sz(present)) if(!present[i]) return i;
        return sz(present);
    }
    
    void compute_grundy() {
        rep(i,0,N+1) {
            vector<int> next;
            for(int b : moves[i]) next.push_back(grundy[b]);
            grundy[i] = mex(next);
        }
    }
};