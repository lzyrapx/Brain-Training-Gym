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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> cnt(30, vector<int>(2, 0));
    for (auto x: a) {
        for (int i = 0; i < 30; i++) {
            // 预处理每一位上的 0 和 1 的个数
            if ((x >> i) & 1) {
                cnt[i][1]++;
            } else {
                cnt[i][0]++;
            }
        }
    }
    ll ans = 0;
    for (auto x: a) {
        ll sum = 0;
        for (int i = 0; i < 30; i++) {
            if ((x >> i) & 1) {
                // 贡献 = 当前位为 0 的个数 * 当前位的权重
                sum += 1LL * cnt[i][0] * (1LL << i);
            } else {
                // 贡献 = 当前位为 1 的个数 * 当前位的权重
                sum += 1LL * cnt[i][1] * (1LL << i);
            }
        }
        ans = max(ans, sum);
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