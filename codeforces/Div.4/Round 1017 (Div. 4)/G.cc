#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "../../algo/debug.h"
#else
#define debug(...)((void) 0)
#endif

void solve() {
    int times;
    deque<int>q;
    cin >> times;
    ll sum = 0, ans = 0;
    bool rev = false;
    while(times--) {
        int op;
        cin >> op;
        if (op == 1) {
            if (rev) {
                int x = q.front();
                ans -= sum;
                ans += 1LL * q.size() * x;
                q.pop_front();
                q.push_back(x);
            } else {
                int x = q.back();
                ans += sum;
                ans -= 1LL * q.size() * x;
                q.pop_back();
                q.push_front(x);
            }
        } else if (op == 2) {
            rev ^= 1;
        } else {
            int k;
            cin >> k;
            if (rev) {
                ans += sum;
                sum += k;
                q.push_front(k);
            } else {
                ans += 1LL * q.size() * k;
                sum += k;
                q.push_back(k);
            }
        }

        if (rev) {
            cout << 1LL * sum * q.size() - ans << endl;
        } else {
            cout << ans + sum << endl;
        }
    }
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