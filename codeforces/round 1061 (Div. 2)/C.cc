#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// 1. 分裂操作不会增加能达到的最大公约数
// 2. 如果想要答案为 d，那么所有保留的数都必须是 d 的倍数
// 问题转化为：找到最大的 d，使得初始数组中至少有 n-k 个数是 d 的倍数

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // suffix[i] 表示 >= i 的数的个数
    vector<int> suffix(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        suffix[i] = suffix[i + 1] + cnt[i];
    }
    int ans = 1; 
    
    // 每个可能的 d
    for (int d = n; d >= 0; --d) {
        int num = 0;
        // 统计 d, 2d, 3d 的个数
        for (int mult = 1; mult <= 3 && mult * d <= n; mult++) {
            num += cnt[mult * d];
        }
        // 任意 x >= 4d，都可以通过一次分裂操作产生至少一个 d 的倍数
        if (4 * d <= n + 1) {
            num += suffix[4 * d];
        }

        if (num >= n - k) {
            ans = max(ans, d);
        }
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
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}