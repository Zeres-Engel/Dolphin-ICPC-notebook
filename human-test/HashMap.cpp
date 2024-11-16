#include <bits/extc++.h>
#include <bits/stdc++.h>
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
	
// To use most bits rather than just the lowest ones:
struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
__gnu_pbds::gp_hash_table<ll,int,chash> h({},{},{},{},{1<<16});
	
void solve() {
    __gnu_pbds::gp_hash_table<int, int, chash> freq; // Khai báo hash map: key là số, value là tần suất

    // Thêm các phần tử vào hash map
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4};
    for (int x : nums) {
        freq[x]++;
    }

    // In tần suất của từng phần tử
    cout << "Frequency of elements:" << endl;
    for (auto &entry : freq) {
        cout << "Element " << entry.first << ": " << entry.second << " times" << endl;
    }

    // Truy vấn một phần tử cụ thể
    int query = 3;
    if (freq.find(query) != freq.end()) {
        cout << "Element " << query << " appears " << freq[query] << " times" << endl;
    } else {
        cout << "Element " << query << " is not found" << endl;
    }
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