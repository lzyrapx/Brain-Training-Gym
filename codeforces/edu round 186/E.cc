#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

/*
贪心：
1. 优先使用盒子（因为不花钱）
2. 盒子的分配：显然，美观度高的盒子应该优先留给 x_i 大的朋友
*/

struct Friend {
    int id;
    int x;       // 盒子美观度要求
    int y;       // 基础礼物价格
    int z;       // 开心礼物价格
    int diff;    // 额外花费 (z - y)
};

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    
    // 从大到小
    sort(a.begin(), a.end(), greater<int>());

    // 朋友信息
    vector<Friend> friends(n);
    ll sum_y = 0;  // 基础花费
    for (int i = 0; i < n; i++) {
        cin >> friends[i].x >> friends[i].y >> friends[i].z;
        friends[i].id = i;
        sum_y += friends[i].y;
        friends[i].diff = friends[i].z - friends[i].y;
    }

    if (sum_y > k) {
        cout << 0 << "\n";
        return; 
    }

    ll budget = k - sum_y; // 剩余预算

    sort(friends.begin(), friends.end(),[&](const Friend& a, const Friend& b){
        return a.x > b.x;
    });

    priority_queue<int, vector<int>, greater<int>> pq;  // <想用盒子的人, 额外花费>
    
    vector<ll> paid_costs;

    int box_idx = 0;  // 当前考虑到第几个盒子

    for (int i = 0; i < n; i++) {
        while (box_idx < m && a[box_idx] >= friends[i].x) {
            box_idx++;
        }
        pq.push(friends[i].diff);

        // 如果想用盒子的人数 > 实际可用的符合条件的盒子数
        if ((int)pq.size() > box_idx) {
            // 选 diff 最小的人退出，因为用钱满足他的代价最小。
            int smallest_diff = pq.top();
            pq.pop();
            paid_costs.push_back(smallest_diff);
        }
    }
    
    int happy_count = pq.size();  // 分配到盒子的人数，不需要花钱

    sort(paid_costs.begin(), paid_costs.end());  // 剩下的

    for (auto cost : paid_costs) {
        if (budget >= cost) {
            budget -= cost;
            happy_count++;
        } else {
            break; // 钱不够了，剩下更贵的也买不起
        }
    }
    cout << happy_count << "\n";
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