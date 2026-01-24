#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int a, b;
    cin >> a >> b;
    
    function<pair<int,int>(int,int)> calc;
    calc = [&](int a, int b) -> pair<int, int> {
        pair<int, int> res;
        res.first = res.second = 0;
        if (a < 0) return res;
        res = calc(a - 1, b & ((1 << (a << 1)) - 1));
        switch (b >> (a << 1))
        {
            case 0:
                swap(res.first, res.second);
                break;
            case 1:
                res.first += (1 << a);
                break;
            case 2:
                res.first += (1 << a);
                res.second += (1 << a);
                break;
            case 3:
                swap(res.first, res.second);
                res.second += (1 << a);
                res.first ^= (1 << a) - 1;
                res.second ^= (1 << a) - 1;
                break;
            default:
                assert(false);
                break;
        } 
        return res;
    };
    pair<int, int> k = calc(a, b);
    cout << k.first << " " << k.second << "\n";
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