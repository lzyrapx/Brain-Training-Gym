#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

template <typename T>
struct BIT {
    int n;
    vector<T> tree;
    BIT(int s) : n(s), tree(s + 1, 0) {}
    void add(int i, T v) {
        for (; i <= n; i += i & -i) tree[i] += v;
    }
    T query(int i) {
        T s = 0;
        for (; i > 0; i -= i & -i) s += tree[i];
        return s;
    }
};

// a[i] < i < a[j] < j
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    BIT<int> bit(n);
    ll ans = 0;
    for (int j = 1; j <= n; j++) {
        if (a[j] < j) {
            if (a[j] > 1) {
                ans += bit.query(a[j] - 1);
            }
            bit.add(j, 1);
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
    cin >> t;
    while (t--) solve();
    return 0;
}