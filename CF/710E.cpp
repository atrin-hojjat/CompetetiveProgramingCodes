#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e7 + 6.66;
long long dp[MaxN];

int main() {
  memset(dp, 63, sizeof dp);
  int n;
  long long x, y;
  scanf("%d %lld %lld", &n, &x, &y);
  for(int i = 0; i < MaxN; i++) dp[i] = i * x;
  for(int i = 0; i < MaxN; i++) {
    for(int j = -1; j < 2; j++)
      if(i * 2 + j < MaxN) dp[i * 2 + j] = min(dp[i] + y + (j != 0) * x, dp[i * 2 + j]);
  }
  printf("%lld\n", dp[n]);
  return 0;
}
