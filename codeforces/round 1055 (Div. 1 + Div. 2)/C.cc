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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> prefix_zero(n + 1, 0), prefix_one(n + 1, 0);
    vector<int> pattern(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix_zero[i] = prefix_zero[i - 1] + (a[i] == 0);
        prefix_one[i] = prefix_one[i - 1] + (a[i] == 1);
        // 当前元素与前一个元素相同时，记录一下
        if (i > 1 && a[i] == a[i - 1]) {
            pattern[i] = pattern[i - 1] + 1;
        } else {
            pattern[i] = pattern[i - 1];
        }
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        int zeros = prefix_zero[r] - prefix_zero[l - 1];
        int ones = prefix_one[r] - prefix_one[l - 1];
        if (zeros % 3 != 0 || ones % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        // debug((r - l + 1) / 3);
        // 每组三个元素需要最少 1 的代价 (这种情况要求01不是交替相邻，否则会多一次操作代价)
        // 一种情况，子数组是 010101 => (r - l + 1) / 3 + 1 (多一次操作代价)
        // 另一种情况， 子数组是 001011 或者 110010，至少有一个不交替相邻 => (r - l + 1) / 3
        cout << (r - l + 1) / 3 + (pattern[r] == pattern[l]) << endl;
    }
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