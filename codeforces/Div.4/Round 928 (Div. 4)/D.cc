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
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int full = (1LL << 31) - 1;
    int pairs = 0;
    for (auto& p : cnt) {
        int x = p.first;
        int y = full ^ x;
        if (x < y && cnt.count(y)) {
            int c1 = p.second;
            int c2 = cnt[y];
            pairs += min(c1, c2);
        }
    }
    int ans = n - pairs;
    cout << ans << '\n';
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
    while (t--) solve();
    return 0;
}