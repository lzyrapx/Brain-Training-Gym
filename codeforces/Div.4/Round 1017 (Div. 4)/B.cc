#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int ans_l = max(l, 0 - m);
    int ans_r = min(r, 0 + (m - abs(ans_l)));
    cout << ans_l << " " << ans_r << endl;
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