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
    string s;
    cin >> n >> s;

    bool found = false;
    for (int mask = 0; mask < (1 << n); mask++) {
        string p, x;
        vector<int> indices;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                p += s[i];
                indices.push_back(i + 1);
            } else {
                x += s[i];
            }
        }
        bool non_dec = true;
        for (size_t i = 1; i < p.size(); i++) {
            if (p[i - 1] > p[i]) {
                non_dec = false;
                break;
            }
        }
        bool ok = true;
        for (size_t i = 0; i < x.size() / 2; i++) {
            if (x[i] != x[x.size() - 1 - i]) {
                ok = false;
                break;
            }
        }
        if (non_dec && ok) {
            cout << indices.size() << "\n";
            if (!indices.empty()) {
                for (int idx : indices) {
                    cout << idx << " ";
                }
            }
            cout << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "-1\n";
    }  
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