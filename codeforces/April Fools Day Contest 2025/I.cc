#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

vector<string> v{"la", "le", "lon", "sha", "she", "shon", "ta", "te", "ton"};
ll trans(string x) {
    ll res = 0;
    for (int i = 0; i < x.size()-1; ){
        for (int j = 0; j < 9; j++) {
            auto s = x.find(v[j], i);
            if(s != string::npos && s == i) {
                i += v[j].size();
                res = res * 9 + j;
                break;
            }
        }
    }
    return res;
}
void out(ll x) {
    string p;
    while (x) {
        p = v[x % 9] + p;
        x /= 9;
    }
    p += 's';
    cout << p << '\n';
}

void solve() {
    string a, b;
    cin >> a >> b;
    out(trans(a) + trans(b));
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