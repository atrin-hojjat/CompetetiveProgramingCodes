#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * base * ans % mod;
  return ans;
}

int main() {
  int n, m; cin >> n >> m;
  int A = _pow(2, m) - 1;
  if(A < 0) A += mod;
  int B = _pow(A, n);
  cout << B << endl;
  return 0;
}
