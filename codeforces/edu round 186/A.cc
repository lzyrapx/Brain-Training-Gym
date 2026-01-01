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
    int five_cnt = 0, six_cnt = 0;
    for (int i = 0; i + 4 <= n; i++) {
        if (s.substr(i, 4) == "2025") five_cnt++;
        if (s.substr(i, 4) == "2026") six_cnt++;
    }
    if (five_cnt == 0) {
        cout << 0 << "\n";
    } else if (six_cnt > 0){
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}