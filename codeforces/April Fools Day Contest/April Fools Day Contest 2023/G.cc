#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// the code should be solve https://codeforces.com/contest/1722/problem/B
void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    bool ok = true;
    for(int i = 0; i < n; i++) {
        ok &= !((s1[i] == 'R') ^ (s2[i] == 'R'));
    }
    cout << (ok ? "YES" : "NO") << '\n'; 
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