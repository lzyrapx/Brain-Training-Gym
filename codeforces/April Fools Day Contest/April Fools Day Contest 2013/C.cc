#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    double sum = 0.0;
    double foo = 0.0, bar = 0.0, baz = 0.0, quz = 1.0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        foo += a;
        bar += 1;
        if (foo * quz > bar * baz) {
            baz = foo;
            quz = bar;
        }
    }
    cout << baz / quz << endl;
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