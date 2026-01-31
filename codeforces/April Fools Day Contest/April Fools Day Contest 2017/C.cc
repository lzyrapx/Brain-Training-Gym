#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// 查找最大和最后一个数组元素的 XOR
void solve() {
    int n;
    cin >> n;
    int mx = 0, last_a = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mx = max(a, mx);
        last_a = a;
    }
    cout << (mx ^ last_a) << endl;
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