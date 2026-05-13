#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    set<int> s;
    auto dfs1 = [&](auto& self, int u, int fa, int x) {
        if (u == b) return;  // 提前判断直接到达 b 了
        s.insert(x);
        for (auto& v: g[u]) {
            if (v.first == fa) continue;
            self(self, v.first, u, x ^ v.second);
        }
    };
    dfs1(dfs1, a, -1, 0);

    bool ok = false;
    auto dfs2 = [&](auto& self, int u, int fa, int x) {
        if (s.count(x)) {
            ok = true;
            return;
        }
        for (auto& v: g[u]) {
            if (v.first == fa) continue;
            self(self, v.first, u, x ^ v.second);
            if (ok) return;
        }
    };
    for (auto& v: g[b]) {
        dfs2(dfs2, v.first, b, v.second);
        if (ok) break;
    }
    if (ok) cout << "yes" << "\n";
    else cout << "no" << "\n";
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