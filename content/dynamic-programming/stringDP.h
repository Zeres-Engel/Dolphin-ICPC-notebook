/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Computes edit distance between A and B.
 * Time: O(M*N)
 */
#pragma once

const int N = 1e3;
char A[N], B[N];

int editDistance(int m, int n) {
	vector<vector<int>> dp(m+1, vector<int>(n+1));
	rep(i, m+1) dp[i][0] = i;
	rep(j, n+1) dp[0][j] = j;
	rep(i,1,m+1) rep(j,1,n+1) {
		if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
		else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
	}
	return dp[m][n];
}
