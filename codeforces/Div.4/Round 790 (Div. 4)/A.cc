#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    string s;
    cin >> s;
    int suma = 0, sumb = 0;
    for (int i = 0; i < 3; i++) suma += int(s[i]);
    for (int i = 3; i < 6; i++) sumb += int(s[i]);
    cout << ((suma == sumb) ? "YES" : "NO") << "\n";
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