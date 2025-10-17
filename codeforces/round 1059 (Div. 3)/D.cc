#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif


ll ask1(int l, int r) {
    cout << "1 " << l << " " << r << endl;
    ll ans;
    cin >> ans; // the sum of the subarray of the original permutation
    return ans;
}

ll ask2(int l, int r) {
    cout << "2 " << l << " " << r << endl;
    ll ans;
    cin >> ans;  // the sum of the subarray of the modified array
    return ans;
}

void solve() {
    int n;
    cin >> n;
    ll total_p = 1LL * n * (n + 1) / 2;
    debug(total_p);
    ll total_a = ask2(1, n);
    ll k = total_a - total_p;
    
    int low = 1, high = n;
    while (low < high) {
        int mid = (low + high) >> 1;
        ll sum_p = ask1(1, mid);
        ll sum_a = ask2(1, mid);
        ll diff = sum_a - sum_p;
        if (diff == 0) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    debug(low, k, low + k - 1);
    cout << "! " << low << " " << low + k - 1 << endl;
    cout.flush();
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