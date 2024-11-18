/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Computes the maximum possible rating after skipping an optimal interval.
 * Time: O(N) per test case
 */

#pragma once

void newRating() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), s(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int x = 0, x_total = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > x) { s[i] = 1; x += 1; }
			else if (a[i] == x) { s[i] = 0; }
			else { s[i] = -1; x -= 1; }
		}
		x_total = x;

		int min_sum = INT_MAX, curr_sum = 0;
		for (int i = 0; i < n; ++i) {
			curr_sum += s[i];
			if (curr_sum > 0) curr_sum = s[i];
			min_sum = min(min_sum, curr_sum);
		}
		if (min_sum == INT_MAX) min_sum = *min_element(s.begin(), s.end());
		int max_rating = x_total - min_sum;
		cout << max_rating << '\n';
	}
}
