#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

const int N = 200005;
const int mod = 998244353;

int w[N], mu[N], minp[N];
vector<int> pr;
vector<int> d[N];
vector<pair<int, int>> cf[N];
int cnt[8][N];
bool vis[N];
int freq[N];
vector<int> act;

ll qp(ll a, ll b) {
    ll r = 1;
    a %= mod;
    while(b) {
        if(b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

void init() {
    w[1] = 0;
    mu[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(!minp[i]) {
            minp[i] = i;
            pr.push_back(i);
            w[i] = 1;
            mu[i] = -1;
        }
        for(int p : pr) {
            if(p > minp[i] || i * p >= N) break;
            minp[i * p] = p;
            if(minp[i] == p) {
                w[i * p] = w[i];
                mu[i * p] = 0;
            } else {
                w[i * p] = w[i] + 1;
                mu[i * p] = -mu[i];
            }
        }
    }
    for(int i = 1; i < N; ++i)
        for(int j = i; j < N; j += i)
            d[j].push_back(i);

    for(int i = 1; i < N; ++i) {
        int tmp[8] = {0};
        for(int g : d[i]) {
            int k = i / g;
            if(mu[k] == 0) continue;
            int ow = w[g];
            if(ow < 8) tmp[ow] += mu[k];
        }
        for(int j = 0; j < 8; ++j)
            if(tmp[j]) cf[i].push_back({j, tmp[j]});
    }
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> uq;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(freq[a[i]] == 0) uq.push_back(a[i]);
        freq[a[i]]++;
    }

    for(int x : uq) {
        int c = freq[x];
        int uw = w[x];
        for(int t : d[x]) {
            if(!vis[t]) {
                vis[t] = 1;
                act.push_back(t);
            }
            cnt[uw][t] += c;
        }
    }

    ll pws[16];
    for(int i = 0; i < 16; ++i) pws[i] = qp(i, k);

    ll ans = 0;
    for(int t : act) {
        if(cf[t].empty()) continue;
        int nz_u[8], nz_c[8], nz_sz = 0;
        for(int i = 0; i < 8; ++i) {
            if(cnt[i][t]) {
                nz_u[nz_sz] = i;
                nz_c[nz_sz] = cnt[i][t];
                nz_sz++;
            }
        }
        if(nz_sz == 0) continue;

        for(auto &p : cf[t]) {
            int gw = p.first;
            int cv = p.second;
            ll term = 0;
            for(int i = 0; i < nz_sz; ++i) {
                int u = nz_u[i];
                ll cu = nz_c[i];
                for(int j = 0; j < nz_sz; ++j) {
                    int v = nz_u[j];
                    ll c_v = nz_c[j];
                    int b = u + v - gw;
                    term = (term + cu * c_v % mod * pws[b]) % mod;
                }
            }
            ans = (ans + term * cv) % mod;
        }
    }

    ll sub = 0;
    for(int i = 0; i < n; ++i) {
        sub = (sub + pws[w[a[i]]]) % mod;
    }

    ans = (ans - sub) % mod;
    if(ans < 0) ans += mod;
    ans = ans * qp(2, mod-2) % mod;

    cout << ans << "\n";

    for(int t : act) {
        vis[t] = 0;
        for(int i=0; i<8; ++i) cnt[i][t] = 0;
    }
    act.clear();
    for(int x : uq) freq[x] = 0;
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