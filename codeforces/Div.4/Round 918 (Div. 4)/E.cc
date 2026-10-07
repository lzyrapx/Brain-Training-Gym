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
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (i % 2 == 0) pref[i + 1] = pref[i] + x;
        else pref[i + 1] = pref[i] - x;
    }
    sort(pref.begin(), pref.end());
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (pref[i + 1] - pref[i] == 0) {
            ok = true; break;
        }
    }
    if (ok) cout << "yes" << "\n";
    else cout << "no" << "\n";
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