#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

const ll INF = 1e18;
 
// 线段树，支持区间置0和区间求和
struct SegTree {
    int n;
    vector<ll> sum;
    vector<bool> zeroed;
 
    SegTree(int n, const vector<ll>& leaves) : n(n) {
        if (n == 0) return;
        sum.resize(4 * n);
        zeroed.resize(4 * n, false);
        build(1, 0, n - 1, leaves);
    }
 
    void build(int node, int start, int end, const vector<ll>& leaves) {
        if (start == end) {
            sum[node] = leaves[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, leaves);
        build(2 * node + 1, mid + 1, end, leaves);
        sum[node] = sum[2 * node] + sum[2 * node + 1];
    }
 
    void push(int node) {
        if (zeroed[node]) {
            zeroed[2 * node] = true;
            sum[2 * node] = 0;
            zeroed[2 * node + 1] = true;
            sum[2 * node + 1] = 0;
            zeroed[node] = false;
        }
    }
 
    void set_zero(int l, int r) {
        if (n == 0 || l > r) return;
        update(1, 0, n - 1, l, r);
    }
 
    void update(int node, int start, int end, int l, int r) {
        if (l > end || r < start) return;
        if (sum[node] == 0) return; 
        if (l <= start && end <= r) {
            zeroed[node] = true;
            sum[node] = 0;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r);
        update(2 * node + 1, mid + 1, end, l, r);
        sum[node] = sum[2 * node] + sum[2 * node + 1];
    }
 
    ll query() {
        if (n == 0) return 0;
        return sum[1];
    }
};
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int max_val = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > max_val) max_val = a[i];
    }
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--; 
    }
 
    // 1. 构建笛卡尔树 (Max Heap)
    vector<int> l(n, -1), r(n, -1);
    vector<int> stk(n);
    int top = -1;
    for (int i = 0; i < n; ++i) {
        int last = -1;
        while (top >= 0 && a[stk[top]] < a[i]) {
            last = stk[top--];
        }
        l[i] = last;
        if (top >= 0) r[stk[top]] = i;
        stk[++top] = i;
    }
    int root = (top >= 0 ? stk[0] : 0);
 
    vector<int> comp_id(n, -1);
    vector<ll> comp_min_cost;
    vector<int> comp_root;
    
    vector<vector<int>> adj(n);
    for(int i=0; i<n; ++i) {
        if(l[i] != -1) adj[i].push_back(l[i]);
        if(r[i] != -1) adj[i].push_back(r[i]);
    }
 
    auto assign_comp = [&](auto&& self, int u, int current_id) -> void {
        if (comp_id[u] != -1) return;
        comp_id[u] = current_id;
        comp_min_cost[current_id] = min(comp_min_cost[current_id], c[u]);
        
        for (int v : adj[u]) {
            if (a[v] == a[u]) {
                self(self, v, current_id);
            } else {
                // 新组件
                comp_min_cost.push_back(INF);
                comp_root.push_back(v);
                self(self, v, (int)comp_min_cost.size() - 1);
            }
        }
    };
 
    comp_min_cost.push_back(INF);
    comp_root.push_back(root);
    assign_comp(assign_comp, root, 0);
 
    // 计算 Max 元素的 Base Cost
    ll min_max_cost = INF;
    int max_count = 0;
    for(int i=0; i<n; ++i) {
        if(a[i] == max_val) {
            min_max_cost = min(min_max_cost, c[i]);
            max_count++;
        }
    }
    ll base_cost = (ll)(max_count - 1) * min_max_cost;
 
    // 3. DFS 计算叶子节点的贡献，并构建线段树
    // 我们需要线段树覆盖所有节点，以便统一索引
    // Max 节点的贡献在线段树中设为 0（因为由 base_cost 处理）
    vector<ll> leaves(n);
    vector<int> tin(n), tout(n);
    int timer = 0;
 
    auto dfs_calc = [&](auto&& self, int u, ll path_min) -> void {
        tin[u] = timer++;
        
        ll eff_cost;
        ll pass_down;
 
        if (a[u] == max_val) {
            // Max 节点
            leaves[tin[u]] = 0;
            pass_down = min_max_cost; 
        } else {
            // Non-Max 节点
            ll c_group = comp_min_cost[comp_id[u]];
            eff_cost = min(path_min, c_group);
            leaves[tin[u]] = eff_cost;
            pass_down = eff_cost;
        }
 
        if (l[u] != -1) self(self, l[u], pass_down);
        if (r[u] != -1) self(self, r[u], pass_down);
 
        tout[u] = timer - 1;
    };
 
    dfs_calc(dfs_calc, root, INF);
 
    SegTree st(n, leaves);
    cout << st.query() + base_cost << " ";
 
    // 4. 处理更新
    bool max_zeroed = false;
    for (int i = 0; i < n; ++i) {
        int idx = p[i];
        if (max_zeroed) {
            cout << 0 << " ";
            continue;
        }
 
        if (a[idx] == max_val) {
            max_zeroed = true;
            cout << 0 << " ";
        } else {
            // Non-Max Zeroing
            // 找到该节点所属组件的根节点
            int cid = comp_id[idx];
            int r_node = comp_root[cid];
            // 将整个组件子树置 0
            st.set_zero(tin[r_node], tout[r_node]);
            cout << st.query() + base_cost << " ";
        }
    }
    cout << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init_primes();
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}