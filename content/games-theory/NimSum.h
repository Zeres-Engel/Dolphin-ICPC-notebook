/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

int nimber_sum(vector<int>& nimbers) {
    int res = 0;
    for (int n : nimbers) res ^= n;
    return res;
}
