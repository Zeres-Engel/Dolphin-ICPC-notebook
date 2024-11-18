/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for subtraction games
 * Usage: grundy(n, S) returns grundy number for position n with subtraction set S
 * Time: O(N * |S|)
 * Status: Tested
 */
#pragma once

int grundy(int n, vector<int>& S) {
    if (n == 0) return 0;
    unordered_set<int> s;
    for (int x : S)
        if (n >= x) s.insert(grundy(n - x, S));
    for (int i = 0;; i++)
        if (!s.count(i)) return i;
}
