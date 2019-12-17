#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2000 + 200 + 20 + 2;
const int mod = 10303;
const int delta = mod;
int fact[MaxN];
int ifact[MaxN];

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * ans * base % mod;
  return ans;
}

void prep() {
  fact[0] = 1;
  for(int i = 1; i < MaxN; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
  ifact[MaxN - 1] = _pow(fact[MaxN - 1], mod - 2);
  for(int i = MaxN - 1; i > 0; i--) ifact[i - 1] = 1ll * ifact[i] * i % mod;
}

int C(int n, int r) {
  if(n < r || r < 0) return 0;
  return 1ll * fact[n] * ifact[r] * ifact[n - r] % mod;
}

int& add(int&x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int main() {
  int n; cin >> n;
  int ans = 0;
  prep();
  for(int i = 0; i < n; i++) {
    int k = 0;
    for(int j = 0; j < i; j++)
    {
      add(ans, 1ll * _pow(2, n - i - 1) * C(i, j + 1) * k % mod);
      add(k, C(i, j));
    }
  }
  cout << _pow(ans, n) << endl;
  return 0;
}
