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
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        if(a[i] == 'R' && b[i] != 'R') {
            cout << "no" << "\n";
            return;
        }
        if(b[i] == 'R' && a[i] != 'R') {
            cout << "no" << "\n";
            return;
        }
        if((a[i] == 'G' || a[i] == 'B') && (b[i] == 'G' || b[i] == 'B')) continue;
        if (a[i] != b[i]) {
            cout << "no" << "\n"; return;
        }
    }
    cout << "yes" << "\n";
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