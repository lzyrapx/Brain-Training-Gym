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
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());
    if (c[0] != 1) {
        cout << "no" << "\n";
        return;
    }
    ll sum = c[0];
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (c[i] > sum) {
            ok = false;
            break;
        }
        sum += c[i];
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
    while(t--) solve();
    return 0;
}