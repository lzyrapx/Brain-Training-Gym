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
    vector<ll> a(n + 1);
    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    int l = 1, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        cout << "? " << mid;
        for (int i = 1; i <= mid; i++) {
            cout << " " << i;
        }
        cout << endl;
        ll x;
        cin >> x;
        if (x > p[mid]) r = mid;
        else l = mid + 1;
    }
    cout << "! " << l << endl;
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}