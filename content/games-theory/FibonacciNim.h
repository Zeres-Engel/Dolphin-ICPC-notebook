/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

bool fib_nim(int n) {
    vector<int> fib = {1, 2};
    while (fib.back() < n) fib.push_back(fib.back() + fib[fib.size() - 2]);
    return find(fib.begin(), fib.end(), n) == fib.end();
}
