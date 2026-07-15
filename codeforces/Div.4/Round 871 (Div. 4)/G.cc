#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

vector<ll> ans;
void init() {
    ans.reserve(2000 * 2000 + 1);
    // dp[i][j]: 第 i 行第 j 列的被打中时，上方拿到的数值和
    // dp[i][j] = k * k + dp[i - 1][j] + dp[i - 1][j - 1] - dp[i - 2][j - 1]
    vector<vector<ll>> dp(2000, vector<ll>(2000, 0));    
    int k = 1 * 1;
    int n = 2000;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (k > 1e6) break;
            dp[i][j] = (ll)k * k;
            if (i > j) dp[i][j] += dp[i - 1][j];
            if (j > 1) dp[i][j] += dp[i - 1][j - 1];
            if (j > 1 && i > j) dp[i][j] -= dp[i - 2][j - 1];
            ans[k] = dp[i][j];
            k++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << ans[n] << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    init();
    cin >> t;
    while(t--) solve();
    return 0;
}