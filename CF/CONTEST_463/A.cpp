#include <bits/stdc++.h>
using namespace std;

int main() {
  string A;cin >> A;
  string B = A;
  string C = "";
  for(auto w : A)
    C = w + C;
  cout << B << C << endl;
  return 0;
}
