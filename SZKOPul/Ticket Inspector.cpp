#include <bits/stdc++.h>
using namespace std;

const int MAXN = 666.66;
const int MAXK = 66.666;
long long nums [ MAXN ] [ MAXN ];
long long par [ MAXN ] [ MAXN ] ;
pair<long long,int> dp [ MAXK ] [ MAXN ] ;

int32_t main ( ) {
  int n,k; scanf ( "%d %d",&n,&k ) ;
  for ( int i = 1;i<=n;i++ )
    for ( int j = i + 1;j<=n;j++ ) 
      scanf ( "%lld", nums[i] + j ) ;
  for ( int i = 1;i<=n;i++ ) 
    for ( int j = n; j>-1;j-- )
      par[i][j] = nums[i][j] + par[i-1][j] + par[i][j+1] - par[i-1][j+1] ;
  for ( int i = 0;i<MAXK;i++ )
    for ( int j = 0;j<MAXN;j++ ) dp[i][j] = {0,-1};
  for ( int i = 1;i<=n;i++ )
    dp[1][i] = { par[i][i+1] , -1 } ;
  for ( int i = 2;i<=k;i++ ) 
    for ( int j = 1;j<n;j++ )
      for ( int w = 1;w<j;w ++ ) 
        dp[i][j] = max ( dp[i][j] , { par[j][j+1] + dp[i-1][w].first - par[w][j+1],w } );
  pair<long long,int> ans = { 0, 0 };
  vector<long long> v;
  for ( int i = 1;i<n;i++ ) ans = max ( ans, { dp[k][i].first,i } ) ;
  int i = ans.second ;
  int KK = k;
  while ( ~i ) {
    v.push_back ( i ) ;
    i = dp[KK--][i].second ;
  }
  sort ( v.begin ( ) ,v.end ( ) ) ;
  for ( auto w : v ) cout << w << " " ; cout << endl;
  return 0;
}
