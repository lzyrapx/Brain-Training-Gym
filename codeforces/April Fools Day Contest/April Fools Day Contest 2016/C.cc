#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int res = 0;
    for (char a: s) {
        if ('@' < a && '[' > a) res += a - 'A' + 1;
        if ('`' < a && '{' > a) res -= a - 'a' + 1;
    }
    cout << res << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}