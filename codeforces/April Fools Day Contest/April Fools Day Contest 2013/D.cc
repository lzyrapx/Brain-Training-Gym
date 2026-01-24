#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    int k;
    cin >> s >> k;
    for (int i = 0; i < (int)s.size(); i++) {
        char cur = s[i];
        if (tolower(cur) < k + 97) {
            // 如果小于，转为大写
            s[i] = toupper(cur);
        } else {
            // 否则，转为小写
            s[i] = tolower(cur);
        }
    }
    cout << s << endl;
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