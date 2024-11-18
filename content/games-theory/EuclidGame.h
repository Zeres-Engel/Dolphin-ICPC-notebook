/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Cram game on wxh board
 * Usage: grundy(w,h) returns grundy number for board of width w and height h
 * Time: O(1)
 * Status: Tested
 */
#pragma once

bool euclid(int a, int b) {
    if (a < b) swap(a, b);
    return a % b ? !euclid(b, a % b) : true;
}
