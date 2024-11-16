/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Top-down DP for maximum subarray sum.
 * Time: O(N)
 */
#pragma once

const int N = 1e5;
ll a[N], memo[N];
bool vis[N];

ll dp(int i) {
	if (i == 0) return a[0];
	if (vis[i]) return memo[i];
	vis[i] = true;
	memo[i] = max(a[i], dp(i - 1) + a[i]);
	return memo[i];
}

ll maxSubarraySum(int n) {
	memset(vis, 0, sizeof(vis));
	ll res = a[0];
	for (int i = 0; i < n; ++i)
		res = max(res, dp(i));
	return res;
}
