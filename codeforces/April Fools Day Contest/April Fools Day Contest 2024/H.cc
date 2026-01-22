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
    vector<string> ve;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ve.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < n; j++) {
            if ((int)ve[j].size() > i) {
                s.push_back(ve[j][i]);
            }
        }
        string s2(s.rbegin(), s.rend());
        cout << (s == s2 ? "YES" : "NO") << '\n';
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
    // cin >> t;
    while(t--) solve();
    return 0;
}