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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == k) {
        cout << string(n, '-') << endl;
        return;
    }
    int remove_top = 0, remove_bottom = 0, uncenrtain = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '0') remove_top++;
        else if (s[i] == '1') remove_bottom++;
        else uncenrtain++; // 会移除，但不确定 top or bottom
    }
    
    string ans(n, '+');
    
    for (int i = 0; i < remove_top; i++) {
        ans[i] = '-';
    }
    for (int i = remove_top; i < remove_top + uncenrtain; i++) {
        ans[i] = '?';
    }

    for (int i = 0; i < remove_bottom; i++) {
        ans[n - 1 - i] = '-';
    }

    for (int i = remove_bottom; i < remove_bottom + uncenrtain; i++) {
        ans[n - 1 - i] = '?';
    }
    cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}