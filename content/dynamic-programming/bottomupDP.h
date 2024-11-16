/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Finds the maximum subarray sum in an array.
 * Time: O(N)
 */
#pragma once

ll maxSubarraySum(const vector<ll>& a) {
	ll maxSum = a[0], curSum = 0;
	for (ll x : a) {
		curSum = max(x, curSum + x);
		maxSum = max(maxSum, curSum);
	}
	return maxSum;
}
