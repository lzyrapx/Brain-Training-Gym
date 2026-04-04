#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

/*

*/
void solve() {
    int n;
    cin >> n;
    set<int> se;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        se.insert(a); 
    }
    if (se.size() == n) {
        cout << n << "\n"; return;
    }
    if (se.size() % 2 == n % 2) {
        cout << se.size() << "\n";
    } else {
        cout << se.size() - 1 << "\n";
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