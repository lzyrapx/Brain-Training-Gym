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
    cin >> n;
    map<string, bool> mp;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        mp[s[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 1; j < (int)s[i].size(); j++) {
            string pref = s[i].substr(0, j);
            string suff = s[i].substr(j, s[i].size() - j);
            if (mp[pref] && mp[suff]) {
                ok = true; break;
            }
        }
        if (ok) cout << 1;
        else cout << 0;
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
    while (t--) solve();
    return 0;
}