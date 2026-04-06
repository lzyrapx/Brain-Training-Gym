#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    string s;
    getline(cin, s);
    
    istringstream str(s);
    string w, name;
    while(str >> w) {
        name += w[0];
    }
    cout << name << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    std::cin.ignore();
    while(t--) solve();
    return 0;
}