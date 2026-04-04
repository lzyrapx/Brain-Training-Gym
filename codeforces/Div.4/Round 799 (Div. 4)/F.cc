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
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % 10]++;
    }
    vector<int> v;
    for (int i = 0; i <= 9; i++) {
        int take = min(cnt[i], 3);
        for (int j = 0; j < take; j++) {
            v.push_back(i);
        }
    }
    int m = v.size();
    bool ok = false;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if ((v[i] + v[j] + v[k]) % 10 == 3) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) break;
    }
    if (ok) cout << "yes" << "\n";
    else cout << "no" << "\n";
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