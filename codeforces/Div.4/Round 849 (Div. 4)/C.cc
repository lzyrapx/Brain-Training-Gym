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
    string s;
    cin >> n >> s;
    int l = 0, r = n - 1;
    while (l < r) {
        if (((s[l] - '0') ^ (s[r] - '0')) == 1) {
            l++;
            r--;
        } else {
            cout << r - l + 1 << "\n";
            return;
        }
    }
    cout << r - l + 1 << "\n";
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