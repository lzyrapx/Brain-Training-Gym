#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    string s;
    cin >> s;
    for (int i = 2; i < (int)s.size(); i++) {
        if ((s[i] - 'A') != (s[i - 1] - 'A' + s[i - 2] - 'A') % 26) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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