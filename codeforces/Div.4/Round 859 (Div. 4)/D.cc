#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    while(q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        ll ans = pref[n] - (pref[r] - pref[l - 1]) + k * (r - l + 1);
        if (ans & 1) cout << "yes" << "\n";
        else cout << "no" << "\n"; 
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
    cin >> t;
    while (t--) solve();
    return 0;
}