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
    vector<int> p(n);
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--; // 转换为 0 ~ n-1
    }

    // 根节点必须是最大值 n-1
    if (p[0] != n - 1) {
        cout << "No\n";
        return;
    }

    // 记录每个值在 P 中的位置
    vector<int> pos(n);
    for(int i = 0; i < n; ++i) pos[p[i]] = i;

    vector<vector<int>> adj(n);
    vector<int> dep(n, 0);

    // l, r: 当前子树在 P 中的下标范围 [l, r)
    // mn, mx: 当前层级子节点允许的值域范围 [mn, mx]
    auto dfs = [&](auto&& self, int l, int r, int mn, int mx) -> bool {
        // 叶子节点，直接成功
        if (l + 1 == r) return true;
        // 第一个子节点的值必须在允许范围内
        if (p[l+1] < mn || p[l+1] > mx) return false;

        int start_val = p[l+1];
        int cur_limit = start_val - 1; // 用于传递给下一层的最大值约束

        // 遍历所有子节点，子节点的值从 start_val 到 mx 依次递增
        for (int v = start_val; v <= mx; ++v) {
            int u = pos[v]; // 子节点在 P 中的下标
            adj[l].push_back(u); // 建立父子边
            dep[u] = dep[l] + 1;

            // 子节点必须位于父节点之后，且在当前子树范围内
            if (u < l || u >= r) return false;

            int nr; // 当前子节点的子树结束位置
            if (v == mx) {
                nr = r;
            } else {
                int next_u = pos[v+1]; // 下一个兄弟节点的位置
                // 兄弟节点必须出现在当前节点之后
                if (next_u < u) return false;
                nr = next_u;
            }

            int sz = nr - u; // 当前子节点的子树大小
            
            // 递归处理子节点
            // 子树内部可用的值域被压缩在 [cur_limit - sz + 2, cur_limit]
            if (!self(self, u, nr, cur_limit - sz + 2, cur_limit)) return false;
            
            // 更新可用值的上限
            cur_limit -= (sz - 1);
        }
        return true;
    };

    // 初始调用，根节点 P[0]，范围 [0, n)，子节点值域 [0, n-2]
    if (!dfs(dfs, 0, n, 0, n - 2)) {
        cout << "No\n";
        return;
    }

    vector<vector<int>> by_dep(n);
    for(int i = 0; i < n; ++i) by_dep[dep[i]].push_back(i);

    vector<int> label(n);

    for(int d = n - 1; d >= 0; --d) {
        vector<pair<pair<int, vector<int>>, int>> vec;
        for(int u : by_dep[d]) {
            vector<int> children;
            for(int v : adj[u]) children.push_back(label[v]);

            if (!is_sorted(children.begin(), children.end())) {
                cout << "No\n";
                return;
            }

            vec.push_back({{ (int)adj[u].size(), children }, u});
        }
        
        sort(vec.begin(), vec.end());
        
        int cur = 0;
        for(size_t i = 0; i < vec.size(); ++i) {
            if (i > 0 && vec[i].first != vec[i-1].first) cur++;
            label[vec[i].second] = cur;
        }
    }

    cout << "Yes\n";
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}