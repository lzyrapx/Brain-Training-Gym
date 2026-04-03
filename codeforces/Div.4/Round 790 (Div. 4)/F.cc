#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int bl = -1, br = -1;
    int cl = -1, cr = -1;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        if (j - i >= k) {
            if (cl == -1) {
                cl = cr = a[i];
            } else if (a[i] == cr + 1) {
                cr = a[i];
            } else {
                cl = cr = a[i];
            }
            if (bl == -1 || cr - cl > br - bl) {
                bl = cl;
                br = cr;
            }
        }
        i = j;
    }
    if (bl == -1) {
        cout << -1 << "\n";
    } else {
        cout << bl << " " << br << "\n";
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
    cin >> t;
    while(t--) solve();
    return 0;
}