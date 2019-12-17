#include <bits/stdc++.h>
using namespace std;

const int MaxN = 11;
const int mod = 10303;
const int delta = mod;

int main() {
  int n; cin >> n;
  int fact = 1, c = 0;
  for(int i = 1; i <= n; i++) {
    fact *= i;
    c += fact;
  }
  c -= fact;
  int d = fact + 3;
  int ans = 0;
  for(int i = 0; i < fact; i++)
  {
    int x = (fact - c + i) % fact + 1;
    x %= mod;
    ans = (1ll * ans * d % mod + x) % mod;
  }
  cout << ans << endl;
  return 0;
}
