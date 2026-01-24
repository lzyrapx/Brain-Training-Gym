#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
   int a1, a2, a3;
   cin >> a1 >> a2 >> a3;
   int t = 0;
   for (int i = 2; i <= a3; i++) {
    t = a1 + a2;
    a1 = a2;
    a2 = t;
   }
   cout << a2 << "\n";
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