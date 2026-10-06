#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    // dist[b][v] 表示骑着在城市 b 买的车，到达当前城市 u 所需要的最短时间
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 1e18));
    
    using ppii = pair<ll, pair<ll, ll>>;
    priority_queue<ppii, vector<ppii>, greater<ppii>> pq;
    dist[0][0] = 0;
    // {w, {u, b}}
    pq.push({0, {0, 0}});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        ll d = cur.first;
        ll u = cur.second.first, b = cur.second.second;
        if (d > dist[b][u]) continue;

        // 在当前城市换车
        if (s[u] < s[b]) {
            if (dist[u][u] > d) {
                dist[u][u] = d;
                pq.push({d, {u, u}});
            }
        }

        // 骑当前的车前往相邻城市
        for (auto edge : adj[u]) {
            ll v = edge.first;
            ll w = edge.second;
            
            // 骑车 b 通过长度为 w 的道路到达城市 v，时间增加 w * s[b]
            if (dist[b][v] > d + w * s[b]) {
                dist[b][v] = d + w * s[b];
                pq.push({dist[b][v], {v, b}});
            }
        }
    }

    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dist[i][n - 1]);
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