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
    if (n == 1) cout << "walk" << "\n";
    else if (n == 2) cout << "no" << "\n";
    else if (n == 3) cout << "no" << "\n";
    else if (n == 4) cout << "no" << "\n";
    else if (n == 5) cout << "yes" << "\n";
    else if (n == 6) cout << "yes" << "\n";
    else if (n == 7) cout << "backwards" << "\n";
    else if (n == 8) cout << "seven" << "\n";
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