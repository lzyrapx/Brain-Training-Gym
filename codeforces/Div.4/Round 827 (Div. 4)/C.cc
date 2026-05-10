#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    char g[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < 8; i++) {
        bool allr = true;
        for (int j = 0; j < 8; j++) {
            if (g[i][j] != 'R') {
                allr = false;
                break;
            }
        }
        if (allr) {
            cout << "R" << "\n";
            return;
        }
    }
    cout << "B" << "\n";
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