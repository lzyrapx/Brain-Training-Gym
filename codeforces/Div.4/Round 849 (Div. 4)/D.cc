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
    string s;
    cin >> n >> s;
    
    vector<int> pref(n+1, 0), suff(n+1, 0);
    vector<int> cnt(26, 0);
    
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a'] = 1;
        pref[i + 1] = accumulate(cnt.begin(), cnt.end(), 0);
    }
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = n - 1; i >= 0; --i) {
        cnt[s[i] - 'a'] = 1;
        suff[i] = accumulate(cnt.begin(), cnt.end(), 0);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, pref[i] + suff[i]);
    }
    cout << ans << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}