#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 弯曲字母
vector <char> c = {'Q', 'R', 'U', 'O', 'P', 'S', 'D', 'G', 'J', 'C', 'B'};
 
bool check(char ch) {
  for (auto x : c) {
    if (x == ch) {
      return 1;
    }
  }
  return 0;
}

// 全部弯曲字母或者全部直线字母
void solve() {
    string s;
    cin >> s;
    bool o = check(s[0]);
    for (int i = 1; i < (int) s.size(); i++) {
        bool k = check(s[i]);
        if (o != k) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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