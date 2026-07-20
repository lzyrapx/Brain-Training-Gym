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
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll d;
        cin >> u >> v >> d;
        adj[v].push_back({u, d});
        adj[u].push_back({v, -d});
    }
    vector<ll> pos(n + 1, 0);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        pos[i] = 0;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (auto e: adj[cur]) {
                int v = e.first;
                ll d = e.second;
                if (!vis[v]) {
                    vis[v] = true;
                    pos[v] = pos[cur] + d;
                    q.push(v);
                } else {
                    if (pos[v] != pos[cur] + d) {
                        cout << "NO" << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "YES" << "\n";
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