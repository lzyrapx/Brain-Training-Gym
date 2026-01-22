#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 检查数组是否已排序，如果是，则返回其长度，否则返回其左右两半的最大答案

int a[21];
int dfs(int l, int r) {
    bool ok = 1;
    for (int i = l; i < r - 1; i++) {
        if (a[i] > a[i + 1]) {
            ok = false;
            break;
        }
    }
    if (ok) return r - l;
    int mid = (l + r) / 2;
    return max(dfs(l, mid), dfs(mid, r));
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << dfs(0, n) << endl;
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