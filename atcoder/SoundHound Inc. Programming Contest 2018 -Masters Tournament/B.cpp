#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int w; cin >> w;
  int I = 0;
  for(auto x : str) {
    if(I % w == 0) cout << x;
    I++;
  }
  cout << endl;
  return 0;
}
