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
    if (n < 4) {
        cout << -1 << "\n"; return;
    }
    for (int i = n; i >= 1; --i) {
        if (i % 2 == 1) cout << i << " ";
    }
    cout << 4 << " " << 2 << " ";
    for (int i = 6; i <= n; i++) {
        if (i % 2 == 0) cout << i << " ";
    }
    cout << "\n";
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