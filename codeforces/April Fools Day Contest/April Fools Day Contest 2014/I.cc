#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

/*
tips:
1. Golorp => Prolog
2. Jaws：     ?( 到 ):- 之间的部分(嘴里)。变量由连续的下划线 _ 表示，长度决定了变量的身份（比如 _ 是变量 A，__ 是变量 B）。分隔符（+, -等）没有意义
3. Stomach:   ):- 到 . 之间的部分(胃里)，只有 > , _ <
4. 找到一组变量的值（0-9），满足所有“Stomach”里的约束条件。约束条件比如： __ > _ 表示变量 B 的值必须大于变量 A 的值
5. 使得输出序列（由“Jaws”里的变量顺序决定）的数字字典序最小，无解输出 false

为了让字典序最小，应该让所有变量的初始值尽可能小。最理想的情况是全为 0
*/

struct Cons {
    int left_len;
    int right_len;
    char tp;  // > or <
};

void solve() {
    string s;
    cin >> s;

    // format: ?(JAWS):-STOMACH.
    int split_pos = s.find("):-");
    string jaws_str = s.substr(2, split_pos - 2);
    string stomach_str = s.substr(split_pos + 3);
    if (!stomach_str.empty() && stomach_str.back() == '.') stomach_str.pop_back();

    vector<int> res;
    map<int, int> mp;  // <pos, val>
    
    // ?(_-_/___*__):-___>__.
    // jaws: _-_/___*__
    // stomach: ___>__

    // output: 0010

    // 解析 jaws
    int cur_pos = 0;
    for (auto c: jaws_str) {
        if (c == '_')  cur_pos++;
        else {
            if (cur_pos > 0) {
                res.push_back(cur_pos);
                mp[cur_pos] = 0;
                cur_pos = 0;
            }
        }
    }
    if (cur_pos > 0) {
        res.push_back(cur_pos);
        mp[cur_pos] = 0;
        cur_pos = 0;
    }

    // 解析 stomach
    vector<Cons> cons;
    string cur_seg;
    
    stomach_str += ',';
    debug(jaws_str);
    debug(stomach_str);

    auto count = [&](string ss) -> int {
        int cnt = 0;
        for (auto c: ss) {
            if (c == '_') cnt++;
        }
        return cnt;
    };

    for(char c: stomach_str) {
        if (c == ',') {
            if (cur_seg.empty()) continue;
            auto greater = cur_seg.find('>');
            auto less = cur_seg.find('<');
            Cons con;
            auto pos = 0;
            if (greater != string::npos) {
                con.tp = '>';
                pos = greater;
            } else if (less != string::npos) {
                con.tp = '<';
                pos = less;
            } else {
                // impossible?
                exit(0);
            }
            string left_part = cur_seg.substr(0, pos);
            string right_part = cur_seg.substr(pos + 1);
            con.left_len = count(left_part);
            con.right_len = count(right_part);

            // debug(con.left_len, con.right_len);
            
            cons.push_back(con);

            cur_seg = "";
        } else {
            cur_seg += c;
        }
    }

    int num = mp.size();
    // mp[x] 全部初始化为 0

    // debug(num);
    // debug(cons.size());

    int max_iters = num * 10;
    int iter = 0;
    while(1) {
        bool ok = false;
        iter++;
        if (iter > max_iters) {
            cout << "false" << "\n"; return;
        }

        // 遍历约束条件
        for (const auto& con : cons) {
            int& vl = mp[con.left_len];
            int& vr = mp[con.right_len];
            
            if (con.tp == '>') {
                // left <= right
                if (vl <= vr) { // 不满足 >
                    vl = vr + 1;
                    ok = true;
                }
            } else { // con.tp == '<'
                // left >= right
                if (vl >= vr) {  // 不满足 <
                    vr = vl + 1;
                    ok = true;
                }
            }
            if (vl > 9 || vr > 9) {
                cout << "false" << "\n"; return;
            }
        }
        if (!ok) break;
    }
    for (auto len: res) {
        cout << mp[len] << "";
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
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}