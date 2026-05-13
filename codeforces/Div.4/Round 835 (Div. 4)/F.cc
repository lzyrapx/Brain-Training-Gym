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
    ll c, d;
    cin >> n >> c >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> prefsum(n + 1, 0);
    for (int i = 0; i < n; i++) prefsum[i + 1] = prefsum[i] + a[i];

    if (prefsum[min((ll)n, d)] >= c) {
        cout << "Infinity" << "\n";
        return;
    }
    
    if (a[0] * d < c) {
        cout << "Impossible" << "\n";
        return;
    }

    auto check = [&](ll k) {
        ll m = k + 1;
        ll full = d / m;
        ll rem = d % m;
        ll total = 0;
        total += full * prefsum[min((ll)n, m)];
        total += prefsum[min((ll)n, rem)];
        return total >= c;
    };

    ll l = 0, r = d, ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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