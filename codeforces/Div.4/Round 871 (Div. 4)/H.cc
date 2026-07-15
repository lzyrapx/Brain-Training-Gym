#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    
    // dp[mask] 表示在当前已经处理过的数字中，有多少个非空子序列，它们的 & 结果正好是 mask
    vector<int> dp(64, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vector<int> nxt = dp;  // 不选 x
        for (int mask = 0; mask < 64; mask++) {  // 选 x
            nxt[mask & x] = (nxt[mask & x] + dp[mask]) % mod;
        }
        nxt[x] = (nxt[x] + 1) % mod;  // 只有 x (序列长度=1)
        dp = move(nxt);
    }
    ll ans = 0;
    for (int mask = 0; mask < 64; mask++) {
        if (__builtin_popcount(mask) == k) {
            ans = (ans + dp[mask]) % mod;
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