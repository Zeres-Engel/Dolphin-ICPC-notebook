/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right.
 * Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // max
	// static constexpr T unit = INT_MAX;
	// T f(T a, T b) { return min(a, b); } // min
	// static constexpr T unit = 0;
	// T f(T a, T b) { return a + b; } // sum
	// static constexpr T unit = 0;
	// T f(T a, T b) { return __gcd(a, b); } // GCD
	// static constexpr T unit = 1;
	// T f(T a, T b) { return (a*b)/__gcd(a, b); } // GCD
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		// condition 
		// for (s[pos += n] = (val > 0 ? 1 : 0); pos /= 2;)
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
