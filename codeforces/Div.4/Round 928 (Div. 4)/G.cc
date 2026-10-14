#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

/*
树形 dp
树上最小割
*/
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    string s;
    cin >> s;
    // dp[u][0]：表示在 u 的子树中，将所有 P 和 S 隔离开，且节点 u 与 P 连通时所需的最少割边数
    // dp[u][1]：表示在 u 的子树中，将所有 P 和 S 隔离开，且节点 u 与 S 连通时所需的最少割边数
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    ll inf = 1e18;  // 不能连通
    auto dfs = [&](auto& self, int cur, int rt) -> void {
        ll sum0 = 0, sum1 = 0;
        for (auto v : adj[cur]) {
            if (v == rt) continue;
            self(self, v, cur);
            sum0 += min(dp[v][0], dp[v][1] + 1);  // min(v 和 P 连通， v 和 S 隔开)
            sum1 += min(dp[v][1], dp[v][0] + 1);  // min(v 和 S 连通， v 和 P 隔开)
        }
        if (s[cur - 1] == 'P') {
            dp[cur][0] = sum0;
            dp[cur][1] = inf;
        } else if (s[cur - 1] == 'S') {
            dp[cur][0] = inf;
            dp[cur][1] = sum1;
        } else {
            dp[cur][0] = sum0;
            dp[cur][1] = sum1;
        }
    };
    dfs(dfs, 1, 0);
    cout << min(dp[1][0], dp[1][1]) << "\n";
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