/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Minimum coins to make amount S.
 * Time: O(N*S)
 */
#pragma once

const int N = 100, S = 1e5, INF = 1e9;
int coins[N];

int coinChange(int n, int amount) {
	vector<int> dp(amount+1, INF);
	dp[0] = 0;
	for (int i = 0; i < n; ++i)
		for (int s = coins[i]; s <= amount; ++s)
			dp[s] = min(dp[s], dp[s - coins[i]] + 1);
	return dp[amount] == INF ? -1 : dp[amount];
}
