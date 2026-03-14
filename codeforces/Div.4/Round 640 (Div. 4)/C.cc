#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// 在 1 到某个数 m 之间，能被 n 整除的数有 m / n 个，不能被 n 整除的数有 m - m / n 个
// 要找到最小的 m 使得 m - m / n >= k
void solve() {
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = 1e18;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (mid - mid / n >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}