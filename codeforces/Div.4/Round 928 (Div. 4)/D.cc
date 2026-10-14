#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    // map<int, int> cnt;  // AC
    // unordered_map<int, int> cnt;  // TLE
    unordered_map<int, int, custom_hash> cnt;  // AC
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int full = (1LL << 31) - 1;
    int pairs = 0;
    for (auto& p : cnt) {
        int x = p.first;
        int y = full ^ x;
        if (x < y && cnt.count(y)) {
            int c1 = p.second;
            int c2 = cnt[y];
            pairs += min(c1, c2);
        }
    }
    int ans = n - pairs;
    cout << ans << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}