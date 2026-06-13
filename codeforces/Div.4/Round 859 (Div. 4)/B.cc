#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x & 1) odd += x;
        else even += x;
    }
    if (even > odd) cout << "yes" << "\n";
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