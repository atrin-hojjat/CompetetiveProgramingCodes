#include <iostream>
#include <cstring>
using namespace std;

const int MaxN = 3e5 + 6.66;
int a[MaxN], b[MaxN];
long long dp[4][MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int q; cin >> q;
  while(q--) {
    int n; cin >> n;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < 4; j++)
        dp[j][i] = 1ll * 3e18 + 6;
    
    for(int i = 0; i < n; i++)
      cin >> a[i] >> b[i];

    for(int i = 0; i < 4; i++)
      dp[i][0] = min(dp[i][0], 1ll * i * b[0]);

    for(int i = 1; i < n; i++) {
      for(int j = 0; j < 4; j++)
        for(int k = 0; k < 4; k++)
          if(j + a[i] != k + a[i - 1])
            dp[j][i] = min(dp[j][i], dp[k][i - 1] + 1ll * b[i] * j);
    }

    long long ans = 1ll * 3e18;
    for(int i = 0; i < 4; i++) ans = min(ans, dp[i][n - 1]);

    cout << ans << endl;

  }
  return 0;
}
