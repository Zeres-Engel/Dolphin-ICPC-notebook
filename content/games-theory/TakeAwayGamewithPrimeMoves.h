/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Take Away game with prime moves
 * Can only take prime number of stones
 * Usage: grundy(n) returns grundy number for n stones
 * Time: O(N * sqrt(N))
 * Status: Tested
 */
#pragma once

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int grundy(int n) {
    if (n == 0) return 0;
    unordered_set<int> s;
    for (int i = 2; i <= n; i++)
        if (is_prime(i)) s.insert(grundy(n - i));
    rep(i,0,INT_MAX) if (!s.count(i)) return i;
    return 0;
}
