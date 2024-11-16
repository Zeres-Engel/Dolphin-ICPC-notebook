/**
 * Author: Simon Lindholm
 * Date: 2016-10-08
 * License: CC0
 * Source: me
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things.
 * Use with a bump allocator for better performance, and SmallPtr or implicit indices to save memory.
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, sz(v));
 * Status: stress-tested a bit
 */
#pragma once

#include "../various/BumpAllocator.h"

const int inf = 1e9; // Change to 0 for sum or INT_MAX for min
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf; // Change val to match the problem
	Node(int lo, int hi): lo(lo), hi(hi) {} // Default value for a large interval
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo) / 2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val); // Combine function (change to + for sum or min queries)
		} else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf; // Default return value (change to 0 for sum or inf for min)
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R)); // Combine function
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val); // Combine function
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x; // Modify logic for add if necessary
		} else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val); // Combine function
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo) / 2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
		else if (madd)
			l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
	}
};

