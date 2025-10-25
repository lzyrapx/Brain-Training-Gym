#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

int ask(int i, int x) {
    cout << "? " << i << " " << x << "\n";
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> p;
    for (int i = 1; i <= n; i++) {
        p.push_back(i); // 1~n
    }
    vector<int> queryable_indices;
    for (int i = 1; i <= n - 1; i++) {
        queryable_indices.push_back(i); // 1~n-1
    }

    int cur_bit = 0; // 从最低位开始处理

    while (p.size() > 1) {
        // 将可能的值按当前位分成两组
        vector<vector<int>> values_by_bit(2);
        for (int value : p) {
            int bit_value = (value >> cur_bit) & 1; // 当前位的值是 0 or 1
            values_by_bit[bit_value].push_back(value);
        }

        // 查询每个索引的当前位值
        vector<vector<int>> indices_by_ask(2);
        for (int index : queryable_indices) {
            int ask_bit_value = ask(index, 1 << cur_bit); // 查询该索引对应的值在当前位是 1 or 0
            indices_by_ask[ask_bit_value].push_back(index);
        }

        // 选择符合条件的一组值
        for (int bit = 0; bit < 2; bit++) {
            debug(bit, indices_by_ask[bit], values_by_bit[bit]);
            if (indices_by_ask[bit].size() ==  values_by_bit[bit].size() - 1) {
                // 为什么是这个条件：
                // 1. 排列 p 中的每个值都是唯一的
                // 2. 要查询的是前 n-1 个索引，而 p_n 不在查询范围内
                // 3. 如果 p_n 的当前位是0，那么 所有当前位为0的值中，除了 p_n 之外，都会出现在查询结果中
                // 所以，查询结果为 bit 的索引数量应该比当前位为 bit 的候选值数量少 1 即可
                p = values_by_bit[bit];
                queryable_indices = indices_by_ask[bit];
                break;
            }
        }
        cur_bit++; // 处理下一位   
    }
    debug(p);
    cout << "! " << p[0] << "\n";
    cout.flush();
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