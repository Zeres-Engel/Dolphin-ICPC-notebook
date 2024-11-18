/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Chomp game on a rectangle
 * Usage: grundy(a,b) returns grundy number for axb chocolate bar
 * Time: O(A*B) with memoization
 * Status: Tested
 */
#pragma once

map<pair<int, int>, int> memo;
int grundy(int a, int b) {
    if (a == 0 || b == 0) return 0;
    if (memo.count({a, b})) return memo[{a, b}];
    unordered_set<int> s;
    rep(i,1,a+1) rep(j,1,b+1)
        s.insert(grundy(i - 1, j - 1));
    rep(i,0,INT_MAX) if (!s.count(i)) 
        return memo[{a, b}] = i;
    return 0;
}
