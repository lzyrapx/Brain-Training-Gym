#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

const int mod = 998244353;
 
struct E {
    int u, v;
};
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
 
    vector<map<ll, int>> dp(n + 1);
    vector<E> es;
    ll ans = m; 
 
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        dp[v][a[u]]++;
        if(a[v] > a[u]) es.push_back({u, v});
    }
 
    sort(es.begin(), es.end(), [&](const E& x, const E& y) {
        return a[x.v] < a[y.v];
    });
 
    for(auto& e : es) {
        ll cnt = a[e.v] - a[e.u];
        if(dp[e.u].count(cnt)) {
            int c = dp[e.u][cnt];
            ans = (ans + c) % mod;
            dp[e.v][a[e.u]] = (dp[e.v][a[e.u]] + c) % mod;
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
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}