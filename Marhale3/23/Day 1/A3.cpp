#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e4 + 6.66;
const int mod = 10253;
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
  if(n < r) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main() {
  int ans = 0;
  int N; cin >> N;
  prep();
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i + 1; j++) {
      int k = 1ll * C(i, j) * _pow(3, j + 1) % mod * _pow(2, i - j) % mod;
      ans += k;
      if(ans >= mod) ans -= mod;
    }
  }
  int kk = _pow(2, N);
  int inv2 = (mod + 1) / 2;
  int sum = 1ll * kk * (kk - 1 + mod) % mod * inv2 % mod;
  cout << ans << " " << sum << " " << kk << endl;
  cout << 1ll * ans * sum % delta << endl;
  return 0;
}
