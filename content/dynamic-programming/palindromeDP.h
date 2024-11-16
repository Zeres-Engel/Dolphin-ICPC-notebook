/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: DP for counting palindromic substrings.
 * Time: O(N^2)
 */
#pragma once

const int N = 5000;
char s[N];
bool p[N][N];

void pal_dp() {
	int n=strlen(s);
	repd(i,n) rep(j,i,n) {
		p[i][j]=(s[i]==s[j])&&(j-i<2||p[i+1][j-1]);
	}
}
