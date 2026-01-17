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
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    function<int(int,int)> dfs;
    dfs = [&](int x, int y) -> int {
        if(x == n - 1 && y == m - 1) return s[x][y] == '*';
        if(x == n - 1) return dfs(x, y + 1) + (s[x][y] == '*');
        if(y == m - 1) return dfs(x + 1, y) + (s[x][y] == '*');
        if(s[x + 1][y] == s[x][y + 1]) return dfs(x, y + 1) + (s[x][y] == '*');
        return (s[x + 1][y] == '*'? dfs(x + 1, y): dfs(x, y + 1)) + (s[x][y] == '*');
    };
    cout << dfs(0, 0) << "\n";
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