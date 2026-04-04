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
    vector<int> x(n);
    map<int, vector<int>> p;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        p[x[i]].push_back(i + 1);
    }
    int best_v = -1, best_a = x[0], best_l = 1, best_r = 1;
    for (auto [a, v] : p) {
        // a = x[i], v = {i + 1, .., ..}
        int cur_v = 0, start = v[0];
        for (int i = 0; i < (int)v.size(); i++) {
            if (i == 0) {
                cur_v = 1;
            } else {
                // 两次出现 a 之间隔了多少个其他数字
                int d = v[i] - v[i - 1] - 1;
                // cur - d 表示减去中间不匹配数字的扣分
                // + 1 表示加上当前这次匹配的得分
                if (cur_v - d + 1 <= 0) {
                    // 放弃，重新开始
                    cur_v = 1;
                    start = v[i];
                } else {
                    // 可以留着这段
                    cur_v = cur_v - d + 1;
                }
            }
            if (cur_v > best_v) {
                best_v = cur_v;
                best_a = a;
                best_l = start;
                best_r = v[i];
            }
        }
    }
    cout << best_a << " " << best_l << " " << best_r << "\n";
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