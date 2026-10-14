#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    vector<string> grid(7);
    for (int i = 0; i < 7; i++) cin >> grid[i];

    int dir[3][2] = {{0, 0}, {1, -1}, {1, 1}};
    int ans = 49;
    auto dfs = [&](auto& self, int s) {
        if (s >= ans) return;
        for (int i = 1; i < 6; i++) {
            for (int j = 1; j < 6; j++) {
                if (grid[i][j] == 'B' 
                && grid[i - 1][j - 1] == 'B' 
                && grid[i - 1][j + 1] == 'B' 
                && grid[i + 1][j - 1] == 'B' 
                && grid[i + 1][j + 1] == 'B') {
                    for (auto d : dir) {
                        grid[i + d[0]][j + d[1]] = 'W';
                        self(self, s + 1);
                        grid[i + d[0]][j + d[1]] = 'B';
                    }
                    return;
                }
            }
        }
        ans = min(ans, s);
    };
    dfs(dfs, 0);
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