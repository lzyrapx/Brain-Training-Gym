#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

vector<int> ans;

void init() {
    ans.resize(1);
    ans[0] = 0;
    for (int i = 1; i <= 2e5; i++) {
        int x = i;
        int res = 0;
        while(x > 0) {
            res += x % 10;
            x /= 10;
        }
        ans.push_back(ans[i - 1] + res);
    }
}
void solve() {
    int n;
    cin >> n;
    cout << ans[n] << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}