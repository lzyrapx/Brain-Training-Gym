#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    for (int id = 21; id <= 50; id++) {
        cout << ((((min(id, 25) + id) % (2 + id % 3)) > 0) ? "1" :"0") << "\n";
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
    // cin >> t;
    while(t--) solve();
    return 0;
}