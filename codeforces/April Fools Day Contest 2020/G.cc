#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    vector<int> arr(11);
    for (int i = 0; i < 11; i++) {
        cin >> arr[i];
    }
    cout << fixed << setprecision(2);
    for (int i = 10; i >= 0; i--) {
        int v = arr[i];
        double a = sqrt(abs(v));
        double b = v * v * v * 5;
        double ans = a + b;
        if (ans > 400) {
            cout << "f(" << v << ") = MAGNA NIMIS!" << '\n';
        } else {
            cout << "f(" << v << ") = " << ans << '\n';
        }
    }
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