/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Basic Nim game functions.
 * Winning state is when XOR sum of pile sizes is non-zero.
 * Usage: winning_position(piles) returns if current position is winning
 * Time: O(N) where N is number of piles
 * Status: Tested
 */
#pragma once

bool winning_position(const vector<int>& piles) {
    int xor_sum = 0;
    for (int pile : piles) xor_sum ^= pile;
    return xor_sum != 0;
}

int find_winning_move(const vector<int>& piles) {
    int xor_sum = 0;
    for (int pile : piles) xor_sum ^= pile;
    if (xor_sum == 0) return -1;
    rep(i,0,sz(piles)) if ((piles[i] ^ xor_sum) < piles[i])
        return i;
    return -1;
}
