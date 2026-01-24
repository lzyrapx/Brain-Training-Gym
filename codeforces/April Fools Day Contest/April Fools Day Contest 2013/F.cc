#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>degree(30);
    vector<int> g[30];
    vector<vector<bool>> is_edge(30, vector<bool>(30, false));
    vector<bool> vis(30);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        // 排除自环和重边
        if (u == v) continue;
        if (is_edge[u][v]) continue;

        // 无向边
        g[u].push_back(v);
        g[v].push_back(u);
        is_edge[u][v] = is_edge[v][u] = true;
        degree[u]++;
        degree[v]++;
    }
    auto compare = [&degree](int u, int v) {
        if (degree[u] != degree[v]) {
            return degree[u] < degree[v];
        }
        return u < v;
    };
    
    // 对每个节点的邻接表按指定规则排序
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end(), compare);
    }
    
    // DFS 遍历，总是选择第一个未访问的相邻节点
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v);
                return; // 只访问一个相邻节点
            }
        }
    };
    
    // 检查是否所有节点都被访问
    auto check = [&]() {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += vis[i];
        }
        return count == n;
    };
    
    // 尝试从每个节点开始 DFS，判断是否存在哈密顿路径
    bool found = false;
    for (int i = 0; i < n; ++i) {
        vis.assign(30, false);
        dfs(i);
        if (check()) {
            cout << "Yes\n";
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "No\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}