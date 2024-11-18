/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

int grundy(int pos) {
    if (memo[pos] != -1) return memo[pos];
    unordered_set<int> s;
    for (int move : moves[pos]) s.insert(grundy(move));
    for (int i = 0;; i++) if (!s.count(i)) return memo[pos] = i;
}
