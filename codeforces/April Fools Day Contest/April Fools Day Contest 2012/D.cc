#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int x;
    cin >> x;
    if(x == 1) {
        cout << 2 << "\n";
    } else if (x == 2) {
        cout << 3 << "\n";
    } else if (x == 3) {
        cout << 1 << "\n";
    } else if (x == 4) {
        cout << 2 << "\n";
    } else if (x == 5) {
        cout << 1 << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}