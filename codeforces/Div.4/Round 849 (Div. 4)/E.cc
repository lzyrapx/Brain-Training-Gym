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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // dp[i][0]: 位置 i 不变，i + 1 不变
    // dp[i][1]: 位置 i 变，i + 1 变
    vector<vector<ll>>dp(n + 1, vector<ll>(2, 0));
    dp[0][0] = a[0];
    dp[0][1] = -a[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1] - a[i]);
        dp[i][1] = max(dp[i - 1][0] - a[i], dp[i - 1][1] + a[i]);
    }
    cout << dp[n - 1][0] << "\n";  // 最后一个元素后面没有元素可以翻转
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