#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (m % k != 0) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << (cnt % k) + 1 << " ";
                cnt++;
            }
            cout << endl;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                int cnt = 0;
                for (int j = 1; j <= m; j++) {
                    cout << (cnt % k) + 1 << " ";
                    cnt++;
                }
            } else {
                int cnt = 1;
                for (int j = 1; j <= m; j++) {
                    cout << (cnt % k) + 1 << " ";
                    cnt++;
                }
            }
            cout << endl;
        }
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