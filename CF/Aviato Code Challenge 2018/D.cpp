#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 5;
long long arr[MAXN];
long long dp[MAXN][MAXN];

int main() {
  int n,k; scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) scanf("%lld", arr + i);
  long long suf = 0;
  for(int b = 60; b > -1; --b) {
    memset(dp, 0, sizeof dp);
    long long sum = 0;
    suf |= (1LL << b);
    for(int i = 0; i < n; i++)
    {
      sum = sum + arr[i];
      if((sum & suf) == suf) dp[0][i] = 1;
    }
    for(int j = 1; j < k; j++) {
      for(int i = j; i < n; i++) {
        sum = 0;
        for(int c = i; c >= j; --c)
        {
          sum += arr[c];
          if((sum & suf) == suf) dp[j][i] |= dp[j - 1][c - 1];
        }
      }
    }
    if(!dp[k - 1][n - 1]) suf ^= (1ll << b);
  }
  cout << suf << endl;
  return 0;
}
