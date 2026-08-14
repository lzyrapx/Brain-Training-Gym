#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    string s;
    cin >> s;
    vector<int> b;
    int c = 0;
    for (char x : s) {
        if (x == 'A') {
            c++;
        } else if (x == 'B') {
            b.push_back(c);
            c = 0;
        }
    }
    b.push_back(c);
    ll sum = 0;
    int minx = 1e9;
    for (auto x : b) {
        sum += x;
        if (x < minx) {
            minx = x;
        }
    }
    cout << sum - minx << "\n";
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