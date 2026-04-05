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
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans = 0;
    for (int i = 0; i < (n / 2); i++) {
        for (int j = 0; j < (n + 1) / 2; j++) {
            int sum = s[i][j] - '0';  // 0
            sum += s[j][n - 1 - i] - '0'; // 90
            sum += s[n - 1 - i][n - 1 - j] - '0'; // 180
            sum += s[n - 1 - j][i] - '0'; // 270
            ans += min(4 - sum, sum);  // 0 or 1
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
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}