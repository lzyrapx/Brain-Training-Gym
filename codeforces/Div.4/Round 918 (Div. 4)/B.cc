#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        if (s.find("?") != string::npos) {
           if (s.find("A") == string::npos) {
            cout << "A" << "\n";
           }
           if (s.find("B") == string::npos) {
            cout << "B" << "\n";
           }
           if (s.find("C") == string::npos) {
            cout << "C" << "\n";
           }
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
    while (t--) solve();
    return 0;
}