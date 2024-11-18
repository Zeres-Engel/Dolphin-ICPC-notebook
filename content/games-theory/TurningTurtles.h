/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Turning Turtles game
 * A turtle can be flipped to change its direction
 * Usage: grundy(n) returns grundy number for n turtles in a row
 * Time: O(log N)
 * Status: Tested
 */
#pragma once

int grundy(int n) {
    if (n == 0) return 0;
    return n % 2 == 0 ? n / 2 : grundy(n / 2);
}
