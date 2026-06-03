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
    string s;
    cin >> n >> s;
    int x = 0, y = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
        if (x == 1 && y == 1) {
            cout << "yes" << "\n";
            return;
        }
    }
    cout << "no" << "\n";
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