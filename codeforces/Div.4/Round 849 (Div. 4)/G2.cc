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
    ll c;
    cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> l(n), r(n);
    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; i++) {
        l[i] = a[i] + (i + 1);
        r[i] = a[i] + (n - i);
        v[i] = {min(l[i], r[i]), i};
    }
    sort(v.begin(), v.end());
    vector<ll> s(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        // 预处理代价 min(l[i], r[i]) 的前缀和，方便二分
        s[i] = v[i].first + (i > 0 ? s[i - 1] : 0);
        pos[v[i].second] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {  // 从 点 0 出发，枚举每个点作为第一个传送点
        if (l[i] > c) continue;
        int first = l[i];
        int low = 1, high = n, best = 1;
        while (low <= high) {
            int mid = (low + high) / 2; // 包括第一个点内，总共能使用的传送点数量
            ll cost = 0;
            if (mid == 1) {
                cost = first;
            } else if (mid > 1) {
                if (pos[i] < mid) { // mid 里包含点 i
                    cost = first + s[mid - 1] - v[pos[i]].first;
                } else {  // mid 里不包含点 i
                    cost = first + s[mid - 2];
                }
            }
            if (cost <= c) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans = max(ans, best);
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
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}