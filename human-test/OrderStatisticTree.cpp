#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

// Định nghĩa Order Statistic Tree
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    Tree<int> t;

    // Thêm phần tử vào cây
    t.insert(3);
    t.insert(1);
    t.insert(4);
    t.insert(2);
    t.insert(5);

    cout << "Initial elements in tree: ";
    for (auto x : t) cout << x << " "; // Output: 1 2 3 4 5
    cout << endl;

    // Truy vấn vị trí phần tử
    cout << "Index of 3: " << t.order_of_key(3) << endl; // Output: 2
    cout << "Index of 6 (not present): " << t.order_of_key(6) << endl; // Output: 5

    // Truy vấn phần tử theo chỉ số
    cout << "Element at index 0: " << *t.find_by_order(0) << endl; // Output: 1
    cout << "Element at index 4: " << *t.find_by_order(4) << endl; // Output: 5

    // Tìm giá trị gần nhất (lower_bound và upper_bound)
    cout << "Lower bound of 3: " << *t.lower_bound(3) << endl; // Output: 3
    cout << "Upper bound of 3: " << *t.upper_bound(3) << endl; // Output: 4
    cout << "Lower bound of 6 (not present): ";
    if (t.lower_bound(6) == t.end()) cout << "None" << endl; // Output: None
    else cout << *t.lower_bound(6) << endl;

    // Xóa phần tử
    t.erase(3);
    cout << "Elements after erasing 3: ";
    for (auto x : t) cout << x << " "; // Output: 1 2 4 5
    cout << endl;

    // Kiểm tra phần tử có tồn tại không
    cout << "Contains 4? " << (t.find(4) != t.end() ? "Yes" : "No") << endl; // Output: Yes
    cout << "Contains 3? " << (t.find(3) != t.end() ? "Yes" : "No") << endl; // Output: No
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // Số lượng testcase
    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
