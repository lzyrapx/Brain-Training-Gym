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
    cout << "Division ";
    if (n >= 1900) cout << 1 << "\n";
    else if (n >= 1600 && n <= 1899) cout << 2 << "\n";
    else if (n >= 1400 && n <= 1599) cout << 3 << "\n";
    else if (n <= 1399) cout << 4 << "\n";
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