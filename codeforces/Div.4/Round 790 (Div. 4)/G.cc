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
    vector<int> a(n + 1);
    for (int i = 2; i <= n; i++) cin >> a[i];
    string s;
    cin >> s;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'B') {
            dp[i] = 1;
        } else {
            dp[i] = -1;
        }
    }
    for (int i = n; i >= 2; --i) dp[a[i]] += dp[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 0) ans++;
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