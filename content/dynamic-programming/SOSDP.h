/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Sum over Subsets DP (SOS DP).
 * Time: O(N * 2^N)
 */
#pragma once

const int N = 20;
ll f[1<<N];

void sos_dp() {
	rep(i,N) rep(mask,1<<N) if(mask&(1<<i))
		f[mask]+=f[mask^(1<<i)];
}
