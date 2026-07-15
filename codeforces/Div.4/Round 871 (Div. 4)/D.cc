#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == m) {
        cout << "yes" << "\n";
        return;
    }
    if (n % 3 != 0) {
        cout << "no" << "\n";
        return;
    }
    function<bool(int, int)> check;
    check = [&](int x, int y) -> bool {
        if (x == y) return true;
        else if (x % 3 != 0) return false;
        return (check(x / 3, y) || check(2 * x / 3, y));
    };
    if (check(n, m)) cout << "yes" << "\n";
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
    while (t--) solve();
    return 0;
}