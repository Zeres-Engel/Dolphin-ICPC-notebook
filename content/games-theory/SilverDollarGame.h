/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

int silver_dollar(vector<int>& coins) {
    int x = 0;
    for (int i = 0; i < coins.size(); i++)
        x ^= (coins[i] - i - 1);
    return x != 0;
}
