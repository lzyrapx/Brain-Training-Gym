#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// https://en.wikipedia.org/wiki/Braille
// 用盲文字体写出数字，并检查最终的符号是否是回文
void solve() {
    map<char, char> H;
    H['3'] = '3';
    H['4'] = '6';
    H['5'] = '9';
    H['6'] = '4';
    H['7'] = '7';
    H['8'] = '0';
    H['9'] = '5';
    H['0'] = '8';
    string s;
    cin >> s;
    int ok = 1;
    for(int i = 0; i < s.size(); i++) {
        if(!H.count(s[i])) ok = 0;
        else {
            if(H[s[i]] != s[s.size( ) - 1 - i]) ok = 0;
        }
    }
    if (ok) cout << "Yes" << "\n";
    else cout << "No\n";
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