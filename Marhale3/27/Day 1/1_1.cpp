#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int mod = 1e6 + 3;

int main() {
  int n; cin >> n;
  int t = 1;
  for(int i = 1; i < n; i++) t = (t + t) % mod;
  cout << t << endl;
  return 0;
}
