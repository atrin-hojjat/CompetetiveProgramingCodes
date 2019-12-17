#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int mod = 1e6 + 3;
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
  for(int i = MaxN - 1; i > 0; --i) ifact[i - 1] = 1ll * ifact[i] * i % mod;
}

int& add(int& x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int C(int n, int r) {
  if(n < r || r < 0) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int H(int n, int r) {
  return C(n + r - 1, r - 1);
}

int calc(int n, int i) {
  return 1ll * C(n, i) * H(n, i) % mod;
}

int main() {
  prep();
  int n; cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++) add(ans, calc(n, i));
  cout << ans << endl;
  return 0;
}
