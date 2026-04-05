#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> vis(26, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'A';
        if (vis[c] == 0) {
            ans += 2;
            vis[c] = 1;
        } else {
            ans += 1;
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
    while (t--) solve();
    return 0;
}