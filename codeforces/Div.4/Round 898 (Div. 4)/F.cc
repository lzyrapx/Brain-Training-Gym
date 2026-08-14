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
    ll k;
    cin >> n >> k;
    vector<ll> a(n), h(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    int ans = 0;
    int l = 0;
    ll cur = 0;
    for (int r = 0; r < n; r++) {
        if (r >= 1 && h[r - 1] % h[r] != 0) {
            l = r;
            cur = 0;
        }
        cur += a[r];
        while (l <= r && cur > k) {
            cur -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
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