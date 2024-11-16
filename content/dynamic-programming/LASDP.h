/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Finds the length of the longest alternating sign subsequence.
 * Time: O(N)
 */
#pragma once

int longestAlternatingSubsequence(const vector<int>& a) {
	int n = sz(a), res = 1;
	vector<int> dp_pos(n, 1), dp_neg(n, 1);
	for (int i = 1; i < n; ++i) {
		if (a[i] * a[i - 1] < 0) {
			dp_pos[i] = dp_neg[i - 1] + 1;
			dp_neg[i] = dp_pos[i - 1] + 1;
		} else {
			dp_pos[i] = dp_pos[i - 1];
			dp_neg[i] = dp_neg[i - 1];
		}
		res = max({res, dp_pos[i], dp_neg[i]});
	}
	return res;
}
