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
    int inf = 1e9;
    vector<vector<int>> dist(n, vector<int>(n, inf));
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        dist[x][y] = z;
        dist[y][x] = z;
    }
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        if (dist[0][i] >= inf) cout << -1 << "\n";
        else cout << dist[0][i] << "\n";
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