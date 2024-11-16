/**
 * Author: Simon Lindholm
 * Date: 2017-05-11
 * License: CC0
 * Source: folklore
 * Description: Computes sums a[i,j,k] for all i<I, j<J, k<K, and increases single elements a[i,j,k].
 *  Requires that the elements to be updated are known in advance (call fakeUpdate() before init()).
 * Time: O((log N)^3). (Use persistent segment trees for O((log N)^2).)
 * Status: stress-tested
 */
#pragma once

#include "FenwickTree.h"

struct FT3 {
    vector<vector<vi>> ys;
    vector<vector<FT>> ft;
    FT3(int limx, int limy) : ys(limx, vector<vi>(limy, vi())) {}
    void fakeUpdate(int x, int y, int z) {
        for (; x < (int)ys.size(); x |= x + 1) {
            for (int yy = y; yy < (int)ys[x].size(); yy |= yy + 1) {
                ys[x][yy].push_back(z);
            }
        }
    }
    void init() {
        for(int x = 0; x < (int)ys.size(); x++) {
            for(int y = 0; y < (int)ys[x].size(); y++) {
                sort(ys[x][y].begin(), ys[x][y].end());
                ys[x][y].erase(unique(ys[x][y].begin(), ys[x][y].end()), ys[x][y].end());
                ft.emplace_back();
                ft[x].emplace_back(ys[x][y].size());
            }
        }
    }
    int ind(int x, int y, int z) {
        return (int)(lower_bound(ys[x][y].begin(), ys[x][y].end(), z) - ys[x][y].begin());
    }
    void update(int x, int y, int z, ll dif) {
        for (; x < (int)ys.size(); x |= x + 1) {
            for(int yy = y; yy < (int)ys[x].size(); yy |= yy + 1) {
                int idx = ind(x, yy, z);
                if(idx < (int)ft[x][yy].size()) {
                    ft[x][yy].update(idx, dif);
                }
            }
        }
    }
    ll query(int x, int y, int z) const {
        ll sum = 0;
        for(; x > 0; x -= x & -x) {
            for(int yy = y; yy > 0; yy -= yy & -yy) {
                int idx = upper_bound(ys[x-1][yy-1].begin(), ys[x-1][yy-1].end(), z) - ys[x-1][yy-1].begin();
                if(idx > 0) {
                    sum += ft[x-1][yy-1].query(idx - 1);
                }
            }
        }
        return sum;
    }
    ll queryRegion(int x1, int y1, int z1, int x2, int y2, int z2) const {
        return query(x2, y2, z2)
             - query(x1, y2, z2)
             - query(x2, y1, z2)
             - query(x2, y2, z1)
             + query(x1, y1, z2)
             + query(x1, y2, z1)
             + query(x2, y1, z1)
             - query(x1, y1, z1);
    }
};
