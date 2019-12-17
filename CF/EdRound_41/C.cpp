#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10 + 1;
int dp[4][2];
char arr[MAXN][MAXN];

void solve(int n,char tab[MAXN][MAXN],int*d) {
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++) {
      d[0] += (((i + j ) % 2 + '0') == tab[i][j]);
      d[1] += (('1' - ( i + j ) % 2) == tab[i][j]);
    }
}

int main() {
  int n;cin >> n;
  for(int K = 0;K<4;K++) {
    for(int i = 0;i<n;i++) 
    {
      for(int j = 0;j<n;j++) cin >> arr[i][j];
    }
    solve(n,arr,dp[K]);
  }
  int ans = 1e9+7;
  ans = min(ans,dp[0][0]+dp[1][0] + dp[2][1] + dp[3][1] ) ;
  ans = min(ans,dp[0][0]+dp[1][1] + dp[2][0] + dp[3][1] ) ;
  ans = min(ans,dp[0][1]+dp[1][0] + dp[2][0] + dp[3][1] ) ;
  ans = min(ans,dp[0][0]+dp[1][1] + dp[2][1] + dp[3][0] ) ;
  ans = min(ans,dp[0][1]+dp[1][0] + dp[2][1] + dp[3][0] ) ;
  ans = min(ans,dp[0][1]+dp[1][1] + dp[2][0] + dp[3][0] ) ;
  cout << ans << endl;
  return 0;
}
