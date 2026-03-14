#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

/*
n0 对：00
n1 对：01 或 10
n2 对：11
*/
void solve() {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    string ans;
    if (n1 == 0) {
        if (n0 > 0) ans = string(n0 + 1, '0');
        else ans = string(n2 + 1, '1');
    } else {
        // if (n0 > 0) ans = string(n0, '0');
        for (int i = 0; i < n1 + 1; i++) {
            ans += (i % 2 == 0) ? '1' : '0';
        }
        if (n0 > 0) {
            ans.insert(1, string(n0, '0'));
        }
        if (n2 > 0) {
            ans.insert(0, string(n2, '1'));
        }
    }
    cout << ans << "\n";

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