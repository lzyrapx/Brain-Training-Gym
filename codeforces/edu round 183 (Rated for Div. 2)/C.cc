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
    string s;
    cin >> s;

    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            cnt_a++;
        } else {
            cnt_b++;
        }
    }
    if (cnt_a == cnt_b) {
        cout << 0 << endl;
        return;
    }
    if (cnt_a == 0 || cnt_b == 0) {
        cout << -1 << endl;
        return;
    }
    int diff = cnt_a - cnt_b;
    unordered_map<int, int> vis;
    vis[0] = 0;
    int prefix_sum = 0;
    int min_len = n + 1;
    
    for (int i = 0; i < n; i++) {
        prefix_sum += (s[i] == 'a' ? 1 : -1);
        int target = prefix_sum - diff;
        if (vis.count(target)) {
            int len = i - vis[target] + 1;
            min_len = min(min_len, len);
        }
        vis[prefix_sum] = i + 1;
    }
    if (min_len < n) {
        cout << min_len << "\n";
    } else {
        cout << "-1\n";
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