#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

vector<string> Elementary = {"AC", "AG", "AL", "AM", "AR", "AS", "AT", "AU", "B",
"BA", "BE", "BH", "BI", "BK", "BR", "C", "CA", "CD", "CE", "CF", "CL", "CM", "CN",
"CO", "CR", "CS", "CU", "DB", "DS", "DY", "ER", "ES", "EU", "F", "FE", "FL", "FM",
"FR", "GA", "GD", "GE", "H", "HE", "HF", "HG", "HO", "HS", "I", "IN", "IR", "K",
"KR", "LA", "LI", "LR", "LU", "LV", "MC", "MD", "MG", "MN", "MO", "MT", "N", "NA",
"NB", "ND", "NE", "NH", "NI", "NO", "NP", "O", "OG", "OS", "P", "PA", "PB", "PD",
"PM", "PO", "PR", "PT", "PU", "RA", "RB", "RE", "RF", "RG", "RH", "RN", "RU", "S",
"SB", "SC", "SE", "SG", "SI", "SM", "SN", "SR", "TA", "TB", "TC", "TE", "TH", "TI",
"TL", "TM", "TS", "U", "V", "W", "XE", "Y", "YB", "ZN", "ZR"};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> vis(n + 1, false);
    vis[0] = true;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) continue;
        for (auto q: Elementary) {
            if (s.substr(i, q.size()) == q) {
                vis[i + q.size()] = true;
            }
        }
    }
    if (vis[n]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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