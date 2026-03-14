#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    
    for (int j = 0; j < m; j++) {
        int last = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (g[i][j] == 'o') last = i - 1;
            else if (g[i][j] == '*') {
                swap(g[i][j], g[last][j]);
                last--;
            }
        } 
    }
    for (int i = 0; i < n; i++) {
        cout << g[i] << '\n';
    }
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