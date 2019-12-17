#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int Max = 20;
long long dp[2][5][Max + 1];
int C[Max];

void get(long long x) {
  memset(C, 0, sizeof C);
  for(int i = Max - 1; i > -1; i--) {
    C[i] = x % 10;
    x /= 10;
  }
}

long long count(long long x) {
  memset(dp, 0, sizeof dp);
  get(x);
  dp[0][0][0] = 1;
  for(int i = 0; i < Max; i++) {
    for(int c = 0; c < 4; c++) {
      dp[0][(C[i] > 0) + c][i + 1] += dp[0][c][i];
      dp[1][c][i + 1] += dp[1][c][i];
      if(C[i] > 0) dp[1][c][i + 1] += dp[0][c][i];
      dp[1][c + 1][i + 1] += 9ll * dp[1][c][i];
      if(C[i] > 0) dp[1][c + 1][i + 1] += (-1 + C[i]) * dp[0][c][i];
    }
  }
  long long ans = 0;
  for(int c = 0; c < 4; c++) ans += dp[0][c][Max] + dp[1][c][Max];
  return ans;
}

int main() {
  int T; scanf("%d", &T);
  while(T--) {
    long long L, R; scanf("%lld %lld", &L, &R);
    printf("%lld\n", count(R) - count(L - 1));
  }
  return 0;
}
