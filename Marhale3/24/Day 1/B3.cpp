#include <bits/stdc++.h>
using namespace std;

const int mod = 10313;
const int delta = mod;
const int MaxN = 2e4 + 1;
int C[MaxN][MaxN];
int pi[MaxN];
int PP[MaxN][MaxN];

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * ans * base % mod;
  return ans;
}

int& add(int&x, long long y) {
  y %= mod;
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int& sub(int&x, long long y) {
  y %= mod;
  x -= y;
  if(x < 0) x += mod;
  return x;
}

int main() {
  int N = 20000;
  int M = 10000;
  int ans = _pow(M, N);
  int inv = _pow(M, mod - 2);
  pi[0] = 1;
  for(int i = 1; i < MaxN; i++) pi[i] = 1ll * pi[i - 1] * inv % mod;
  for(int i = 0; i < MaxN; i++) {
    PP[i][0] = 1;
    for(int j = 1; j < MaxN; j++)
      PP[i][j] = 1ll * PP[i][j - 1] * i % mod;
  }
  for(int j = 1; j <= N; j++)
  {
    for(int k = 1; k <= M; k++) {
      C[j][k] = 1ll * pi[j] * (M - k) * PP[k - 1][j - 1] % mod;
      add(C[j][k], C[j - 1][k]);
    }
  }
  for(int i = 1; i < N; i++) {
    for(int j = 1; j <= M; j++) {
      add(ans, 1ll * PP[M][N - i - 1] * PP[j - 1][i] + 1ll * C[i][j] * PP[M][N - 1]);
    }
  }
  cout << ans << endl;
  return 0;
}
