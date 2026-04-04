#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int h, m, x;
    char c;
    cin >> h >> c >> m >> x;
    vector<int> vis(24 * 60, 0);
    int ans = 0;
    int tot_m = h * 60 + m;

    auto check = [&](int minutes) -> int {
        vector<int> v;
        int hours = minutes / 60;
        minutes %= 60;
        v.push_back(hours / 10);
        v.push_back(hours % 10);
        v.push_back(minutes / 10);
        v.push_back(minutes % 10);
        vector<int> rv = v;
        reverse(rv.begin(), rv.end());
        return v == rv;
    };
    while (!vis[tot_m]) {
        vis[tot_m] = 1;
        ans += check(tot_m);
        tot_m = (tot_m + x) % (24 * 60);
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