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

// i < j && a[i] >= a[j]
void solve() {
    int n;
    cin >> n;
    BIT<int> bit(2e5 + 123);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ans += (i - 1) - bit.query(x - 1);
        bit.add(x, 1);
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