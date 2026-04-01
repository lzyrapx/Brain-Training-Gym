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
    vector<int> p(n + 1), a(n + 1);
    vector<bool> isp(n + 1, false);
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        isp[p[i]] = true;
    }
    for (int i = 2; i <= n; i++) cin >> a[i];
    vector<int> h(n + 1, 0), r(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        h[i] = h[p[i]] + (a[i] == 1);
        r[i] = r[p[i]] + (a[i] == 2);
    }
    int inf = 1e9;
    int minh = inf, minr = inf, ans = -1;
    for (int i = 1; i <= n; i++) {
        if (!isp[i]) {
            if (h[i] < minh || (h[i] == minh && r[i] < minr)) {
                minh = h[i];
                minr = r[i];
                ans = i;
            }
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
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}