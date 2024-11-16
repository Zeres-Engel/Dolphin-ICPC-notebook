

#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define PI acos(-1)

using ll = long long;
using db = double;

typedef complex<double> base;
typedef vector<base> vb;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int ALPHABET_SIZE = 26;
const int BASE = 31;
const int MAXN = 100000001;
const int INF = 1e9;
const int NBIT = 18;
const int N = 1<<18;
const int MOD = (int)1e9+7;

int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};

/*
------------------------------------------------------------------------------------------------------------
	
	
	
	
	
	
------------------------------------------------------------------------------------------------------------
*/
	
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

	
	void solve() {
		vector<int> arr = {1, -3, -2, 8, -7, 4};
		Tree segTree(arr.size());
		for (int i = 0; i < arr.size(); ++i) {
			segTree.update(i, arr[i]);
		}
		cout << "Count > 0 in range [0, 6): " << segTree.query(0, 6) << endl; // Output: 3
		cout << "Count > 0 in range [3, 6): " << segTree.query(3, 6) << endl; // Output: 2
	}

	int main() {
		#ifndef ONLINE_JUDGE
		freopen("INPUT.INP","r",stdin);
		freopen("OUTPUT.OUT","w",stdout);
		#endif
		ios_base::sync_with_stdio(false);
		cin.tie(0); cout.tie(0);
		int test = 1;
		cin >> test;
		while (test--) {
			solve();
		}
	}

