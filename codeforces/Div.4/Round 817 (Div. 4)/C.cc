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
    map<string, int> mp;
    vector<vector<string>> s(3, vector<string>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
            mp[s[i][j]]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        int ans = 0;
        for (auto s: s[i]) {
            if (mp[s] == 2) {
                ans += 1;
            } else if (mp[s] == 1) {
                ans += 3;
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
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