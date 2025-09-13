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

// ll f(int k, vector<int>& a, int l, int r) {
//     ll ans = 0;
//     for (int i = l; i <= r; i++) {
//         while(k % a[i] == 0) {
//             k /= a[i];
//         }
//         ans += k;
//     }
//     return ans;
// }

// ll f(int k, vector<int>& a, int l, int r) {
//     ll ans = 0;
//     for (int i = l; i <= r; i++) {
//         if (k == 1) {
//             ans += (r - i + 1);
//             break;
//         }
//         if (a[i] == 1) {
//             ans += k;
//             continue;
//         }
//         if (a[i] > k) {
//             ans += k;
//             continue;
//         }
//         while (k % a[i] == 0) {
//             k /= a[i];
//         }
//         ans += k;
//     }
//     return ans;
// }

// ll f(int k, vector<int>& a, int l, int r) {
//      if (l > r) return 0;
//     if (l == r) {
//         while (k % a[l] == 0) {
//             k /= a[l];
//         }
//         return k;
//     }
//     // 分治处理左右两部分
//     int mid = (l + r) / 2;

//     // 计算左半部分处理后的 k 值
//     ll left_sum = f(k, a, l, mid);
    
//     int temp_k = k;
//     for (int i = l; i <= mid; i++) {
//         while (temp_k % a[i] == 0) {
//             temp_k /= a[i];
//         }
//     }
    
//     ll right_sum = f(temp_k, a, mid + 1, r);
    
//     return left_sum + right_sum;
// }

const int maxn = 1e5 + 10;
vector<int> divisors[maxn];

void init() {
    int N = 1e5 + 1;
    for (int i = 2; i <= N; i++) {
        for (int j = i; j < N; j += i) {
            // j % i== 0
            divisors[j].push_back(i);       
        }
    }
}

map<int, vector<int>>idx;

ll f(int k, vector<int>& a, int l, int r) {
    ll ans = 0;
    while (l <= r) {
        int j = r + 1;
        for (auto x: divisors[k]) {
            int a_x = x;
            auto it = lower_bound(idx[a_x].begin(), idx[a_x].end(), l);
            if (it != idx[a_x].end()) {
                j = min(j, *it);
            }
        }
        ans += 1LL * (j - l) * k;
        if (j != r + 1) {
            k /= a[j];
        }
        l = j;
    }
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int>a(n + 1);
    idx.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    while(q--) {
        int k, l, r;
        cin >> k >> l >> r;
        cout << f(k, a, l, r) << endl;
    }

}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    init();
    cin >> t;
    while(t--) solve();
    return 0;
}