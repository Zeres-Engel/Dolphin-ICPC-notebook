/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

bool lasker_nim(vector<int>& heaps) {
    int x = 0;
    for (int h : heaps) x ^= h % 3;
    return x != 0;
}
