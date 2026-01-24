#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int cur = 0;
    for (char c : s) {
        while (true) {
            cout << "...\n";
            cout << ".X.\n";
            cur = (cur - 1 + 256) % 256;
            if (cur == c) {
                cout << ".X.\n";
                break;
            }
        }
    }
    cout << "...\n";
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