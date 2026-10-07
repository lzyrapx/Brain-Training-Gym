#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
      cout << s[i];
      if (i + 2 < s.size() && (s[i + 2] == 'a' || s[i + 2] == 'e')) {
        cout << '.';
      }
    }
    cout << '\n';
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