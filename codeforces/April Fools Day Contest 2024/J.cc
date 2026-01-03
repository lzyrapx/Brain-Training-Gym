#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "yoink a" << "\n";
        cout << "yoink b" << "\n";
        cout << "*slaps a on top of b*" << "\n";
        cout << "yeet b" << "\n";
        cout << "go touch some grass" << "\n";
    } else if (n == 2) {
        cout << "yoink a" << "\n";
        cout << "bruh b is lowkey just 0" << "\n";
        cout << "rip this b fell off by a" << "\n";
        cout << "vibe check a ratios b" << "\n";
        cout << "simp for 7" << "\n";
        cout << "bruh a is lowkey just b" << "\n";
        cout << "yeet a" << "\n";
        cout << "go touch some grass" << "\n";
    } else if (n == 3) {
        cout << "yoink n" << "\n";
        cout << "yoink a" << "\n";
        cout << "bruh m is lowkey just a[0]" << "\n";
        cout << "bruh i is lowkey just 1" << "\n";
        cout << "vibe check n ratios i" << "\n";
        cout << "simp for 9" << "\n";
        cout << "yeet m" << "\n";
        cout << "go touch some grass" << "\n";
        cout << "vibe check a[i] ratios m" << "\n";
        cout << "bruh m is lowkey just a[i]" << "\n";
        cout << "*slaps 1 on top of i*" << "\n";
        cout << "simp for 5" << "\n";
    } else {
        cout << "yoink n" << "\n";
        cout << "yoink a" << "\n";
        cout << "yoink k" << "\n";
        cout << "rip this k fell off by 1" << "\n";
        cout << "bruh j is lowkey just 0" << "\n";
        cout << "vibe check n ratios j" << "\n";
        cout << "simp for 10" << "\n";
        cout << "yeet a[k]" << "\n";
        cout << "go touch some grass" << "\n";
        cout << "bruh i is lowkey just j" << "\n";
        cout << "vibe check n ratios i" << "\n";
        cout << "simp for 14" << "\n";
        cout << "simp for 22" << "\n";
        cout << "vibe check a[j] ratios a[i]" << "\n";
        cout << "simp for 19" << "\n";
        cout << "bruh l is lowkey just a[j]" << "\n";
        cout << "bruh a[j] is lowkey just a[i]" << "\n";
        cout << "bruh a[i] is lowkey just l" << "\n";
        cout << "*slaps 1 on top of i*" << "\n";
        cout << "vibe check n ratios i" << "\n";
        cout << "simp for 11" << "\n";
        cout << "*slaps 1 on top of j*" << "\n";
        cout << "vibe check n ratios 0" << "\n";
        cout << "simp for 6" << "\n";
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