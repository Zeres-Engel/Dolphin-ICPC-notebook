/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: TSP using DP with bitmasking.
 * Time: O(N^2 * 2^N)
 */
#pragma once

const int N = 20, INF = 1e9;
int n, d[N][N], dp[1<<N][N];

void tsp() {
	rep(m,1<<n) rep(u,n) dp[m][u]=INF;
	dp[1][0]=0;
	rep(m,1<<n) rep(u,n) if(m&(1<<u))
		rep(v,n) if(!(m&(1<<v)))
			dp[m|(1<<v)][v]=min(dp[m|(1<<v)][v],dp[m][u]+d[u][v]);
}

ll dp[1<<N];
void bitmask_dp() {
	int n; dp[0]=base_case;
	rep(mask,1<<n) {
		// process dp[mask]
		rep(i,n) if(!(mask&(1<<i)))
			dp[mask|(1<<i)]=update(dp[mask|(1<<i)], dp[mask], i);
	}
}