#include <bits/stdc++.h>
using namespace std;

const int MaxN = 50 + 6.66;
const int mod = 1e9 + 7;
int dp[2][MaxN][MaxN];
int fact[MaxN];
int ifact[MaxN];

void add(int&x, int y) {
  x += y;
  if(x > mod) x -= mod;
}

void div2(int &x) {
  if(x % 2) x += mod;
  x /= 2;
}

void prep() {
  fact[0] = 1;
  for(int i = 1; i < MaxN; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
  ifact[MaxN - 1] = 1;
  for(int exp = mod - 2, base = fact[MaxN - 1]; 
      exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ifact[MaxN - 1] = 1ll * ifact[MaxN - 1] * base % mod;
  for(int i = MaxN - 1; i > 0; i--) ifact[i - 1] = 1ll * ifact[i] * i % mod;
}

int C(int n, int r) {
  if(r < 0 || r > n) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main() {
  prep();
  dp[1][1][0] = 1;
  for(int i = 2; i < MaxN; i++) {
    for(int j = 0; j < i; j++)
      for(int m = 0; m < 2; m++) {
        int mask = 1;
        if(m & 1) mask = 0;
        add(dp[mask][i][j + (m & 1)], 2ll * (i - 1) * dp[m][i - 1][j] % mod);
      }
    for(int ii = 1; ii < i; ii++) {
      if(i - ii - 1 <= 0) continue;
      for(int j = 0; j <= ii / 2; j++) {
        for(int jj = 0; jj <= (i - ii - 1) / 2; jj++) {
          for(int m = 0; m < 2; m++) {
            for(int m2 = 0; m2 < 2; m2++) {
              int ans = 1ll * C(i - 1, ii) * ii * (i - ii - 1) % mod;
              ans = 1ll * ans * dp[m][ii][j] % mod;
              ans = 1ll * ans * dp[m2][i - ii - 1][jj] % mod;
              if(!ans) continue;
              int new_mask = 1;
              if((m & 1) | (m2 & 1)) new_mask = 0;
              int a = (m & 1) | (m2 & 1);
              add(dp[new_mask][i][jj + j + a], ans);
            }
          }
        }
      }
    }
    for(int j = 0; j < i; j++)
      for(int m = 0; m < 2; m++)
        div2(dp[m][i][j]);
  }
  int n, k; scanf("%d %d", &n, &k);
  int ans = 0;
  for(int i = 0; i < 2; i++) {
    ans += dp[i][n][k];
    if(ans > mod) ans -= mod;
  }
  printf("%d\n", ans);
  return 0;
}
