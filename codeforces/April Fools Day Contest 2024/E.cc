#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// 给定假设的 mine[0] 和 mine[1]，尝试推导整个序列
// 返回 1 表示这是一种合法解，返回 0 表示不合法
int calc(int n, const vector<int>& a, int m0) {
    vector<int> m(n);
    
    // mine[-1] 默认为 0，所以 a[0] = mine[-1] + mine[1] => mine[1] = a[0]
    // 如果 a[0] > 1，说明 mine[1] 需要是 2，但这在扫雷中是不可能的（只能0或1），直接无效。
    if (a[0] > 1) return 0;
    
    m[0] = m0;
    m[1] = a[0];
    
    // 公式: a[i] = m[i-1] + m[i+1]  ==>  m[i+1] = a[i] - m[i-1]
    for (int i = 1; i < n - 1; i++) {
        int next_mine = a[i] - m[i-1];
        
        // 检查推导出的地雷数是否合法 (必须是 0 或 1)
        if (next_mine < 0 || next_mine > 1) {
            return 0; // 无解
        }
        m[i+1] = next_mine;
    }
    
    // a[n-1] 应该等于 m[n-2] + m[n] (其中 m[n] 默认为0)
    // 所以只需检查: a[n-1] == m[n-2]
    if (a[n-1] != m[n-2]) {
        return 0;
    }
    
    return 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << (a[0] == 0 ? 2 : 0) << "\n";
        return;
    }
    int ans = 0;
    ans += calc(n, a, 0);
    ans += calc(n, a, 1);
    cout << ans << "\n";
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