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

struct dsu {
    vector<int>fa;
    void init(int n) {
        fa.resize(n);
        for(int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
} fa_l, fa_r;

void solve() {
    int n;
    cin >> n;
    vector<int>a(n), fa(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        fa[i] = i;
    }

    fa_l.init(n + 1);
    fa_r.init(n + 1);
    
    sort(fa.begin(), fa.end(), [&](int i, int j){
        return a[i] > a[j];
    });

    int ans = 0, mn = n;
    for (auto x: fa) {
        for (int i = 1; i <= 2; i++) {
            int f = fa_l.find(x + 1);
            if (f > 0) {
                fa_l.fa[f] = fa_l.find(f - 1);
                mn = min(mn, a[f - 1]);
            }

            f = fa_r.find(x);
            if (f < n) {
                fa_r.fa[f] = fa_r.find(f + 1);
                mn = min(mn, a[f]);
            }
        }
        ans = max(ans, a[x] - mn);
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