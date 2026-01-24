#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

bool is_prime(ll num) {
    if (num < 2) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (ll i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

ll reverse_num(ll num) {
    ll rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

bool check(ll num) {
    ll rev = reverse_num(num);
    if (rev == num) return false;
    return is_prime(num) && is_prime(rev);
}

// 找到第 n 个这样的数，定义是其本身质数，其反转是一个与原始质数不同的质数
// http://oeis.org/A006567
void solve() {
    int n;
    cin >> n;

    ll num = 1;
    int cnt = 0;
    while(true) {
        if (check(num)) {
            cnt++;
            if (cnt == n) {
                cout << num << "\n";
                return;
            }
        }
        num++;
    }
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}