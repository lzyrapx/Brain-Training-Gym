#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// 2^j * a_{i + j} < 2^{j+1} * a_{i + j + 1}
// => a_{i + j} < 2 * a_{i + j + 1}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < 2 * a[i + 1]) {
            cnt++;
        } else {
            cnt = 0;
        }
        if (cnt >= k) ans++;
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
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}