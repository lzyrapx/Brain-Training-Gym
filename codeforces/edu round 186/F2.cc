#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

const int mod = 998244353;
const int maxm = 600005;
const int maxb = 65; // 2^60

ll cnt[maxb];  // 记录每个等级(0-60)有多少只驯鹿
ll pw2[maxm];  // 2^n
ll inv[maxb + 20];

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


void pre() {
    pw2[0] = 1;
    for (int i = 1; i < maxm; i++)
        pw2[i] = (pw2[i - 1] * 2) % mod;
    for (int i = 1; i <= 80; i++)
        inv[i] = pow_mod(i, mod - 2, mod);
}


void solve() {
    pre();
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cnt[c]++;
    }

    for (int q = 0; q < m; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            cnt[x]++;
        } else if (t == 2) {
            int x;
            cin >> x;
            cnt[x]--;
        } else {  // t == 3
            ll x;
            cin >> x;

            ll ans = 0;
            ll ways = 1;  // 前缀完全匹配的方案数
            
            int h = 61;

            ll left = 0;
            // 计算当前总驯鹿数
            for (int i = 0; i <= 60; ++i) left += cnt[i];
            bool ok = true;

            for (int i = 60; i >= 0; i--) {
                left -= cnt[i]; // 剩余的低等级驯鹿数量 (0 到 i-1)
                ll ci = cnt[i];

                int z = -1;
                for (int b = h - 1; b >= 0; b--) {
                    if (!((x >> b) & 1)) {
                        z = b;
                        break;
                    }
                }

                int lim = 0;
                if  (z == -1) {
                    lim = h;
                } else {
                    lim = h - z;
                }
                ll low = 0, term = 1, match = 0;

                for (int j = 0; j < lim; j++) {
                    if (j == lim - 1) match = term;
                    low = (low + term) % mod;
                    // 递推计算下一个组合数 C(ci, j+1)
                    if (j < ci) {
                        ll num = (ci - j) % mod;
                        term = term * num % mod * inv[j + 1] % mod;
                    } else {
                        term = 0;
                    }
                }

                // 计算 Winning 的部分 (j >= limit)
                // 方案数 = (2^ci - low)
                ll win = (pw2[ci] - low + mod) % mod;

                // 贡献到答案：(当前Win组合) * (剩余低位任意选) * (之前的Match路径)
                ll add = win * pw2[left] % mod * ways % mod;
                ans = (ans + add) % mod;

                if (z == -1 || match == 0) {
                    ok = false;
                    break;
                }
                ways = ways * match % mod;
                h = z;
            }
            if (ok) ans = (ans + ways) % mod;
            cout << ans << "\n";
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
    // cin >> t;
    while(t--) solve();
    return 0;
}