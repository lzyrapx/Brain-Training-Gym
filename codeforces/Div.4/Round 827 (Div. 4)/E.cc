#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), pref_sum(n + 1, 0), pref_max(n);
    ll maxh = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref_sum[i + 1] = pref_sum[i] + a[i];
        maxh = max(maxh, a[i]);
        pref_max[i] = maxh;
    }
    for (int i = 1; i <= q; i++) {
        ll k;
        cin >> k;
        // first pref_max[i] > k
        auto it = upper_bound(pref_max.begin(), pref_max.end(), k);
        int idx = it - pref_max.begin();
        // debug(idx);
        cout << pref_sum[idx] << " ";
    }
    cout << "\n";
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