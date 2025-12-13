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
    vector<int> a(n);
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2) {
            odd.push_back(a[i]);
        } else {
            even.push_back(a[i]);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    reverse(odd.begin(), odd.end());
    reverse(even.begin(), even.end());
    if (odd.size() == 0) {
        for (int i = 0; i < n; ++i) {
            cout << 0 << " ";
        }
        cout << "\n";
        return;
    }
    ll val = odd[0];
    for (int i = 0; i < (int)even.size(); ++i) {
        cout << val << " ";
        val += even[i];
    }
    cout << val << " ";
    for (int i = 1; i < (int)odd.size(); ++i) {
        if (i % 2 == 1) {
            if (even.size() > 0 && i != (int)odd.size() - 1) {
                cout << val - even.back() << " ";
            } else {
                cout << 0 << " ";
            }
        } else {
            cout << val << " ";
        }
    }
    cout << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}