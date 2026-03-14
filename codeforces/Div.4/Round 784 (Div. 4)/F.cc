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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int suml = a[0], sumr = a[n - 1];

    int ans = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (suml == sumr) ans = max(ans, l + 1 + n - r);
        if (suml <= sumr) {
            l += 1;
            suml += a[l];
        } else if (suml > sumr) {
            r--;
            sumr += a[r];
        }
    }
    cout << ans << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}