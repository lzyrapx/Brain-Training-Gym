#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
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

ll calc(int n, const vector<int>& v) {
    BIT<ll> bit(2);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += bit.query(2) - bit.query(v[i] + 1);
        bit.add(v[i] + 1, 1);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int f0 = -1;  // first 0
    int l1 = -1;  // last 1
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0 && f0 == -1) f0 = i;
        if (a[i] == 1) l1 = i;
    }
    ll ans = calc(n, a);
    if (f0 != -1) {
        a[f0] = 1;
        ans = max(ans, calc(n, a));
        a[f0] = 0;
    }
    if (l1 != -1) {
        a[l1] = 0;
        ans = max(ans, calc(n, a));
        a[l1] = 1;
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
    while(t--) solve();
    return 0;
}