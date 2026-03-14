#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool pre = a[1] % 2 ? true : false;
    for (int i = 3; i < n; i += 2) {
        bool cur = a[i] % 2 ? true : false;
        if (cur != pre) {
            cout << "NO\n"; return;
        }
    }
    pre = a[0] % 2 ? true : false;
    for (int i = 2; i < n; i += 2) {
        bool cur = a[i] % 2 ? true : false;
        if (cur != pre) {
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}