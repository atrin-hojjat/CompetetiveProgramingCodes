#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 200 + 20 + 2;
const int MAX = MAXN * MAXN;
const int mod = 1e9 + 7;
int fact[MAX];
int ifact[MAX];
int dp[MAXN][MAXN];

int bpow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1LL * base * base % mod )
    if(exp & 1) ans = 1LL * ans * base % mod;
  return ans;
}

void init() {
  fact[0] = 1;
  for(int i = 1; i < MAX; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
  ifact[MAX - 1] = bpow(fact[MAX - 1], mod - 2);
  for(int i = MAX - 1; i > 0; i--)
    ifact[i - 1] = 1LL * ifact[i] * i % mod;
}

int C(int n,int r) {
  if(n < r) return 0;
  return 1LL * (1LL * fact[n] * ifact[r] % mod) * ifact[n - r] % mod;
}

int& add(int&x, int s) {
  return x = (1LL * x + s) % mod;
}

int main() {
  init();
  int N,K; scanf("%d %d", &N, &K);
  if(K == 1) {
    printf("1\n");
    return 0;
  }
  dp[N][N] = 1;
  for(int i = N; i >= 0; i--)
  {
    for(int j = N; j > i; j--) 
    {
      add(dp[i][j-1], 1LL * dp[i][j] * C(i + (K - 1) * j - 1, K - 2) % mod);
      if(i) add(dp[i-1][j], dp[i][j]);
    }
    if(i) add(dp[i-1][i], dp[i][i]);
  }
  int ans = 1LL * dp[0][0] * fact[N] % mod;
  printf("%d\n", ans);
  return 0;
}
