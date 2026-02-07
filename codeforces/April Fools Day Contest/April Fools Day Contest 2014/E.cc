#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    double aa;
    cin >> aa;
    for (int a = 1; a <= 10; a++) {
        for (int h = 1; h <= 10; h++) {
            double ans = a * 1.0 * h / sqrt(4.0 * h * h + a * a);
            if (fabs(ans - aa) < 1e-5) {
                cout << a << " " << h << "\n";
                return;
            }
        }
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