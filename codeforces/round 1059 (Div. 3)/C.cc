#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    ll a, b;
    cin >> a >> b;
    // debug(a ^ b, a & b, a | b);
    // debug(a ^ 1 ^ 1 ^ 0, b);
    if (a == b) {
        cout << 0 << "\n";
        return;
    }
    int xo = a ^ b;
    if (xo <= a) {
        cout << 1 << "\n";
        cout << xo << "\n";
        return;
    }
    if (b <= a && a <= xo) {
        cout << 2 << "\n";
        cout << b << " " << a << "\n";
        debug(a ^ b ^ a, b);
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}