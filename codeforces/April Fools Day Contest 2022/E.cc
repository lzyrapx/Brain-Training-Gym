#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);

    // 按行
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j + 7 <= n; j++) {
            if (a[i].substr(j, 7) == "theseus") {
                cout << "YES\n";
                return;
            }
        }
    }

    // 按列
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < n; j++) {
            s += a[j][i];
        }
        b[i] = s;
    }
    debug(b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 7 <= n; j++) {
            if (b[i].substr(j, 7) == "theseus") {
                cout << "YES\n";
                return;
            }
        }
    }

    // 斜
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + 7 <= n && j + 7 <= n) {
                if (a[i][j] == 't' && a[i + 1][j + 1] == 'h' && a[i + 2][j + 2] == 'e' && a[i + 3][j + 3] == 's' && 
                    a[i + 4][j + 4] == 'e' && a[i + 5][j + 5] == 'u' && a[i + 6][j + 6] == 's') {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    std::cout << "NO\n";
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