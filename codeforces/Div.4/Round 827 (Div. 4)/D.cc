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
    vector<int> last_pos(1001, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        last_pos[x] = i;
    }
    vector<int> num;
    for (int x = 1; x <= 1000; x++) {
        if (last_pos[x] > 0) num.push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < (int)num.size(); i++) {
        for (int j = 0; j < (int) num.size(); j++) {
            int x = num[i], y = num[j];
            if (std::gcd(x, y) == 1) {
                ans = max(ans, last_pos[x] + last_pos[y]);
            }
        }
    }
    if (ans == 0) cout << -1 << "\n";
    else cout << ans << "\n";
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