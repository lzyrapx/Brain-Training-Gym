#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    ll n, k;
    cin >> n >> k;
    int m = n - (k - 1);
    if (m > 0 && m % 2 == 1) {
        cout << "YES" << "\n";
        for (int i = 0; i < k - 1; i++) {
            cout << 1 << " ";
        }
        cout << m << "\n";
        return;
    }
    m = n - 2 * (k - 1);
    if (m > 0 && m % 2 == 0) {
        cout << "YES" << "\n";
        for (int i = 0; i < k - 1; i++) {
            cout << 2 << " ";
        }
        cout << m << "\n";
        return;
    }
    
    cout << "NO" << "\n";

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