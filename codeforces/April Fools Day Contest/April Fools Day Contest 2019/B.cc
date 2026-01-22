#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://oeis.org/A072956
// https://oeis.org/A072957

// without 'k' 'a' 'n'
int a[100];
void solve() {
    a[2] = a[3] = a[4] = a[5] = 1;
    a[12] = a[30] = a[31] = a[35] = 1;
    a[36] = a[39] = a[43] = a[46] = 1;
    a[52] = a[64] = a[86] = 1;
    int n;
    cin >> n;
    if (a[n]) cout << "Yes\n";
    else cout << "No\n";
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