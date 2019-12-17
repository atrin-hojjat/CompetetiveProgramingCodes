#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e3 + 6.66;
const int mod = 998244353;
int dp[MaxN];
int fact[MaxN];
int ifact[MaxN];
int arr[MaxN];

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

int C(int n, int r) {
  if(n < r || r < 0 || n < 0) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int& add(int& x, int y) {
  x += y;
  if(x > mod) x -= mod;
  return x;
}

int& sub(int& x, int y) {
  x -= y;
  if(x < 0) x += mod;
  return x;
}

int main() {
  prep();
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  int ans = 0;
  for(int i = n - 1; i > -1; i--) {
    if(arr[i] <= 0) continue;
    if(i + arr[i] >= n) continue;
    dp[i] = C(n - 1 - i, arr[i]);
    for(int j = i + arr[i]; j < n; j++)
      add(dp[i], 1ll * dp[j] * C(j - i - 1, arr[i]) % mod);
    add(ans, dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}
