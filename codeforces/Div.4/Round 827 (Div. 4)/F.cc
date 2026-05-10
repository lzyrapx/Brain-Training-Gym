#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int q;
    cin >> q;
    bool sh = false, th = false;
    ll sl = 1, tl = 1;  // "a"
    while (q--) {
        int d; ll k;
        string s;
        cin >> d >> k >> s;
        if (d == 1) { 
            sl += k * 1LL * s.size();
            for (char c : s) {
                if (c != 'a') sh = true;
            }
        } else {
            tl += k * 1LL * s.size();
            for (char c : s) {
                if (c != 'a') th = true;
            }
        }

        // s < t => yes or no

        if (th) cout << "yes" << "\n";
        else if (sh) cout << "no" << "\n";
        else {
            if (sl < tl) cout << "yes" << "\n";
            else cout << "no" << "\n";
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
    cin >> t;
    while(t--) solve();
    return 0;
}