#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// 5 + AVG Y
void solve() {
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        sum += y;
    }
    cout << fixed << setprecision(3) << (5 + (1.0 * sum / n)) << "\n";
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