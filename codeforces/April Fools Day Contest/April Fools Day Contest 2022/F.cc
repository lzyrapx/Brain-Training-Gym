#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

string calc(string s1, string s2) {
    string res = "";
    for (int i = 0; i < (int)s1.size(); i++) {
        res += (char)((s1[i] - 'a' + s2[i] - 'a') % 26 + 'a');
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    int l = s.size();
    if (l == 3) 
        cout << calc(s, "the") << endl;
    else if (l == 4)
        cout << "none" << endl;
    else if (l == 5)
        cout << calc(s, "buffy") << endl;
    else if (l == 6)
        cout << calc(s, "slayer") << endl;
    else if (l == 7)
        cout << calc(s, "vampire") << endl;
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