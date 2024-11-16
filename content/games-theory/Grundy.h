/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Computes Grundy numbers for game positions.
 * Time Complexity: O(N + M), where N is the number of positions and M is the number of moves.
 */

#pragma once
typedef pair<int, int> pii;

struct GrundyCalculator {
    int N, M;
    vector<vector<int>> moves;
    vector<int> grundy;
    GrundyCalculator(int n, int m) : N(n), M(m), moves(n+1, vector<int>()), grundy(n+1, 0) {}
    void add_move(int a, int b) {
        moves[a].push_back(b);
    }
    int mex(const vector<int> &s){
        vector<bool> present(s.size()+1, false);
        for(auto x : s) if(x < present.size()) present[x] = true;
        for(int i = 0; i < present.size(); i++) if(!present[i]) return i;
        return present.size();
    }
    void compute_grundy() {
        for(int i = 0; i <= N; i++){
            vector<int> next;
            for(auto &b : moves[i]) next.push_back(grundy[b]);
            grundy[i] = mex(next);
        }
    }
};