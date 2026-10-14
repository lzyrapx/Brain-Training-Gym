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
    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - 1; j++)
        if (matrix[i][j - 1] == '0' && matrix[i][j] == '1' && matrix[i][j + 1] == '0') {
            ok = true;
        }
    }
    if (ok) cout << "TRIANGLE" << "\n";
    else cout << "SQUARE" << "\n";
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