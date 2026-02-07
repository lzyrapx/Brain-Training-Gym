#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k, x, y, z;
    cin >> n >> k >> x >> y >> z;
    cout << min(n, min(k, min(x / 2, min(y / 7, z / 4)))) << endl;
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