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

// 题意：给你一个数组 a，求有多少个子数组，长度在 [l, r] 之间，恰好有 k 个不同的数

void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto f = [&](vector<int>&a, int k, int x) {
        if (k < 0 || x <= 0) return 0LL;
        ll ans = 0;
        int n = a.size();
        map<int, int> cnt;
        int l = 0;
        for (int r = 0; r < n; r++) {
            cnt[a[r]]++;
            while(r - l + 1 > x || (int)cnt.size() > k) {
                cnt[a[l]]--;
                if (cnt[a[l]] == 0) {
                    cnt.erase(a[l]);
                }
                l++;
            }
            ans += 1LL * (r - l + 1);
        }
        return ans;
    };
    // ans = 滑动窗口 [l, r] 中不同元素 <= k 的的方案数 - 滑动窗口 [l, r] 中不同元素 <= k - 1 的的方案数
    ll ans = (f(a, k, r) - f(a, k, l - 1)) - (f(a, k - 1, r) - f(a, k - 1, l - 1));
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