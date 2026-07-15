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
    vector<vector<int>>g(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};
    auto dfs = [&](auto& self, int x, int y) -> ll {
        ll sum = g[x][y];
        g[x][y] = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + dirx[d], ny = y + diry[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] > 0) {
                sum += self(self, nx, ny);
            }
        }
        return sum;
    };
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] > 0) {
                ans = max(ans, dfs(dfs, i, j));
            }
        }
    }
    cout << ans << "\n";
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