/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Minimizes difference between two subsets.
 * Time: O(N*T)
 */
#pragma once

const int N = 1000, T = 1e5;
int a[N];
bitset<T+1> dp;

int minDifference(int n) {
	int total = accumulate(a, a + n, 0);
	dp.reset(); dp[0] = 1;
	for (int i = 0; i < n; ++i)
		dp |= dp << a[i];
	int half = total / 2;
	for (int s = half; s >= 0; --s)
		if (dp[s]) return total - 2 * s;
	return total;
}
