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

// 有一个游戏，数组 b，每个元素>=2。
// 两个玩家轮流操作，Poby 先手。
// Poby 的操作：选一个 >=2 的元素 x，将其变为 floor(x/2)。
// Rekkles 的操作：选一个 >=2 的元素 x，将其变为 x+1。
// 游戏当所有元素都为 1 时结束。
// 得分是 Poby 的操作次数。Poby 想最小化得分，Rekkles 想最大化得分。
// 多个查询，每个查询给出数组 a 的一个子数组 [l, r]，要求这个子数组的操作次数。

// 计算数字的二进制位数（floor(log2(x))）
int binary_length(int x) {
    return (x == 0) ? 0 : 31 - __builtin_clz(x);
}

// 判断一个数是否是 2 的幂
bool is_power_of_two(int x) {
    return (x & (x - 1)) == 0;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> base_prefix(n + 1, 0);
    vector<int> extra_prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // debug(a[i], binary_length(a[i]));
        // binary_length 是将 x 变为 1 所需的最少除法次数
        base_prefix[i + 1] = base_prefix[i] + binary_length(a[i]);
        extra_prefix[i + 1] = extra_prefix[i];

        // 假设 a[i] = x 和 a[i] = x + 1 
        // 其中的 x 都不是 2 的幂，则需要额外考虑 Rekkles 的干扰
        // 因为 Rekkles 会把这类数字 + 1，会导致 Poby 多操作一次
        if (!is_power_of_two(a[i])) {
            // a[i] = x != 2^k
            if (!is_power_of_two(a[i] - 1)) {
                // a[i] = x + 1 != 2^k + 1 => a[i] - 1 != 2^k
                // a[i] = 6,7,10,12...
                base_prefix[i + 1]++;
            } else {
                // a[i] = 3,5,9...
                extra_prefix[i + 1]++;
            }
        }
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        // 总操作次数 = 基础操作 + 额外操作的平均值
        int base_op = base_prefix[r] - base_prefix[l - 1];
        int extra_op = extra_prefix[r] - extra_prefix[l - 1];
        // extra_op / 2 个这类数会让 Poby 的操作数 + 1
        int total_op = base_op + extra_op / 2;
        cout << total_op << endl;
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