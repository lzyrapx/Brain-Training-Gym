#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> last_pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last_pos[a[i]] = i;
    }
    vector<pair<int, int>> nums;
    for (int i = 1; i <= n; i++) {
        nums.push_back({last_pos[i], i});
    }
    // 按最后出现位置排序
    sort(nums.begin(), nums.end());
    // 通过选择那些较早从数组中"消失"的数字，可以尽量减少新形成的回文子数组。
    // 因为如果一个数字在原始数组中较早出现最后位置，意味着它不太可能与后续添加的数字形成回文。
    for (int i = 0; i < k; i++) {
        if (i > 0) cout << " ";
        cout << nums[i].second;
    }
    cout << "\n"; 
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