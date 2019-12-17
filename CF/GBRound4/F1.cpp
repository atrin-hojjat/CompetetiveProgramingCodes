#include <iostream>
using namespace std;

const int MaxN = 500 + 50 + 5;
const int mod = 998244353;
int dp[MaxN][MaxN];
pair<int, int> mn[MaxN][MaxN];
int dpe[MaxN];
int arr[MaxN];

int main() {
  int n; cin >> n;
  int m; cin >> m;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < n; i++)
  {
    mn[i][i] = {arr[i], i};
    for(int j = i + 1; j < n; j++)
      mn[i][j] = min(mn[i][j - 1], {arr[j], j});
  }
  for(int i = 0; i <= n; i++) dp[i][i] = 1;
  for(int len = 1; len <= n; len++) {
    for(int i = 0; i + len <= n; i++) {
      if(len == 1) {
        dp[i][i + 1] = 1;
        continue;
      }
      int j = i + len;
      int mp = mn[i][j - 1].second;
      int left = 0, right = 0;
      for(int k = i; k <= mp; k++) {
        (left += 1ll * dp[i][k] * dp[k][mp] % mod) %= mod;;
      }
      for(int k = mp + 1; k <= j; k++) {
        (right += 1ll * dp[mp + 1][k] * dp[k][j] % mod) %= mod;
      }
      dp[i][j] = 1ll * left * right % mod;
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}
