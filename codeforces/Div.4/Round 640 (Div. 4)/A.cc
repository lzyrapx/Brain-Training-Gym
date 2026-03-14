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
    int m = n;
    vector<int> ans;
    int p = 1;
    while (n > 0) {
        int d = n % 10;
        if (d != 0) {
            ans.push_back(d * p);
        }
        n /= 10;
        p *= 10;
    }
    if (ans.size() == 1) {
        cout << 1 << "\n";
        cout << m << "\n";
        return;
    }
    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";
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