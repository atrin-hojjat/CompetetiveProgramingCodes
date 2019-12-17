#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int gcd(int a, int b) {
  return a == 0 ? b : gcd(b % a, a);
}

int main() {
  int n, k; cin >> n >> k;
  if(k > 3) {
    cout << 0 << endl;
    return 0;
  }
  if(k == 1) {
    cout << n << endl;
    return 0;
  }
  if(k == 2) {
    cout << n * (n - 1) / 2 << endl;
    return 0;
  }
  int ans = 0;
  for(int i = 1; i <= n - 1; i++)
    for(int j = 1; j <= n - 1; j++) {
      int c = (i + j);
      int l = n - c;
      if(l <= 0) continue;
      if(gcd(i, j) == 1 && gcd(i, c) == 1 && gcd(c, j) == 1)
      {
        ans += l;
        if(ans >= mod) ans -= mod;
      }
    }
  cout << ans << endl;
  return 0;
}
