#include <bits/stdc++.h>
using namespace std;

int a[123];
int main(int argc, char const *argv[]) {

  int soft = 0, hard = 0;
  int n;
  std::cin >> n;
  string s1,s2;
  for(int i = 0; i < n; i++)
  {
    std::cin >> s1 >> s2;
    if(s2=="hard") hard++;
    else soft ++;
  }
  int k1= 1,  k2 = 0;
  int a = 1, b = 0;
  int ans = 1;
  int c = 0, d = 2;
  while((k2 < hard || k1 < soft) && (k2 < soft || k1 < hard))
  {
      ans++;
      a += c; k1 += a;
      c = (c + 2) % 4;
      b += d; k2 += b;
      d = (d + 2) % 4;
  }
  std::cout << ans << '\n';
  return 0;
}
