#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char const *argv[]) {
 
  srand(time(0));
  int num = rand() % 2;
  if(num) {
    std::cout << "Odd" << '\n';
  }
  else{
    std::cout << "Even" << '\n';
  }
  return 0;
}
 