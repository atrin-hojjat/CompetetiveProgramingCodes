#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3000 + 300 + 30 + 3;
const int mod = 1e9 + 7;
int dp[MaxN][MaxN];
int fact[MaxN];
int ifact[MaxN];
vector<int> children[MaxN];

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
  for(int i = MaxN - 1; i > 0; --i) ifact[i - 1] = 1ll * ifact[i] * i %mod;
}

void dfs(int v) {
  for(auto x : children[v]) dfs(x);
  for(int i = 1; i < MaxN; i++) dp[v][i] = 1;
  for(auto x : children[v]) {
    for(int i = 1; i < MaxN; i++)
      dp[v][i] = 1ll * dp[v][i] * dp[x][i] % mod;
  }
  for(int i = 1; i < MaxN; i++) dp[v][i] = (dp[v][i] + dp[v][i - 1]) % mod;
}

int C(int n, int r) {
  if(n < r) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main() {
  int n, D; scanf("%d %d", &n, &D);
  prep();
  for(int i = 1; i < n; i++) {
    int par; scanf("%d", &par);
    children[par].push_back(i + 1);
  }
  dfs(1);
  int factD = 1;
  int ans = 0;
  for(int i = 1; i <= min(n, D); i++) {
    factD = 1ll * factD * (D - i + 1) % mod;
    int xx = dp[1][i];
    for(int j = 1; j < i; j++) {
      int sign = (i - j) % 2 ? -1 : 1;
      xx = xx + sign * (1ll * dp[1][j] * C(i, j) % mod);
      if(xx < 0) xx += mod;
      else if(xx >= mod) xx -= mod;
    }
    ans = ans + 1ll * xx * factD % mod * ifact[i] % mod;
    if(ans >= mod) ans -= mod;
  }
  printf("%d\n", ans);
  return 0;
}
