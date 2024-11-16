/**
 * Author: [Your Name]
 * License: CC0
 * Description: Determines if target sum S can be achieved using + and -.
 * Time: O(N*T)
 */
#pragma once

const int N = 1000, T = 1e4;
int a[N];
bitset<2*T+1> dp;

bool targetSum(int n, int S) {
	const int offset = T;
	dp.reset(); dp[offset] = 1;
	for (int i = 0; i < n; ++i) {
		bitset<2*T+1> next;
		next |= dp << a[i];
		next |= dp >> a[i];
		dp = next;
	}
	return dp[S + offset];
}
