#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

ll power(ll x, int n, int p) {
    x %= p;
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * x) % p;
        x = (x * x) % p;
        n >>= 1;
    }
    return res;
}


void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    if (k == 0) {
        cout << (*min_element(a.begin() + 1, a.begin() + n + 1) == 0 ? n - 1 : 0) << '\n';
        return;
    }
    
    map<int, int> mp;
    ll ans = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) continue;
        
        int x = power(a[i], 3, p);
        int inv = power(x, p - 2, p);
        ans += mp[(k * (ll)inv) % p];
        ++mp[x];
    }
    
    cout << ans << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}