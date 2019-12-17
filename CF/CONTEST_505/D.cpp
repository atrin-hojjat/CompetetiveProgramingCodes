#include <bits/stdc++.h>
using namespace std;

const int MaxN = 700 + 70 + 7;
bool can_connect[MaxN][MaxN];
bool dp[MaxN][MaxN];
int arr[MaxN];

int gcd(int x, int y) {
  return x == 0 ? y : gcd(y % x, x);
}

bool can(int i, int j) { return can_connect[i][j]; }

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  for(int i = 0; i < n; i++) 
    for(int j = 0; j < n; j++) can_connect[i][j] = (gcd(arr[i], arr[j]) > 1);
  for(int i = 0; i < n; i++) dp[i][i] = 1;
  for(int len = 2; len <= n; len++) {
    for(int i = 0; i < n; i++) {
      for(int j = 1; j < len; j++) {
        if(i >= len - 1 && i - j > -1) dp[i - len + 1][i] |= can(i - j, i) && dp[i - len + 1][i - j] && dp[i - 1][i - j];
        if(i + len - 1 < n && i + j < n) dp[i + len - 1][i] |= can(i + j, i) && dp[i + len - 1][i + j] && dp[i + 1][i + j];
      }
    }
  }
  bool ans = false;
  for(int i = 0; i < n; i++) ans |= dp[0][i] && dp[n - 1][i];
  if(ans) printf("Yes\n");
  else printf("No\n");
  return 0;
}
