#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int num = 0;
    int ans = 1;  // A
    for (int i = 1; i < (int)s.size(); i++) {
        num *= 10;
        num += s[i] - '0';
        if (num > 1) {
            ans += num;
            num = 0;
        }
    }
    cout << ans << "\n";
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