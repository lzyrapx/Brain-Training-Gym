#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
   ll n, k;
   cin >> n >> k;

   auto dfs = [&](auto& self, ll n, ll k) -> ll {
    if (k <= (n + 1) / 2) {
        // 第 k 个奇数
        return 2 * k - 1;
    }
    // 问题转化为在一个大小为 (n / 2) 的序列中找第 k - (n + 1) / 2 的卡片
    return 2 * self(self, n / 2, k - (n + 1) / 2);
   };
   cout << dfs(dfs, n, k) << "\n";
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