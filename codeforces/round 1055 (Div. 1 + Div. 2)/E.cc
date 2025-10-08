#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    int i = 0, n = (int) distance(x.begin(), x.end());
    os << "{ ";
    for (const auto& y : x) os << y << (++i < n ? ", " : "");
    return os << " }";
}
template <typename... Args>
void _debug(const char* names, Args&&... args) {
    string_view s(names);
    cout << "{ ";
    size_t i = 0, cnt = 0, n = sizeof...(args);
    auto next = [&]() {
        while (i < s.size() && (s[i] == ' ' || s[i] == ',')) ++i;
        size_t st = i;
        while (i < s.size() && s[i] != ',') ++i;
        return s.substr(st, i - st);
    };
    ((cout << next() << ": " << args << (++cnt < n ? ", " : "")), ...);
    cout << " }" << '\n';
}
#else
#define del
#define debug(...)
#endif

// 题意：
// 交互题。在长度为 n * n + 1 的排列中，找到长度为 n + 1 的单调（严格递增或递减）子序列。
// 每次可以问一个子序列，然后会回答你有哪些位置是前缀最大的数
// 最多 n 次查询。

// 思路：
// 一开始全问 [1, n * n + 1]；
// 中间交互器返回的长度大于等于 n + 1 的直接输出；
// 否则每次把上一次得到的序列屏蔽掉，留下剩下的序列继续问。

vector<int> query(const vector<int>& indices) {
    cout << "? " << indices.size();
    for (int i : indices) {
        cout << " " << i;
    }
    cout << endl;
    cout.flush();
    int c;
    // c is the number of visible indices from query's cout
    cin >> c;
    vector<int> j(c);
    for (int i = 0; i < c; i++) {
        // j is interactor returns values
        cin >> j[i];
        // 1 <= j[1] < j[2] < ... < j[c] <= n^2 + 1 
    }
    return j;
}

void answer(std::vector<int>& indices) {
    cout << "! ";
    // indices 对应的值递增或者递减
    for (auto idx: indices) {
        cout << idx << " ";
    }
    cout << endl;
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    int m = n * n + 1;
    vector<int> all(m);
    vector<vector<int>> res;
    iota(all.begin(), all.end(), 1); // first time, query all indices [1, n * n + 1]
    for (int i = 0; i < n; i++) {
        auto ve = query(all);
        if ((int)ve.size() >= n + 1) {
            ve.resize(n + 1);
            answer(ve);
            // no more visible indices, return immediately
            return;
        } else {
            vector<bool> vis(n * n + 1 + 1);
            for (auto x : ve) {
                // x is visible indices
                vis[x] = 1;
            }
            vector<int> tmp;
            for (auto x: all) {
                if (!vis[x]) {
                    // x is not visible indices
                    tmp.push_back(x);
                }
            }
            res.push_back(ve);
            // query all not visibel indices
            all = tmp;
        }
    }

    // 样例太弱了，很难理解，可以有多种答案，只要 indices 对应的值满足递增或递减就可以
    vector<int> ans;
    ans.push_back(all.back());
    for (int i = n - 1; i >= 0; --i) {
        auto ve = res[i];
        // ve is last interactor returns values
        for (int j = (int)ve.size() - 1; j >= 0; --j) {
            if (ans.back() > ve[j]) {
                ans.push_back(ve[j]);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    answer(ans);
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}