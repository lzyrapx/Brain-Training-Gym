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
    
    int b_cnt = 0;
    auto f = [&](string s) {
        vector<int> ve;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                ve.push_back(b_cnt);
            } else {
                b_cnt++;
            }
        }
        ll ans = 0;
        int sz = ve.size();
        for (int i = 0; i < sz; i++) {
            if (i < sz / 2) {
                ans += ve[sz / 2] - ve[i];
            } else {
                ans += ve[i] - ve[sz / 2];
            }
        }
        ve.clear();
        return ans;
    };
    ll ans = f(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') s[i] = 'b';
        else s[i] = 'a';
    }
    cout << min(ans, f(s)) << endl;
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