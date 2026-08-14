#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

/*
基环树
1. 拓扑排序找环
2. 计算最短距离
3. 判定
*/
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> g(n + 1);
    vector<int> in_degree(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        in_degree[u]++;
        in_degree[v]++;
    }
    if (a == b) {
        cout << "no" << "\n";
        return;
    }
    vector<bool> cycle_node(n + 1, true);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 1) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cycle_node[u] = false;
        for (auto v : g[u]) {
            in_degree[v]--;
            if (in_degree[v] == 1) q.push(v);
        }
    }
    auto get_dis = [&] (int start) {
        vector<int> dis(n + 1, -1);
        queue<int> bq;
        dis[start] = 0;
        bq.push(start);
        while (!bq.empty()) {
            int u = bq.front(); bq.pop();
            for (auto v: g[u]) {
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    bq.push(v);
                }
            }
        }
        return dis;
    };
    vector<int> dm = get_dis(a);
    vector<int> dv = get_dis(b);
    bool win = false;
    for (int i = 1; i <= n; i++) {
        if (cycle_node[i] && dv[i] < dm[i]) {
            win = true;
            break;
        }
    }
    if (win) cout << "yes" << "\n";
    else cout << "no" << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}