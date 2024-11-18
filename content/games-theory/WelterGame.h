/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

int grundy(int u) {
    if (grundy[u] != -1) return grundy[u];
    unordered_set<int> s;
    for (int v : adj[u]) s.insert(grundy(v));
    for (int i = 0;; i++)
        if (!s.count(i)) return grundy[u] = i;
}
