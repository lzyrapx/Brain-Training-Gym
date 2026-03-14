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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sa = 0, sb = 0;
    int pre = 0, m = 0;
    while (!a.empty())
    {
        int cur = 0;
        if (m % 2 == 0) {
            while(!a.empty() && cur <= pre) {
                cur += a.front();
                a.erase(a.begin());
            }
            sa += cur;
        } else {
            while(!a.empty() && cur <= pre) {
                cur += a.back();
                a.pop_back();
            }
            sb += cur;
        }
        pre = cur;
        m++;
    }
    cout << m << " " << sa << " " << sb << "\n";
    
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}