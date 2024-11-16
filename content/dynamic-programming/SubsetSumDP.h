/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Checks if a subset sum equals S.
 * Time: O(N*S)
 */
#pragma once

const int N = 1000, S = 1e5;
int a[N];
bitset<S+1> dp;

bool subsetSum(int n, int sum) {
	dp.reset(); dp[0] = 1;
	for (int i = 0; i < n; ++i)
		dp |= dp << a[i];
	return dp[sum];
}
