#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

/*
up = "bdfhklt"
down = "gjpqy"
*/
void solve() {
    string s;
    cin >> s;
    bool ok = true;
    int cnt = 0;
    for (auto c : s) {
        if (c == 'b' || c == 'd' || c == 'l' || c == 't' || c == 'k' || c == 'f' || c == 'h') cnt++;
        else if (c == 'g' || c == 'j' || c == 'p' || c == 'q' || c == 'y') cnt--;
        if (cnt < 0) ok = false;
    }
    if (ok && cnt == 0) {
        cout << "YES\n";
    } else cout << "NO\n";
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