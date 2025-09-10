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

// 给定一个数组，找到一个子数组，使得该子数组的中位数减去最小值最大，求出这个最大差值

void solve() {
    int n;
    cin >> n;
    int maxn = n + 2;
    vector<int>a(maxn);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    vector<int>cnt(maxn);
    vector<int>sum(maxn);
    vector<int>l(maxn);
    vector<int>r(maxn);
    l[0] = 0;  // can not be 1e9
    r[n + 1] = -1e9;
    for (int med = 1; med <= 100; med++) {
        for (int i = 1; i <= n; i++) cnt[i] = a[i] < med ? -1 : 1;
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + cnt[i];
        for (int i = 1; i <= n; i++) l[i] = min(l[i - 1], sum[i]);
        for (int i = n; i >= 1; --i) r[i] = max(r[i + 1], sum[i]);
        for (int i = 1; i <= n; i++) {
            if (r[i] - l[i - 1] >= 0) {
                // debug(med, a[i]);
                ans = max(ans, med - a[i]);
            }
        }
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