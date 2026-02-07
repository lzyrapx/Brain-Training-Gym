#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(char a) {
    if (a == '8') return 0; // 剪刀
    if (a == '(') return 1; // 石头
    return 2; // 布
}
 
void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < (int)s1.size(); i += 2) {
        int id1 = check(s1[i]);
        int id2 = check(s2[i]);
        if (id1 == id2) continue;  // 平
        if (id1 == 0 && id2 == 1) ans2++;
        if (id1 == 0 && id2 == 2) ans1++;
        if (id1 == 1 && id2 == 0) ans1++;
        if (id1 == 1 && id2 == 2) ans2++;
        if (id1 == 2 && id2 == 0) ans2++;
        if (id1 == 2 && id2 == 1) ans1++;
    }
    if (ans1 == ans2) puts("TIE");
    else if (ans1 > ans2) puts("TEAM 1 WINS");
    else puts("TEAM 2 WINS");
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