#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const string NAME="problem"; 
const int NTEST=100;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll L, ll R) {
    return L+rd()%(R-L+1);
}

int main() {
    for(int i=1;i<=NTEST;i++) {
        ofstream inp((NAME + ".inp").c_str());
        inp << input
        inp.close();
        system(("./" + NAME).c_str());
        system(("./" + NAME + "_bf").c_str());

        if (system(("diff -q " + NAME + ".out " + NAME + ".ans").c_str()) != 0) {
            cout << "Test " << i << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << i << ": CORRECT!\n";
    }
    cout << "All tests passed!\n";
}