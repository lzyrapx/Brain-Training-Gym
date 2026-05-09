#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, q;
    cin >> n >> q;
    // s[i][j] 表示所有满足高度不超过 i && 宽度不超过 j 的矩形面积之和
    vector<vector<ll>> s(1001, vector<ll>(1001, 0));
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        s[h][w] += 1LL * h * w;
    }
    int m = 1000;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    while (q--) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        cout << s[hb - 1][wb - 1] - s[hs][wb - 1] - s[hb - 1][ws] + s[hs][ws] << "\n";
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
    while(t--) solve();
    return 0;
}