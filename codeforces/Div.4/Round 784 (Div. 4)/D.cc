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
    string s;
    cin >> s;
    int i = 0;
    while (i < n) {
        if (s[i] == 'W') {
            i++;
            continue;
        }
        int j = i;
        bool has_r = false, has_b = false;
        while (j < n && s[j] != 'W') {
            if (s[j] == 'R') has_r = true;
            if (s[j] == 'B') has_b = true;
            j++;
        }
        if (!has_r || !has_b) {
            cout << "NO\n";
            return;
        }
        i = j;
    }
    cout << "YES\n";
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