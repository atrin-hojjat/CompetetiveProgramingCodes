#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100 + 10 + 1;
const int mod = 1e6 + 3;
int dp[MaxN][MaxN];

int&add(int&x) { return x; }

template<typename...T>
int&add(int&x, int y, T...t) {
  x += y;
  if(x >= mod) x -= mod;
  return add(x, t...);
}

int main() {
  int n, k; cin >> n >> k;
  dp[0][0] = 1;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j <= min(i, k); j++) {
      for(int c = i - 1; c >= max(0, i - j - 1); c--) {
        for(int d = j - (i - c - 1); d <= min(c, k); d++)
          add(dp[i][j], 1ll * dp[c][d] % mod);
      }
      if(i == j) add(dp[i][j], 1);
    }
  }
  int ans = 0;
  for(int i = 0; i <= k; i++) add(ans, dp[n - 1][i]);
  cout << ans << endl;
  return 0;
}
