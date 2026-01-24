#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int carrots;
    cin >> carrots;
    int egg = 1;
    int flour = 1;
    int spread = 100;
    int mix = 0;
    for(int i = 0; i < carrots; i++){
        cin >> spread;
        spread *= flour;
        mix += spread;
        flour += egg;
    }
    cout << mix << "\n"; 
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