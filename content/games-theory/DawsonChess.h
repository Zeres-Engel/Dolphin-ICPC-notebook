/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

int grundy(string s) {
    if (memo.count(s)) return memo[s];
    unordered_set<int> sgs;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            string t = s;
            t[i] = '0';
            if (i > 0) t[i - 1] = '0';
            if (i + 1 < s.size()) t[i + 1] = '0';
            sgs.insert(grundy(t));
        }
    }
    for (int i = 0;; i++)
        if (!sgs.count(i)) return memo[s] = i;
}
