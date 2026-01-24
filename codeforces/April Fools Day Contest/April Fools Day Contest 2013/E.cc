#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;

    // 检查字符串是否包含 'Q'
    auto pos = s.find('Q');
    if (pos == string::npos) {
        cout << "Yes" << endl;
        return;
    }

    // 统计 'Q' 的数量
    int cnt = count(s.begin(), s.end(), 'Q');
    int sqc = sqrt(cnt);  // Q的数量的平方根
    
    // 计算'H'的数量和每个'H'对应的字符串长度
    int h_count = s.size() - cnt;
    int w = h_count / (sqc + 1);
    
    pos /= 2;
    string b = s.substr(pos, w + sqc);
    string ans;
    
    for (auto ch : b) {
        if (ch == 'H') {
            ans += 'H';
        } else {
            ans += b;
        }
    }
    if (s == ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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