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
    vector<int> a (n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int cur_max = a[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= cur_max) {
            cnt++;
            cur_max = a[i];
        }
    }
    cout << n - cnt << "\n";
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