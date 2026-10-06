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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i].first >> ve[i].second;
    }
    sort(ve.begin(), ve.end());
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = ve[i].second;
    }
    vector<int> sorted_b = b;
    sort(sorted_b.begin(), sorted_b.end());

    BIT<int> tree(n);

    // a[i] < a[j] && b[i] > b[j]

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        // >= b[i] 的 pos
        int pos = lower_bound(sorted_b.begin(), sorted_b.end(), b[i]) - sorted_b.begin() + 1;
        // i: 已经统计的人数
        // query(pos): <= b[i] 的人数
        ans += i - tree.query(pos);
        // b[i] 占位
        tree.add(pos, 1);
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