#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

// And after happily lived ever they
// 0 0 0 0 1 0
// And they lived  happily ever after

void solve() {
    int n;
    cin >> n;
    std::string s = std::bitset< 6 >( n ).to_string();
    swap(s[1],s[5]);
    swap(s[2],s[3]);
    cout << stoi(s, nullptr, 2) << endl;
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