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
    int x;
    vector<int> p(2 * n + 1), vis(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            p[i + j] = x;
            vis[x] = 1;
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (vis[i] == 0) {
            p[1] = i;
            break;
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        cout << p[i] << " \n"[i == 2 * n];
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}