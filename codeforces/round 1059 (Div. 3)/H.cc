#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> intervals(m);
    for (int i = 0; i < m; i++) {
        cin >> intervals[i].first >> intervals[i].second;
        intervals[i].first--;
        intervals[i].second--;
    }

    // 排序区间
    sort(intervals.begin(), intervals.end());

    string ans(n, '0');

    // 对每个 x 判断
    for (int x = 1; x <= n; x++) {
        // 统计数组中 <x, =x, >x 的个数
        int cntLess = 0, cntEqual = 0, cntGreater = 0;
        for (int v : a) {
            if (v < x) cntLess++;
            else if (v == x) cntEqual++;
            else cntGreater++;
        }

        // 如果 x 不在数组中，直接不可能
        if (cntEqual == 0) {
            continue;
        }

        // 贪心分配模式
        vector<int> mode(m, -1); // 0: L(<=x), 1: G(>=x)
        vector<int> mustL(n, 0), mustG(n, 0);

        bool possible = true;

        for (int i = 0; i < m && possible; i++) {
            int l = intervals[i].first, r = intervals[i].second;
            // 检查区间内是否可能全 <=x
            bool canL = true, canG = true;

            // 如果区间和之前的 mustG 有重叠且重叠部分不是全是 x，则不能选 L
            for (int j = l; j <= r; j++) {
                if (mustG[j]) {
                    canL = false;
                    break;
                }
            }
            // 如果区间和之前的 mustL 有重叠且重叠部分不是全是 x，则不能选 G
            for (int j = l; j <= r; j++) {
                if (mustL[j]) {
                    canG = false;
                    break;
                }
            }

            if (!canL && !canG) {
                possible = false;
                break;
            }

            if (canL && canG) {
                // 选哪个？优先选需要 x 更少的
                // 这里简单策略：选 L
                mode[i] = 0;
                for (int j = l; j <= r; j++) mustL[j] = 1;
            } else if (canL) {
                mode[i] = 0;
                for (int j = l; j <= r; j++) mustL[j] = 1;
            } else {
                mode[i] = 1;
                for (int j = l; j <= r; j++) mustG[j] = 1;
            }
        }

        if (!possible) continue;

        // 计算 mustL 和 mustG 的交集大小
        int overlap = 0;
        for (int i = 0; i < n; i++) {
            if (mustL[i] && mustG[i]) overlap++;
        }

        if (overlap > cntEqual) continue;

        // 计算 mustL \ overlap 大小
        int onlyL = 0, onlyG = 0;
        for (int i = 0; i < n; i++) {
            if (mustL[i] && !mustG[i]) onlyL++;
            if (mustG[i] && !mustL[i]) onlyG++;
        }

        if (onlyL <= cntLess && onlyG <= cntGreater) {
            ans[x-1] = '1';
        }
    }

    cout << ans << "\n";
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