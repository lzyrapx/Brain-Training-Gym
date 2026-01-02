#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

template<const int &MOD>
struct _mod_int {
    int val;
 
    _mod_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _mod_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _mod_int(int v) : _mod_int(int64_t(v)) {}
    _mod_int(unsigned v) : _mod_int(uint64_t(v)) {}
 
    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
 
    _mod_int& operator+=(const _mod_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    _mod_int& operator-=(const _mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        // 快速取模函数
        // 作用: 使用内联汇编 (Assembly) 优化 64位整数除以 32位整数 的取模运算。
        //       这通常比编译器的默认 % 运算要在某些特定的 32位环境或旧编译器下快。
        //       注意：这主要针对 x86 架构的 Codeforces 等评测机优化。
        // 时间复杂度: O(1)
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    _mod_int& operator*=(const _mod_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }
 
    _mod_int& operator/=(const _mod_int &other) {
        return *this *= other.inv();
    }
 
    friend _mod_int operator+(const _mod_int &a, const _mod_int &b) { return _mod_int(a) += b; }
    friend _mod_int operator-(const _mod_int &a, const _mod_int &b) { return _mod_int(a) -= b; }
    friend _mod_int operator*(const _mod_int &a, const _mod_int &b) { return _mod_int(a) *= b; }
    friend _mod_int operator/(const _mod_int &a, const _mod_int &b) { return _mod_int(a) /= b; }
 
    _mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    _mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    _mod_int operator++(int) { _mod_int before = *this; ++*this; return before; }
    _mod_int operator--(int) { _mod_int before = *this; --*this; return before; }
 
    _mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    friend bool operator==(const _mod_int &a, const _mod_int &b) { return a.val == b.val; }
    friend bool operator!=(const _mod_int &a, const _mod_int &b) { return a.val != b.val; }
    friend bool operator<(const _mod_int &a, const _mod_int &b) { return a.val < b.val; }
    friend bool operator>(const _mod_int &a, const _mod_int &b) { return a.val > b.val; }
    friend bool operator<=(const _mod_int &a, const _mod_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _mod_int &a, const _mod_int &b) { return a.val >= b.val; }
 
    static const int SAVE_INV = int(1e6) + 5;
    static _mod_int save_inv[SAVE_INV];
    
    // 预处理小范围数的逆元
    // 作用: 线性递推求 1 到 SAVE_INV 范围内所有数的逆元
    // 原理: inv[i] = -(MOD/i) * inv[MOD%i] (mod MOD)
    // 时间复杂度: O(SAVE_INV)，整个程序运行期间只执行一次
    static void prepare_inv() {
        // Ensures that MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);
 
        save_inv[0] = 0;
        save_inv[1] = 1;
 
        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    // 求模逆元
    // 作用: 计算 val^(MOD-2) % MOD 或使用线性递推公式
    // 时间复杂度: 
    //   1. 若 val < SAVE_INV (缓存命中): O(1)
    //   2. 若 val >= SAVE_INV: 均摊 O(1) 或 O(log MOD)（通过递归减小 val 直到命中缓存）
    _mod_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();
 
        if (val < SAVE_INV)
            return save_inv[val];
 
        _mod_int product = 1;
        int v = val;

        // 迭代法实现线性逆元公式，直到 v 落在预处理范围内
        do {
            product *= MOD - MOD / v;
            v = MOD % v;
        } while (v >= SAVE_INV);
 
        return product * save_inv[v];
    }
    
    // 快速幂
    // 作用: 计算 (*this)^p % MOD
    // 时间复杂度: O(log p)
    _mod_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);
 
        _mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            p >>= 1;
 
            if (p > 0)
                a *= a;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &os, const _mod_int &m) {
        return os << m.val;
    }
};
 
template<const int &MOD> _mod_int<MOD> _mod_int<MOD>::save_inv[_mod_int<MOD>::SAVE_INV];

const int MOD = 998244353;
using mod_int = _mod_int<MOD>;
 
template<const int &MOD>
struct combinatorics {
    using combo_int = _mod_int<MOD>;
 
    vector<combo_int> _factorial, _inv_factorial;
    int64_t prepared_maximum;
 
    combinatorics() {
        init();
    }
 
