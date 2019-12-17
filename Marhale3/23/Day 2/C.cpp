#include <bits/stdc++.h>
using namespace std;

const int mod = 10883;
const int MaxN = mod;
const int delta = mod;
int ans[MaxN][200 + 2];
int dp[MaxN][200 + 2];
int fact[MaxN];
int ifact[MaxN];

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * base * ans % mod;
  return ans;
}

void prep() {
  fact[0] = 1;
  for(int i = 1; i < MaxN; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
  ifact[MaxN - 1] = _pow(fact[MaxN - 1], mod - 2);
  for(int i = MaxN - 1; i > 0; --i) ifact[i - 1] = 1ll * ifact[i] * i % mod;
}

int C(int n, int r) {
  if(n < r || r < 0) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int& add(int&x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int DP(int N, int K) {
  dp[1][0] = ans[1][0] = 1;
  for(int i = 1; i <= K; i++) ans[1][i] = 1;
  for(int i = 2; i <= N; i++) {
    for(int j = i; j > 1; j--) {
      for(int k = 1; k <= K; k++)
        add(ans[i][k], 1ll * ans[i - j + 1][k] * ans[j - 1][k - 1] % mod * C(i - 2, j - 2) % mod);
    }
//    for(int k = 1; k <= K; k++)
//      add(ans[i][k], ans[i][k - 1]);
  }
  return ans[N][K];
}

int tot_bc(int N, int k) {
  int perm[N - 1];
  int time[N - 1];
  for(int i = 0; i < N - 1; i++) perm[i] = i;
  int Ans = 0;
  do {
    int mmx = 0;
    for(int i = 0; i < N - 1; i++) {
      int mx = 0;
      for(int j = i - 1; j > -1; --j) {
        if(perm[i] < perm[j]) break;
        mx = max(time[j], mx);
      }
      time[i] = mx + 1;
      mmx = max(time[i], mmx);
    }
    if(mmx <= k) {
      (Ans += 1) %= mod;
    }
  } while(next_permutation(perm, perm + N - 1));
  return Ans;
}

int main() {
  int N, k; cin >> N >> k;
  if(N == -1) {
    k = 200;
    N = delta / 10;
  }
  prep();
  cout << _pow(DP(N, k), 3) << endl;
  if(N < 12) {
    int xx = tot_bc(N, k);
    cout << xx << endl;
    xx = 1ll * xx * xx % mod * xx % mod;
    cout << xx << endl;
  }
  return 0;
}
