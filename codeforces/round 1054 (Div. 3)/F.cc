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

void solve() {
    int h, d;
    cin >> h >> d;

    auto calc = [&](int x) {
        // 1 + 2 + 3 + ..... + n
        return 1LL * x * (x + 1) / 2;
    };
    
    // 步长是 1，到达终点的步数一样，都要 d * (d + 1) / 2 步。只是休息次数不一样。
    // 二分休息次数
    int l = 0, r = d;
    while(l <= r) {
        int mid = (l + r) >> 1;  // 休息次数

        int cur_health = h + mid;  // 生命值

        // 把休息当作连续走路的分界点，那么走路段数为 mid + 1，每一段最小步数就是 d / (mid + 1)
        int dis = d / (mid + 1);
        // debug(d, dis);

        // 连续走 dis 步的次数为 mid + 1 - d % (mid + 1)， 连续 dis + 1 步的次数为 d % (mid + 1)
        ll need = calc(dis) * (mid + 1 - d % (mid + 1)) + calc(dis + 1) * (d % (mid + 1));
        if (need < cur_health) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        // debug(l, r);
    }
    cout << d + l << endl;
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