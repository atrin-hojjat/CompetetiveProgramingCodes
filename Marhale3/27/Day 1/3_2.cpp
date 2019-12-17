#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5000 + 5000 + 500 + 50 + 5;
const int mod = 1e6 + 3;
int dp[MaxN][MaxN];

int& add(int& x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int main() {
  int n; cin >> n;
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++) dp[0][i] = 1, dp[1][i] = i;
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= n; j++) add(dp[i][j], dp[i - 1][j]);
    for(int j = 2; j <= n; j++) add(dp[i][j], dp[i][j - 1]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= n; j++) {
      add(ans, 1ll * dp[i][j - 1] * dp[n - i - 1][j] % mod);
    }
  }
  cout << ans << endl;
  return 0;
}
