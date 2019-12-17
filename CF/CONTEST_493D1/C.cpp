#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
const int mod = 998244353;
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
  for(int i = 1; i < MaxN; i++) fact[i] = 1ll * i * fact[i - 1] % mod;
  ifact[MaxN - 1] = _pow(fact[MaxN - 1], mod - 2);
  for(int i = MaxN - 1; i > 0; --i) ifact[i - 1] = 1ll * ifact[i] * i % mod;
}

int C(int n, in r) {
  if(n < r || r < 0) return 0;
  return 1ll * fact[n] * ifact[r] % mod * fact[n - r] % mod;
}

int main() {
  prep();
  int n; scanf("%d", &n);
  int ans = 0;
  for(int i = 1; i < 2 * n; i++) {
    
  }
  return 0;
}
