#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

/*

*/
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    int ans = 0;

    auto calc = [&](int i, int j) -> int {
      int sum = mat[i][j];
      for (int x = i + 1, y = j + 1; x < n && y < m; x++, y++) {
        sum += mat[x][y];
      }
      for (int x = i - 1, y = j + 1; x >= 0 && y < m; x--, y++) {
        sum += mat[x][y];
      }
      for (int x = i + 1, y = j - 1; x < n && y >= 0; x++, y--) {
        sum += mat[x][y];
      }
      for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--) {
        sum += mat[x][y];
      }
      return sum;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, calc(i, j));
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
    while (t--) solve();
    return 0;
}