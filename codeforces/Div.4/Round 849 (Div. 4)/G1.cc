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
    vector<ll> w(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        w[i] = a + (i + 1);
    }
    sort(w.begin(), w.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (c >= w[i]) {
            c -= w[i];
            ans++;
        } else {
            break;
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