/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

int grundy(int n) {
    if (n == 0) return 0;
    unordered_set<int> s;
    for (int i = 4; i <= n; i++)
        if (!is_prime(i)) s.insert(grundy(n - i));
    for (int i = 0;; i++)
        if (!s.count(i)) return i;
}
