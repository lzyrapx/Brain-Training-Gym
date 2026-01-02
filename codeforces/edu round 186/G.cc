#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

const int mod = 998244353;

const int maxn = 3e5 + 5;
const int maxnode = 8e6 + 5;

struct Node {
    int l, r;
    ll sum, mul;
} tree[maxnode];

int cnt;
vector<int> g[maxn];
ll fac[maxn];
int n, k, dep[maxn];

/**
 * 快速幂
 * @return b^e % mod
 * O(log e)
 */
ll pow_mod(ll b, ll e, int mod = 998244353) {
    ll r = 1;
    b %= mod;
    while (e) {
        if (e & 1) r = r * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return r;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
}

int newNode() {
    int id = ++cnt;
    tree[id].l = tree[id].r = tree[id].sum = 0;
    tree[id].mul = 1;
    return id;
}

void push(int u) {
    if (tree[u].mul != 1) {
        ll m = tree[u].mul;
        if (tree[u].l) {
            tree[tree[u].l].mul = tree[tree[u].l].mul * m % mod;
            tree[tree[u].l].sum = tree[tree[u].l].sum * m % mod;
        }
        if (tree[u].r) {
            tree[tree[u].r].mul = tree[tree[u].r].mul * m % mod;
            tree[tree[u].r].sum = tree[tree[u].r].sum * m % mod;
        }
        tree[u].mul = 1;
    }
}

void add(int &u, int l, int r, int p, ll v) {
    if (!u) u = newNode();
    if (l == r) {
        tree[u].sum = (tree[u].sum + v) % mod;
        return;
    }
    push(u);
    int m = l + (r - l) / 2;
    if (p <= m) add(tree[u].l, l, m, p, v);
    else add(tree[u].r, m + 1, r, p, v);
    tree[u].sum = ((tree[u].l ? tree[tree[u].l].sum : 0) + (tree[u].r ? tree[tree[u].r].sum : 0)) % mod;
}

ll ask(int u, int l, int r, int ql, int qr) {
    if (!u || ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[u].sum;
    push(u);
    int m = l + (r - l) / 2;
    return (ask(tree[u].l, l, m, ql, qr) + ask(tree[u].r, m + 1, r, ql, qr)) % mod;
}

void mul(int u, ll v) {
    if (!u) return;
    tree[u].mul = tree[u].mul * v % mod;
    tree[u].sum = tree[u].sum * v % mod;
}

int merge(int u, int v, int l, int r) {
    if (!u) return v;
    if (!v) return u;
    if (l == r) {
        tree[u].sum = (tree[u].sum + tree[v].sum) % mod;
        return u;
    }
    push(u);
    push(v);
    int m = l + (r - l) / 2;
    tree[u].l = merge(tree[u].l, tree[v].l, l, m);
    tree[u].r = merge(tree[u].r, tree[v].r, m + 1, r);
    tree[u].sum = ((tree[u].l ? tree[tree[u].l].sum : 0) + (tree[u].r ? tree[tree[u].r].sum : 0)) % mod;
    return u;
}

int dfs(int u, int d) {
    dep[u] = d;
    if (g[u].empty()) {
        int rt = 0;
        add(rt, 0, n, d, 1);
        return rt;
    }
    vector<pair<int, ll>> ch;
    for (int v : g[u]) {
        int r = dfs(v, d + 1);
        ll c = ask(r, 0, n, 0, min(n, d + k - 1));
        ch.push_back({r, c});
    }
    int zero = 0;
    ll prod = 1;
    for (auto &p : ch) {
        if (p.second == 0) zero++;
        else prod = prod * p.second % mod;
    }
    int merged = 0;
    int m = ch.size();
    ll com = fac[m - 1];
    for (auto &p : ch) {
        ll coeff = 0;
        if (p.second != 0) {
            if (zero == 0) {
                ll iv = pow_mod(p.second, mod - 2);
                debug(p.second, iv);
                coeff = ((prod * iv) % mod) * com % mod;
            }
        } else {
            if (zero == 1) coeff = (prod * com) % mod;
        }
        if (coeff) {
            mul(p.first, coeff);
            merged = merge(merged, p.first, 0, n);
        }
    }
    return merged;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    cnt = 0;
    int root = dfs(1, 0);
    cout << tree[root].sum << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}