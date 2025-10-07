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

// 给你一个数组 a 和 q 个查询，每个查询 [l, r]
// 查询 [l, r] 中，出现次数严格大于 [l - r + 1] / 3 的所有数字(从小到大输出)，如果没有就输出 -1

// 1. random sampler algorithm
// 2. segment tree
// 3. mo's algorithm


// random sampler algorithm
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n + 1);
    vector<int> b;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b.push_back(a[i]);
    }

    // 离散化处理
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 1; i <= n; i++){
        // a[i] 替换为在 b 中的索引（从1开始））
        a[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    // at 是对每个值存储它在数组中出现的所有位置，为了后续用二分查找快速计算频率
    vector<vector<int>> at(n + 1);
    for (int i = 1; i <= n; i++){
        at[a[i]].push_back(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        set <int> ans;
        // random vertify
        // 设区间长度为 L，某个元素出现次数为 k > L/3
        // 单次抽样命中该元素的概率：k/L > 1/3
        // 100次抽样都命不中的概率: (1 - k/L)^100 < (2/3)^100 ≈ 3.5 × 10^-18，抽不中的概率极低
        for (int i = 1; i <= 100; i++){
            int idx = l + RNG() % (r - l + 1);  // 随机位置
            int x = a[idx];                     // 对应的值
            int count = upper_bound(at[x].begin(), at[x].end(), r) - lower_bound(at[x].begin(), at[x].end(), l);
            
            int need = (r - l + 1) / 3;        // 计算阈值
            if (count > need) {
                ans.insert(x);
            }
        }
        for (auto x : ans) {
            cout << b[x - 1] << " ";
        }
        if (ans.size() == 0) cout << -1 << " ";
        cout << endl;
    }
}

// mo's algorithm

const int maxn = 2e5 + 5;
const int k = 400;
struct seg{
  int l = 0, r = 0, i = 0;
  seg() = default;
  seg(int l, int r, int i) : l(l), r(r), i(i){}
 
  bool operator<(const seg& rhs){
    if (l / k != rhs.l / k){
      return l / k < rhs.l / k;
    }
    return r < rhs.r;
  }
};

int h[maxn];
void add(int x) {
  h[x] += 1;
}
 
void remove(int x) {
  h[x] -= 1;
}

void mo_algorithm_solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        h[i] = 0;
    }
    
    vector<int> b = a;
    vector<int> c(n);

    // 离散化
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 0; i < n; ++i){
        c[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    vector<seg> s(q);
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l -= 1;
        r -= 1;
        s[i] = seg(l, r, i);
    }
    
    sort(s.begin(), s.end());  // 不排序会 TLE

    vector<vector<int>> ans(q);
    int L = 0, R = -1;
    for (auto [l, r, i] : s) {
        while (L > l) add(c[--L]);
        while (R < r) add(c[++R]);
        while (L < l) remove(c[L++]);
        while (R > r) remove(c[R--]);
        set<int> res;
        // random vertify
        for (int j = 0; j < 100; j++){
            int idx = l + RNG() % (r - l + 1);
            int x = c[idx];
            if (h[x] > (r - l + 1) / 3){
                res.insert(a[idx]);
            }
        }
        for (int x : res){
            ans[i].push_back(x);
        }
    }
    for (int i = 0; i < q; i++){
        for (int j : ans[i]){
            cout << j << ' ';
        }
        if (ans[i].empty()){
            cout << "-1";
        }
        cout << endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) mo_algorithm_solve();
    return 0;
}