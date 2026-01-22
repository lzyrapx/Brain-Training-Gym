#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    cout << "R" << endl;
    cout << "R" << endl;
    cout << "S" << endl;
    cout << "S" << endl;
    cout << "P" << endl;
    cout << "P" << endl;
    cout << "R" << endl;
    vector<string> ve(7);
    for (int i = 0; i < 7; i++) {
        cin >> ve[i];
    }
    map<char, char> win_strategy;
    if (ve[1] == "player") {
        // 我出R赢了 -> AI出了S -> 意味着AI在看到上一轮R后会出S -> 我的必胜策略是继续出R
        win_strategy['R'] = 'R';
    } else if (ve[2] == "player") {
        // 我出S赢了 -> AI出了P -> 意味着AI在看到上一轮R后会出P -> 我的必胜策略是出S
        win_strategy['R'] = 'S';
    } else {
        // 前面两种都没赢 -> AI出的只能是R -> 意味着AI在看到上一轮R后会出R -> 我的必胜策略是出P
        win_strategy['R'] = 'P';
    }

    if (ve[3] == "player") {
        win_strategy['S'] = 'S';
    } else if (ve[4] == "player") {
        win_strategy['S'] = 'P';
    } else {
        win_strategy['S'] = 'R';
    }


    if (ve[5] == "player") {
        win_strategy['P'] = 'P';
    } else if (ve[6] == "player") {
        win_strategy['P'] = 'R';
    } else {
        win_strategy['P'] = 'S';
    }

    char last = 'P';
    for (int i = 0; i < 13; ++i) {
        last = win_strategy[last];
        cout << last << endl;
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