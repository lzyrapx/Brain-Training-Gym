#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif


void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int a1 = a ^ b;
    int b1 = c | d;
    int c1 = b & c;
    int d1 = a ^ d;
    
    int a2 = a1 & b1;
    int b2 = c1 | d1;
    
    cout << (a2 ^ b2) << endl;
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