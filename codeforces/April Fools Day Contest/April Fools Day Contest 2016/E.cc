#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int inf = 2e9;
int qw[111];
int a[11][11];

void solve() {
    int n;
    cin >> n;
    iota(qw, qw + n, 0);
    for_each(qw, qw + n, [&] (int i) {
        for_each(qw, qw + n, [&] (int j) {
            cin >> a[i][j];
        });
    });
    for_each(qw, qw + n, [&] (int k) {
        for_each(qw, qw + n, [&] (int i) {
            for_each(qw, qw + n, [&] (int j) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            });
        });
    });
    int res = 0;
    for_each(qw, qw + n, [&] (int i) {
        for_each(qw, qw + n, [&] (int j) {
            res = max(res, a[i][j]);
        });
    });
    cout << res << '\n';
}

int main() {
    solve();
    return 0;
}