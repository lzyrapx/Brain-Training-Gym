#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int x = 0, y = 1;
    // a <= b
    int ans = 0;
    while(x <= a && y <= b) {
        x <<= 1;
        y <<= 1;
        if (ans % 2 == 0) {
            x++;
        } else {
            y++;
        }
        ans++;
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
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}