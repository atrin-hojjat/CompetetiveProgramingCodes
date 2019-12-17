#include <bits/stdc++.h>
using namespace std;

const int MaxN = 54 + 6.66;
const int mod = 10253;
const int delta = mod;
int dp[2][MaxN][MaxN][MaxN];

int& add(int&x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int& mul(int&x, int y) {
  x = 1ll * x * y % mod;
  return x;
}

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * ans * base % mod;
  return ans;
}

int main() {
  int c; cin >> c;
  long long N = 0;
  if(c == 0) cin >> N;
  else if(c == 1) N = delta + 2;
  else N = 1ll * delta * delta + 2;
  for(int i = 53; i > -1; i--) {
    if((N >> i) > 1) add(dp[1][i][1][i], 1);
    if((N >> i) == 1) add(dp[0][i][1][i], 1);
    for(int j = 1; j < 54; j++) {
      for(int k = i + 1; k < 54; k++) {
        add(dp[1][i][j][k], dp[1][i + 1][j - 1][k]);
        add(dp[1][i][j][k], dp[1][i + 1][j][k]);
        if((N >> i) & 1) add(dp[1][i][j][k], dp[0][i + 1][j][k]);
        add(dp[0][i][j][k], dp[0][i + 1][j - ((N >> i) & 1)][k]);
      }
    }
  }
  int ans = 0;
  for(int j = 1; j < 54; j++)
    for(int k = j - 1; k < 54; k++)
    {
      int c = dp[1][0][j][k];
      add(c, dp[0][0][j][k]);
      add(ans, mul(c, 1ll * _pow(3, j) * _pow(2, k - j + 1) % mod));
    }
  int inv2 = (mod + 1) / 2;
  int k = 1ll * N % mod * (N + 1) % mod * inv2 % mod;
  mul(ans, k);
  cout << ans << endl;
  return 0;
}
