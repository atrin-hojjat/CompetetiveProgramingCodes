#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5000 + 500 + 50 + 5;
int dp[2][MaxN / 2][MaxN];
int ans[MaxN / 2];
int arr[MaxN];

int main() {
  int N; scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", arr + i);
  memset(ans, 63, sizeof ans);
  int inf = ans[0];
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < MaxN / 2; j++)
      for(int k = 0; k < MaxN; k++) dp[i][j][k] = inf;
  dp[0][0][0] = dp[0][0][1] = 0;
  dp[arr[0] <= arr[1]][1][1] = max(0, arr[1] - arr[0] + 1);
  ans[1] = min({ans[1], dp[0][1][1], dp[1][1][1]});
  for(int i = 2; i <= N; i++) {
    dp[0][0][i] = 0;
    for(int j = 1; j <= (N + 1) / 2;j++) {
      dp[(arr[i - 1] <= arr[i])][j][i] = 
        min(max(0, arr[i] - arr[i - 1] + 1) + dp[0][j - 1][i - 2] + max(0, arr[i - 2] - arr[i - 1] + 1),
            max(0, arr[i] - arr[i - 1] + 1) + dp[1][j - 1][i - 2] + (i >= 3 ? max(arr[i - 3] - arr[i - 1], 0) : 0));
      dp[0][j][i] = min({dp[0][j][i - 1], dp[1][j][i - 1], dp[0][j][i]});
      ans[j] = min({ans[j], dp[0][j][i], dp[1][j][i]});
    }
  }
  for(int i = 1; i <= (N + 1) / 2; i++)
    printf("%d%c", ans[i], " \n"[i == (N + 1) / 2]);
  return 0;
}
