/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

bool moore_nim(vector<int>& heaps) {
    map<int, int> m;
    for (int h : heaps) m[h]++;
    return m.size() != 1;
}
