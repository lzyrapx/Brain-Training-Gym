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
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
    // debug(cnt);
    vector<int> pre_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre_sum[i + 1] = pre_sum[i] + a[i];
    }

    vector<bool> can(n + 2, false);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = pre_sum[j + 1] - pre_sum[i];
            if (sum > n) break;
            if (sum <= n) {
                can[sum] = true;
            }
        }
    }
    int ans = 0;
    for (int v = 1; v <= n; v++) {
        if (can[v]) {
            ans += cnt[v];
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