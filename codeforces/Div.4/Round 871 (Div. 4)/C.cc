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
    map<string, int> mp;
    mp["00"] = mp["01"] = mp["10"] = mp["11"] = 1e9;
    int ans = 1e9;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        string s;
        cin >> s;
        mp[s] = min(x, mp[s]);
    }
    if(min(mp["11"], mp["10"] + mp["01"]) >= 1e9) {
        cout << "-1" << "\n";
    } else {
        cout << min(mp["11"], mp["10"] + mp["01"]) << "\n";
    }
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