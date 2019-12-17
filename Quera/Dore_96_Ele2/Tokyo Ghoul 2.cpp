#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 6.66;;
const int inf = 1e9+7;
int dp[1<<20];
int a[MAXN],b[MAXN],c[MAXN];
int seg1[MAXN];
int seg2[MAXN];
pair<int,int> CC[MAXN];
int par[MAXN];

int main() {
  int n;cin >> n;
  for(int i = 0 ;i<n;i++) cin >> a[i] >> b[i] >> c[i];
  if(n <= 20) {
    for(int i = 0;i<(1<<n);i++) dp[i] = inf;
    dp[0] = 0;
    for(int N = 0;N<(1<<n);N++) {
      int sum = 0;
      for(int i = 0;i<n;i++) if((N>>i) & 1) sum += a[i];
      for(int i = 0;i<n;i++) 
        if(!( (N>>i) & 1) ) {
          if(b[i] <= sum) dp[N | (1<<i)] = min(dp[N | (1<<i)] , dp[N]);
          else dp[N | (1<<i)] = min(dp[N | (1<<i)] , dp[N] + c[i]);
        }
    }
    cout << dp[(1<<n)-1] << endl;
  } else {
    for(int i = 0;i<n;i++) CC[i] = {a[i],c[i]};
    sort(CC,CC+n);
    par[0] = CC[0].first;
    for(int i = 1;i<n;i++) par[i] = par[i-1] + CC[i].first;
    int ans = inf;
    for(int i = 0;i<n;i++) {
      int j = i;
      while(j<n) {
        int sum = par[j];
        int idx = upper_bound(CC,CC+n,(pair<int,int>) {sum,inf})- CC;
        if(idx <=j+1) break;
        j= idx;
      }
      if(j >=n) ans = min(ans,CC[i].second);
    }
    cout << ans << endl;
  }
  return 0;
}
