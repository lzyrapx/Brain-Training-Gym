#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, m, r1, c1, r2, c2;
    string s;
    cin >> n >> m >> r1 >> c1 >> r2 >> c2 >> s;
    if ((r1 + c1) % 2 != (r2 + c2) % 2) {
        cout << "-1" << "\n";
        return;
    }
    int dr = (s[0] == 'D' ? 1 : -1);  // 上 or 下
    int dc = (s[1] == 'R' ? 1 : -1);  // 左 or 右
    int cnt = 0;
    int r = r1, c = c1;  // 当前位置
    set<pair<pair<int, int>, pair<int, int>>> vis;
    while (true) {
        if (vis.count({{r, c}, {dr, dc}})) {
            cout << -1 << "\n";
            return;
        }
        vis.insert({{r, c}, {dr, dc}});
        int kh = (dr == 1 ? n - r : r - 1);
        int kv = (dc == 1 ? m - c : c - 1);
        // 到水平墙和垂直墙的最小距离
        int k = min(kh, kv);
        int drt = r2 - r, dct = c2 - c;
        if (abs(drt) == abs(dct)) {  // 在同一条对角线上
            bool ok = true;  // 方向向量与当前移动方向是否一致
            if (drt != 0 && drt / abs(drt) != dr) ok = false;
            if (dct != 0 && dct / abs(dct) != dc) ok = false;
            if (ok && abs(drt) <= k) {
                cout << cnt << "\n";
                return;
            }
        }
        r += k * dr;
        c += k * dc;

        // 碰壁
        bool hit = false;
        if (k == kh) {  // 水平墙
            dr *= -1;
            hit = true;
        }
        if (k == kv) {  // 垂直墙
            dc *= -1;
            hit = true;
        }
        if (hit) {
            cnt++;
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
    while(t--) solve();
    return 0;
}