#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// write n in base m and check whether all digits are unique.
void solve() {
    int n, m;
    cin >> n >> m;
    set<int>se;
    int cnt = 0;
    while(n) {
        se.insert(n % m);
        cnt++;
        n /= m;
    }
    if ((int)se.size() == cnt) cout << "YES\n";
    else cout << "NO\n";
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