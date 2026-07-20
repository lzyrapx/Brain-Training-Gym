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
    ll c;
    cin >> n >> c;
    vector<ll> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    ll low = 1, high = 1e9;
    ll ans = 1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll sum = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            ll b = s[i] + 2 * mid;
            sum += b * b;
            if (sum > c) {
                ok = false; break;
            }
        }
        if (ok && sum <= c) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
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
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}