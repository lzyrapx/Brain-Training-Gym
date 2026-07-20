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
    vector<ll> x(n), y(n), d1(n), d2(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        d1[i] = y[i] - x[i];  // 左对角线
        d2[i] = x[i] + y[i];  // 右对角线
    }
    auto count_pairs = [&](vector<ll> v) -> ll {
        sort(v.begin(), v.end());
        ll tot = 0, cnt = 1;
        for (int i = 0; i < (int)v.size(); i++) {
            if (v[i] == v[i - 1]) cnt++;
            else {
                tot += cnt * (cnt - 1);
                cnt = 1;
            }
        }
        tot += cnt * (cnt - 1);
        cnt = 1;
        return tot;
    };
    ll ans = 0;
    ans = count_pairs(x) + count_pairs(y) + count_pairs(d1) + count_pairs(d2);
    cout << ans << "\n";
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