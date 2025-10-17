#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << '\n';
        return;
    }
    
    if (n == 3) {
        cout << "1 3\n";
        cout << "2 3\n";
        return;
    }
    
    if (n == 4) {
        cout << "1 2\n";
        cout << "3 1\n";
        cout << "4 1\n";
        return;
    }
    
    // 对于 n >= 5 的情况
    cout << "1 2\n";
    cout << "2 3\n";
    cout << "3 4\n";
    cout << "1 " << n << '\n';
    
    // 对于节点 5 到 n-1，连接到节点 2
    for (int i = 5; i < n; i++) {
        cout << "2 " << i << '\n';
    }
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