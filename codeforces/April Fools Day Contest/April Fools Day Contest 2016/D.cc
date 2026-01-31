#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// #ifndef ONLINE_JUDGE 
// #include "../../algo/debug.h"
// #else
// #define debug(...) ((void)0)
// #endif

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    while(n) {
        if (n % 8 == 1) ans++;
        n /= 8;
    }
    cout << ans << endl;
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