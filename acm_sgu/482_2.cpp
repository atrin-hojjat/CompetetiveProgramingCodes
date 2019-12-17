#include <bits/stdc++.h>
using namespace std;

const int MaxN = 50 + 6.66;
const int MaxH = 100 + 10 + 1;
const int MaxP = 2 * MaxN + MaxN * MaxH + MaxH;
pair<int, int> dp[MaxN][MaxP];
int H[MaxN];
int par[MaxN];
bool mark[MaxN];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", H + i);
  int P = 2 * n + H[0] + H[n - 1];
  for(int i = 1; i < n; i++) P += abs(H[i] - H[i - 1]);
  for(int i = 0; i < MaxN; i++)
    for(int j = 0; j < MaxP; j++) dp[i][j] = {-1, -1};
  for(int i = 0; i < n; i++) par[i] = H[i] + par[max(i - 1, 0)];
  for(int i = 0; i < n; i++) {
    dp[i][2 * H[i] + 2] = {i > 0 ? par[i - 1] : 0, -1};
    for(int p = 0; p < MaxP; p++) {
      for(int j = 0; j < i; j++) {
        int c = abs(H[i] - H[j]) - H[j];
        int pp = p - 2 - H[i] - c;
        if(pp >= 0 && pp < MaxP && dp[j][pp].first >= 0) 
          dp[i][p] = max(dp[i][p], {par[i - 1] - par[j] + dp[j][pp].first, j});
      }
    }
  }
  pair<int, pair<int, int>> ans = {-1, {-1, -1}};
  for(int i = 0; i < n; i++)
    for(int p = (P + 1) / 2; p < MaxP; p++) 
      if(dp[i][p].first >= 0) ans = max(ans, {dp[i][p].first + par[n - 1] - par[i], {i, p}});
  if(!~ans.first) {
    printf("0\n0\n");
    return 0;
  }
  printf("%d\n", ans.first);
  int rm = 0;
  pair<int, int> now = ans.second;
  while(~now.first) {
    rm++;
    mark[now.first] = true;
    int i = now.first;
    int p = now.second;
    int j = dp[i][p].second;
    int pp = p - H[i] - 2 - abs(H[i] - H[j]) + H[j];
    now = {j, pp};
  }
  printf("%d\n", n - rm);
  for(int i = 0; i < n; i++) if(!mark[i]) printf("%d ", i + 1);
  printf("\n");
  return 0;
}
