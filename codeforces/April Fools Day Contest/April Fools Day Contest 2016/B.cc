#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    vector<int> M(n), R(n);
    for (int i = 0; i < n; i++) cin >> M[i];
    for (int i = 0; i < n; i++) cin >> R[i];

    function<int(int,int)> gcd;
    gcd = [&](int x, int y) -> int {
        return y == 0 ? x : gcd(y, x % y);
    };
    int lcm = 1;
    for (int i = 0; i < n; i++) {
        lcm = lcm * M[i] / gcd(lcm, M[i]);
    }

    int cnt = 0;
    for (int i = 0; i < lcm; i++) {
        for (int j = 0; j < n; j++) {
            if (i % M[j] == R[j]) {
                cnt++;
                break;
            }
        }
    }
    // cout << cnt  << " "  << lcm << endl;
    cout << fixed << setprecision(5) << 1.0 * cnt / lcm << "\n";

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