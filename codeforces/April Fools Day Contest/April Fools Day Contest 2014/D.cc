#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    // 判断上面的信息是否是真实的
    vector<int> a = {1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0};
    int n;
    cin >> n;
    cout << a[n - 1] << endl;
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