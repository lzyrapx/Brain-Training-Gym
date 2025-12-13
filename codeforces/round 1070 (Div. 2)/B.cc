#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// 101 => 101101
// 0110 => 01100110
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = s + s;
    int last_one = -1;
    int ans = 0;
    for (int i = 0; i < 2 * n ; ++i) {
        if (i >= n && s[i] == '0') {
            ans = max(ans, i - last_one);
        }
        if (s[i] == '1') {
            last_one = i;
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
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}