#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
   int n, s;
    cin >> n >> s;
    vector<int> a(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    if (tot < s) {
        cout << -1 << "\n";
        return;
    }
    int mx = 0, cur = 0, l = 0;
    for (int r = 0; r < n; r++) {
        cur += a[r];
        while (cur > s) {
            cur -= a[l];
            l++;
        }
        if (cur == s) {
            mx = max(mx, r - l + 1);
        }
    }
    cout << n - mx << "\n";
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