#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

const int mod = 1e9 + 7;
const unsigned U = 11, S = 7, B = 0x9d2c5680UL, T = 15, C = 0xefc60000UL, L = 18;
unsigned untemper(unsigned z) {
    unsigned y1 = z ^ (z >> L);
    unsigned y2 = y1 ^ ((y1 << T) & C);
    unsigned SM = (1 << S) - 1;
    unsigned y3 = y2 ^ ((y2 << S) & B & (SM << S));
    unsigned y4 = y3 ^ ((y3 << S) & B & (SM << (S * 2)));
    unsigned y5 = y4 ^ ((y4 << S) & B & (SM << (S * 3)));
    unsigned y6 = y5 ^ ((y5 << S) & B & (SM << (S * 4)));
    unsigned UM = (1 << U) - 1;
    unsigned y7 = y6 ^ ((y6 >> U) & (UM << (U * 2)));
    unsigned y8 = y7 ^ ((y7 >> U) & (UM << U));
    unsigned x = y8 ^ ((y8 >> U) & UM);
    return x;
}

void solve() {
    vector<int> b;
    int n;
    for (int i = 0; i < 10; i++) {
        b.push_back(rand() % (mod - 13893829 * 2) + 13893829);
    }
    cin >> n;
    vector<unsigned> v;
    unsigned x;
    for (int i = 1; i <= min(624, n); i++) {
        cout << "? " << i << ' ' << i << endl;
        cin >> x;
        v.push_back(x);
    }

    // if (v.size() < 624) return;

    mt19937 rng;
    stringstream ss;
    // 将逆向推导出的 624 个内部状态写入流
    for (int i = 0; i < 624; i++) {
        ss << untemper(v[i]) << " ";
    }
    // 写入索引 624
    // MT19937 每生成 624 个数会进行一次"扭转"(twist)
    // v[0]...v[623] 是基于当前状态生成的
    // 下一个数 v[624] 需要基于"扭转"后的新状态生成
    // 设置索引为 624 会告诉引擎当前状态已用尽，下次调用 rng() 时需立即进行 twist
    ss << 624;
    ss >> rng;
    for (int i = 624; i < n; i++) {
        v.push_back(rng());
    }
    unsigned mn = v[0];
    for (int i = 1; i < n; i++) {
        mn = min(mn, v[i]);
    }
    cout << "! " << mn << endl;  
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