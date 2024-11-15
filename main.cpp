#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = double;

#define PI acos(-1)

typedef complex<double> base;
typedef vector<base> vb;

const int ALPHABET_SIZE = 26;
const int BASE = 31;
const int MAXN = 100000001;
const int INF = 1e9;
const int NBIT = 18;
const int N = 1<<18;
const int MOD = (int)1e9+7;

int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};

// Khai báo kiểu cây phân vị
template<class T>
using OrderStatisticTree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    // Khởi tạo cây phân vị
    OrderStatisticTree<int> ost;

    // Chèn các phần tử vào cây
    ost.insert(5);
    ost.insert(10);
    ost.insert(15);
    ost.insert(20);
    ost.insert(25);

    // Lấy phần tử ở vị trí thứ 2 (index 2)
    cout << "Phần tử ở vị trí thứ 2: " << *ost.find_by_order(2) << endl;

    // Lấy vị trí (index) của phần tử 15 trong cây
    cout << "Vị trí của phần tử 15: " << ost.order_of_key(15) << endl;

    // Nếu phần tử không có trong cây, nó sẽ trả về vị trí ảo
    cout << "Vị trí của phần tử 17 (không tồn tại): " << ost.order_of_key(17) << endl;

    // Kiểm tra số phần tử nhỏ hơn 20
    cout << "Số phần tử nhỏ hơn 20: " << ost.order_of_key(20) << endl;
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

    return 0;
}
