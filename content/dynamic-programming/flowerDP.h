/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Top-down DP for flower arrangement.
 * Time: O(N*K)
 */
#pragma once

const int N = 1e3, K = 1e3, INF = 1e9;
int A[K+1][N+1];
int memo[K+1][N+1];
bool vis[K+1][N+1];

int dp(int i, int j) {
	if (i == 0) return 0;
	if (j < i) return -INF;
	if (vis[i][j]) return memo[i][j];
	vis[i][j] = true;
	return memo[i][j] = max(dp(i, j - 1), dp(i - 1, j - 1) + A[i][j]);
}

int maxAesthetic(int n, int k) {
	memset(vis, 0, sizeof(vis));
	return dp(k, n);
}
