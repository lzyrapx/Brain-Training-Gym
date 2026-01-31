#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

string get_ss(int p) {
    if(p == 0) {
        return "0";
    }
    int flag = 0;
    if(p < 0)  {
        flag = 1;
        p = -p;
    }
    string tmp;
    while(p) {
        tmp += (p % 10 + '0');
        p /= 10;
    }
    if(flag) tmp += '-';
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

// 写一个 cpp 解析器，读取一个数学表达式，然后写出 brainfuck 表示
void solve() {
    string s;
    cin >> s;

    int n = 0;
    int num = 0;
    int flag = 0;
    
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '+' || s[i] == '-') {
            if(flag == 0) {
                n += num;
            } else {
                n -= num;
            }
            
            if(s[i] == '+') {
                flag = 0;
            } else {
                flag = 1;
            }
            num = 0;
        } else {
            num = num * 10 + (s[i] - '0');
        }
    }
    
    if(flag == 0) {
        n += num;
    } else {
        n -= num;
    }
    
    string ss = get_ss(n);
    debug(n, ss);
    
    for(int i = 0; i < (int)ss.size(); i++) {
        for(int j = 0; j < ss[i]; j++) {
            cout << "+";
        }
        cout << ".";
        cout << ">" << endl;
    }
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