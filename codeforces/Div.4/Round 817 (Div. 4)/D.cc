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
    string s;
    cin >> s;
    ll ans = 0;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            v.push_back((n - 1 - i) - i);
            ans += i;
        } else {
            // 'R'
            v.push_back(i - (n - 1 - i));
            ans += n - 1 - i;
        }
    }
    sort(v.begin(), v.end(), greater());
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            ans += v[i];
        }
        cout << ans << " ";
    }
    cout << "\n";
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