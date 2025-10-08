#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    int i = 0, n = (int) distance(x.begin(), x.end());
    os << "{ ";
    for (const auto& y : x) os << y << (++i < n ? ", " : "");
    return os << " }";
}
template <typename... Args>
void _debug(const char* names, Args&&... args) {
    string_view s(names);
    cout << "{ ";
    size_t i = 0, cnt = 0, n = sizeof...(args);
    auto next = [&]() {
        while (i < s.size() && (s[i] == ' ' || s[i] == ',')) ++i;
        size_t st = i;
        while (i < s.size() && s[i] != ',') ++i;
        return s.substr(st, i - st);
    };
    ((cout << next() << ": " << args << (++cnt < n ? ", " : "")), ...);
    cout << " }" << '\n';
}
#else
#define del
#define debug(...)
#endif

// 题意：
// 在一个(n+1)x(n+1)的网格上，Krug 和 Doran 玩追逐游戏。Krug 先手，然后轮流移动。
// Krug 可以上下左右移动或不动，Doran 可以上下左右以及对角线方向移动或不动。
// 两人都不能走出网格。Doran 抓住 Krug 当且仅当两人在同一格子。定
// 义生存时间为 Doran 移动的回合数（直到抓住）。双方都最优移动，求生存时间，如果无限则输出-1。

// 思路: 
// Krug 走的是曼哈顿距离，Doran 走的是切比雪夫距离距离
// Doran 走得更多，感觉不太可能有 -1 的情况
// 1e9 肯定是找规律了，

// 由于 Krug 和 Doran 都采取最优策略，Krug 会尽量往边界跑
// 而 Doran 会尽量去追。由于 Doran 的移动能力更强，他能够将 Krug 逼到角落。
// 而答案就是 Doran 将 Krug 逼到角落所需的步数?

void solve() {
    int n;
    int rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;
    if (rk > rd) {
        rk = n - rk;
        rd = n - rd;
    }
    if (ck > cd) {
        ck = n - ck;
        cd = n - cd;
    }
    ll ans = 0;
    if (rk != rd) {
        ans = max(ans, 1LL * rd);
    }
    if (ck != cd) {
        ans = max(ans, 1LL * cd);
    }
    cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}