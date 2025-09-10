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

const int maxn = 200010;
vector<pair<int,int>>g[maxn];

unordered_map<int, ll> mp[maxn];
pair<int, int> fa[maxn];
int a[maxn];

void dfs(int cur, int father, int cost) {
    fa[cur] = {father, cost};
    for (auto [nxt, c]: g[cur]) {
        if (nxt == father) continue;
        mp[cur][a[nxt]] += c;
        dfs(nxt, cur, c);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    int u, v, cost;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> cost;
        g[u].push_back({v, cost});
        g[v].push_back({u, cost});
        // if a[u] == a[x], then cost = 0
        if (a[u] != a[v]) {
            sum += cost;
        }
    }
    dfs(1, 0, 0);
    int x;
    v = 0;
    while (q--) {
        // repaint vertex v to color x
        cin >> v >> x;
        if (a[v] == x) {
            cout << sum << endl;
            continue;
        }
        // v's son edge
        sum -= mp[v][x];
        sum += mp[v][a[v]];
        // v's father edge
        auto& [f, c] = fa[v];
        if (a[v] == a[f]) {
            sum += c;
        }
        if (x == a[f]) {
            sum -= c;
        }
        // update
        mp[f][a[v]] -= c;
        mp[f][x] += c;
        a[v] = x;
        cout << sum << endl;
    }
    // multiple query, clear buffer
    for (int i = 1; i <= n; i++) {
        mp[i].clear();
        g[i].clear();
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