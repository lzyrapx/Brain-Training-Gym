#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    string S;
    int X;
    cin >> S >> X;
    if (S == "ABC" && X < 2000) {
        cout << "YES\n"; return;
    } else if (S == "ARC" && X < 2800) {
        cout << "YES\n"; return;
    } else if (S == "AGC" && X >= 1200) {
        cout << "YES\n"; return;
    }
    cout << "NO\n";
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