    void init() {
        _factorial = _inv_factorial = {1};
        prepared_maximum = 0;
    }
    // 预处理阶乘和阶乘逆元
    // 作用: 动态扩展预处理数组，计算到 maximum 的阶乘
    // 时间复杂度: O(maximum - prepared_maximum)，即增量线性复杂度。
    //            如果在程序中多次调用，总复杂度为 O(maximum)
    void prepare_factorials(int64_t maximum) {
        if (maximum <= prepared_maximum)
            return;
 
        // Prevent increasing prepared_maximum by only 1 each time.
        // 策略：每次扩容至少增加 1%，防止频繁小幅度扩容导致常数过大
        maximum = max(maximum, int64_t(1.01L * prepared_maximum));
        _factorial.resize(maximum + 1);
        _inv_factorial.resize(maximum + 1);

        // 正向计算阶乘
        for (int64_t i = prepared_maximum + 1; i <= maximum; i++)
            _factorial[i] = i * _factorial[i - 1];

        // 计算最大值的阶乘逆元 (费马小定理 + 快速幂/inv函数)
        _inv_factorial[maximum] = _factorial[maximum].inv();

        // 逆向递推计算阶乘逆元: (i!)^{-1} = ((i+1)!)^{-1} * (i+1)
        for (int64_t i = maximum - 1; i > prepared_maximum; i--)
            _inv_factorial[i] = (i + 1) * _inv_factorial[i + 1];
 
        prepared_maximum = maximum;
    }
    // 获取阶乘 n!
    // 时间复杂度: 首次调用 O(n)（如果未预处理），之后 O(1)
    combo_int factorial(int64_t n) {
        if (n < 0) return 0;
        prepare_factorials(n);
        return _factorial[n];
    }

    // 获取阶乘逆元 (n!)^{-1}
    // 时间复杂度: 首次调用 O(n)，之后 O(1)
    combo_int inv_factorial(int64_t n) {
        if (n < 0) return 0;
        prepare_factorials(n);
        return _inv_factorial[n];
    }
    
    // 组合数 C(n, r) = n! / (r! * (n-r)!)
    // 时间复杂度: O(1) (假设 n 已被预处理覆盖，否则会有一次性的 O(n) 开销)
    combo_int choose(int64_t n, int64_t r) {
        if (r < 0 || r > n) return 0;
        prepare_factorials(n);
        return _factorial[n] * _inv_factorial[r] * _inv_factorial[n - r];
    }
    
    // 排列数 P(n, r) = n! / (n-r)!
    // 时间复杂度: O(1) (预处理后)
    combo_int permute(int64_t n, int64_t r) {
        if (r < 0 || r > n) return 0;
        prepare_factorials(n);
        return _factorial[n] * _inv_factorial[n - r];
    }
    
    // 组合数的逆元 1/C(n, r)
    // 时间复杂度: O(1) (预处理后)
    combo_int inv_choose(int64_t n, int64_t r) {
        assert(0 <= r && r <= n);
        prepare_factorials(n);
        return _inv_factorial[n] * _factorial[r] * _factorial[n - r];
    }
    
    // 排列数的逆元 1/P(n, r)
    // 时间复杂度: O(1) (预处理后)
    combo_int inv_permute(int64_t n, int64_t r) {
        assert(0 <= r && r <= n);
        prepare_factorials(n);
        return _inv_factorial[n] * _factorial[n - r];
    }
};
 
combinatorics<MOD> combo;

/*
最优策略：
1. 每个人轮到自己时，优先消耗自己盒子里的装饰品
2. 只有当自己盒子空了，才去拿公共盒子（0号盒子）的
*/
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    ll sum = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int k = sum / n; // 每个人至少挂 k 个
    // debug(sum, n, k);

    // b0 代表 k 轮后公共盒子剩余的数量
    ll b0 = a[0];

    int z = 0; // z 代表 k 轮后，个人盒子为空的人数

    for (int i = 1; i <= n; i++) {
        if (a[i] < k) {
            // 自己的不够，消耗公共的
            b0 -= (k - a[i]);
            z++; // 此时盒子肯定是空的
        } else {
            // 自己的够 k 个
            ll remain = a[i] - k;
            if (remain > 1) {
                // 如果剩超过 1 个，怎么排都不可能挂完
                cout << 0 << endl;
                return;
            }
            if (remain == 0) {
                z++;
            }
            // 如果 remain == 1，这个人必须在下一轮挂掉，不能算进 z 里
        }
    }

    // 检查公共盒子是否被透支
    if (b0 < 0) {
        cout << 0 << endl;
        return;
    }

    // x 表示那些不挂第 k+1 个装饰品的人数（即排列末尾的人数）

    // 最后剩余 b0 个公共装饰品 + (n-z) 个个人装饰品 = 总剩余需要挂的人数
    // 总剩余需要挂的人数 r = b0 + n - z
    // 不需要挂的人数 x = n - r = n - (b0 + n - z) = z - b0
    ll x = n - (b0 + n - z);

    if (x < 0 || x > z) {
        cout << 0 << endl;
        return;
    }
    // debug(x);

    // 答案: C(z, x) * x! * (n-x)!
    // 选出 x 个空盒子的人放到末尾(不需要挂) * 末尾排列顺序 * 前面人的排列顺序
    mod_int ans = combo.choose(z, x) * combo.factorial(x) * combo.factorial(n - x);

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