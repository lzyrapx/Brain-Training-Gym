#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
    }
    sort(a.begin(), a.end());
    ll d = 8e18;
    for (int i = 0; i + k - 1 < n; ++i) {
        int dx = a[i + k - 1].first - a[i].first;
        int dy = a[i + k - 1].second - a[i].second;
        d = min(d, 1LL * dx * dx + 1LL * dy * dy);
    }
    double PI = acos(-1);
    cout << fixed << setprecision(20) << d * PI / 4 << '\n';
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