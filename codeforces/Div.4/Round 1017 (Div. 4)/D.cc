#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int p = 0;
    for (int i = 0; i < n; ) {
        int j = i, k = p;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        while (k < m && t[k] == s[i]) {
            k++;
        }
        if (k - p < j - i || k - p > 2 * (j - i)) {
            cout << "NO" << endl;
            return;
        }
        i = j;
        p = k;
    }
    cout << (p == m ? "YES" : "NO") << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}