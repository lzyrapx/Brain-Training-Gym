#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE 
#include "../../algo/debug.h"
#else
#define debug(...) ((void)0)
#endif

void solve() {
   int cnt = 0;
 
  char grid[21][21];
  for(int i = 0; i < 21; i++){
    for(int j = 0; j < 21; j++){
      cin >> grid[i][j];
    }
  }
 
  for(int i = 0; i <= 21-4; i++){
    for(int j = 0; j <= 21-4; j++){
      int tmp = 0;
      for(int k = 0; k < 4; k++){
        for(int l = 0; l < 4; l++){
          if(grid[i+k][j+l] == '1' )tmp++;
        }
      }
      cnt = max(cnt, tmp);
    }
  }
  cout << cnt; 
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