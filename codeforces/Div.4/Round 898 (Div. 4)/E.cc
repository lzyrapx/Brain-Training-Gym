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
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll l = 1, r = 2e9;
    ll ans = 1;
    while (l <= r) {
        ll h = l + (r - l) / 2;
        ll w = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < h) {
                w += (h - a[i]);
            }
        }
        if (w <= x) {
            ans = h;
            l = h + 1;
        } else {
            r = h - 1;
        }
    }
    cout << ans << "\n";
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