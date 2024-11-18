/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

int nim_modulo(vector<int>& heaps, int m) {
    int x = 0;
    for (int h : heaps) x ^= h % m;
    return x != 0;
}
