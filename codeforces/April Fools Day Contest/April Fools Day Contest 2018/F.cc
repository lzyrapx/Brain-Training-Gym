#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    char c;
    int sum = 0, cur = 0;
    int sign = 1;
    while (cin >> c) {
        if (c == '+' || c == '-') {
            sum += cur;
            cur = 0;
            if (c == '+') sign = 1;
            if (c == '-') sign = -1;
        }
        cur = 10 * cur + sign * (c - '0');
    }
    cout << sum + cur << endl;
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