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
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    bool ok = true;
    int dirx[] = {-1, -1, -1, 0,  0, 1, 1,  1};
    int diry[] = {-1, 0,   1, 1, -1, 1, 0, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '*' && !vis[i][j]) {
                vector<pair<int, int>> c;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    c.push_back(cur);
                    for (int k = 0; k < 8; k++) {
                        int nx = cur.first + dirx[k];
                        int ny = cur.second + diry[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '*' && !vis[nx][ny]) {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                if (c.size() != 3) {
                    ok = false;
                } else {
                    int r0 = n, r1 = -1, c0 = m, c1 = -1;
                    for (auto x: c) {
                        r0 = min(r0, x.first);
                        r1 = max(r1, x.first);
                        c0 = min(c0, x.second);
                        c1 = max(c1, x.second);
                    }
                    if (r1 - r0 != 1 || c1 - c0 != 1) {
                        ok = false;
                    }
                }
            }
        }
    }
    if (ok) cout << "yes" << "\n";
    else cout << "no" << "\n";
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