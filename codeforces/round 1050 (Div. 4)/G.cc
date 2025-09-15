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

const int MAXN = 200000;

vector<int> divisors[MAXN + 1];

void precompute_divisors() {
    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) {
            divisors[j].push_back(i);
        }
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void update(int node, int l, int r, int index, int value) {
        if (l == r) {
            tree[node] = value;
            return;
        }
        int mid = (l + r) >> 1;
        if (index <= mid) {
            update(2 * node, l, mid, index, value);
        } else {
            update(2 * node + 1, mid + 1, r, index, value);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > qr) return 0;
        if (l == ql && r == qr) {
            return tree[node];
        }
        int mid = (l + r) >> 1;
        if (qr <= mid) {
            return query(2 * node, l, mid, ql, qr);
        } else if (ql > mid) {
            return query(2 * node + 1, mid + 1, r, ql, qr);
        } else {
            return max(
                query(2 * node, l, mid, ql, mid),
                query(2 * node + 1, mid + 1, r, mid + 1, qr)
            );
        }
    }
};

void solve() {

    int n;
    cin >> n;
    SegmentTree segTree(n);
    vector<int> cnt(n + 1, 0);
    int current_gcd = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        current_gcd = gcd(current_gcd, x);
        for (int d : divisors[x]) {
            if (d > n) continue;
            cnt[d]++;
            segTree.update(1, 1, n, d, cnt[d]);
        }
        int ans = 0;
        if (current_gcd < n) {
            ans = segTree.query(1, 1, n, current_gcd + 1, n);
        }
        cout << ans << " ";
    }
    cout << "\n";   
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute_divisors();
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}