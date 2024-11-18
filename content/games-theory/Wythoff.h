/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Implementation of Sprague-Grundy theorem.
 * Converts an impartial game to Nim game.
 * Usage: sprague_grundy(pos) returns grundy number of position
 * Time: O(N * M) where M is number of possible moves
 * Status: Tested
 */
#pragma once

int sprague_grundy(int pos) {
    if (memo[pos] != -1) return memo[pos];
    vector<bool> seen(MAX_VAL);
    for (int next_pos : get_next_positions(pos))
        seen[sprague_grundy(next_pos)] = true;
    int mex = 0;
    while (seen[mex]) mex++;
    return memo[pos] = mex;
}
