/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Kayles game on a binary string
 * Usage: grundy(s) returns grundy number for position represented by string s
 * Time: O(N * 2^N) where N is string length
 * Status: Tested
 */
#pragma once

map<string, int> memo;
int grundy(string s) {
    if (memo.count(s)) return memo[s];
    unordered_set<int> sgs;
    rep(i,0,sz(s)) {
        if (s[i] == '1') {
            s[i] = '0';
            sgs.insert(grundy(s));
            if (i + 1 < sz(s) && s[i + 1] == '1') {
                s[i + 1] = '0';
                sgs.insert(grundy(s));
                s[i + 1] = '1';
            }
            s[i] = '1';
        }
    }
    for (int i = 0;; i++) if (!sgs.count(i)) return memo[s] = i;
}
