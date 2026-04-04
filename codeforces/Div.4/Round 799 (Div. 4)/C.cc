#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

/*

*/
void solve() {
    vector < string > g(8);
    for (int i = 0; i < 8; i++) {
        cin >> g[i];
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (g[i][j] == '#' &&
                g[i - 1][j - 1] == '#' &&
                g[i - 1][j + 1] == '#' &&
                g[i + 1][j - 1] == '#' &&
                g[i + 1][j + 1] == '#') {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
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