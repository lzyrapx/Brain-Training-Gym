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
    ll ans = 0;
    vector<vector<int>>cnt(26, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = s[0] - 'a', y = s[1] - 'a';
        for (int j = 0; j < 26; j++) {
            if (x != j) ans += cnt[j][y];
            if (y != j) ans += cnt[x][j];
        }
        cnt[x][y]++;
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