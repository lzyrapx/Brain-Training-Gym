#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// XOR MINUS MEDIAN
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = a ^ b ^ c;
    int m = a + b + c - max({a, b, c}) - min({a, b, c});
    cout << x - m << "\n";
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