#include <bits/stdc++.h>
using namespace std;
// kitten
void solve() {
    int F, I, T;
    cin >> F >> I >> T;
    vector<string> v(F);
    for (int i = 0; i < F; i++) cin >> v[i];
    vector<int> d(I, 0);
    for (int j = 0; j < I; j++) for (int i = 0; i < F; i++) if (v[i][j] == 'Y') d[j]++;
    int res = 0;
    for (int i = 0; i < I; i++) if (d[i] >= T) res++;
    cout << res << endl;
}
int main() {
    solve();
    return 0;
}