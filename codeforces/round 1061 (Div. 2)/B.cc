#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i];
    }
    bool hasB = false;
    for (char c : s) {
        if (c == 'B') {
            hasB = true;
            break;
        }
    }
    
    if (!hasB) {
        for (int i = 0; i < q; i++) {
            cout << a[i] << "\n";
        }
        return;
    }
    for (int i = 0; i < q; i++) {
        int ans = 0;
        while(a[i] != 0) {
            if (s[ans % n] == 'A') {
                a[i]--;
            } else {
                a[i] /= 2;
            }
            ans++;
        }
        cout << ans << "\n";
    }
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