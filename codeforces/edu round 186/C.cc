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
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    // 统计有多少个 i 满足 a[i...] < b[0...]
    ll count_a = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int m = 0; m < n; m++) {
            // 比较 a 的移位版本和原始 b
            if (a[(i + m) % n] >= b[m]) {
                ok = false;
                break;
            }
        }
        if (ok) count_a++;
    }
    // 统计有多少个 k 满足 b[0...] < c[k...]
    ll count_c = 0;
    for (int k = 0; k < n; k++) {
        bool ok = true;
        for (int m = 0; m < n; m++) {
            // 比较原始 b 和 c 的移位版本
            if (b[m] >= c[(k + m) % n]) {
                ok = false;
                break;
            }
        }
        if (ok) count_c++;
    }
    // count_a * count_c 得到的是 j=0 时的合法组合 (i, 0, k) 的数量
    // 乘以 n 是利用循环对称性覆盖所有 j
    cout << count_a * count_c * n << "\n";
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