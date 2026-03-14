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
    vector<int> cnt(n + 1, 0);
    int a;
    for (int i = 0; i < n; i++) cin >> a, cnt[a]++;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] >= 3) {
            cout << i << "\n"; return;
        }
    }
    cout << -1 << "\n";
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