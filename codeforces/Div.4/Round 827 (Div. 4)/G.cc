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
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<bool> vis(n, false);
    int cur = 0, lim = 31;
    for (int i = 0; i < min(n, lim); i++) {
        int maxx = -1, pos = -1;
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            int nxt = a[j];
            int v = cur | nxt;
            if (v > maxx) {
                maxx = v;
                pos = j;
            }
        }
        if (pos == -1 || cur == maxx) break;
        vis[pos] = true;
        cur = maxx;
        cout << a[pos] << " ";
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) cout << a[i] << " ";
    }
    cout << "\n";
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