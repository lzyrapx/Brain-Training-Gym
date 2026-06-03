#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

const int maxn = 2e5 + 123;
int v[maxn], tree[maxn * 4];

int get(int x) {
    int sum = 0;
    while (x > 0) {
        int d = x % 10;
        x /= 10;
        sum += d;
    }
    return sum;
}

void pushup(int u) {
    tree[u] = max(tree[u << 1], tree[u << 1 | 1]);
}

void build(int l, int r, int x) {
    if (l == r) {
        tree[x] = v[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, x << 1);
    build(mid + 1, r, x << 1 | 1);
    pushup(x);
}

void update(int l, int r, int x, int ql, int qr) {
    if (tree[x] < 10) return;
    if (l == r) {
        v[l] = get(v[l]);
        tree[x] = v[l];
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) update(l, mid, x << 1, ql, qr);
    if (qr > mid) update(mid + 1, r, x << 1 | 1, ql, qr);
    pushup(x);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> v[i];

    build(1, n, 1);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            update(1, n, 1, l, r);
        } else {
            int x;
            cin >> x;
            cout << v[x] << "\n";
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
    cin >> t;
    while(t--) solve();
    return 0;
}