#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 5 + 1;
const long long mod = 1e9 + 7;
int cnt[3] ;
long long dp[2][2],dp1[2][2];

long long bpow ( long long base,long long exp ) {
  if ( exp < 0 ) return 0;
  long long ans = 1;
  for ( ; exp; exp >>= 1, base = base * base % mod )
    if ( exp & 1 ) ans = ( ans * base ) % mod;
  return ans;
}

void init_fact ( ) {
  fact[ 0 ] = 1;
  for ( int i = 1;i<MAXN;i++ ) fact[i] = fact[i-1] * i % mod;
  ifact [ MAXN - 1 ] = bpow ( fact[MAXN - 1], mod - 2 );
  for ( int i = MAXN-2;i>-1;i--) ifact[i] = ifact[i + 1] * ( i + 1 ) % mod;
}

long long C ( int n,int r ) {
  if ( n > r || r < 0) return 0;
  return ( fact [ n ] * ifact [ r ] % mod ) * ifact [ n - r ] % mod;
}

int main ( ) {
  int n,p;cin >> n >> p;
  for ( int i = 0;i<n;i++ ) {
    int x;cin >> x; cnt [x + 1] ++ ; }
  init_fact ( ) ;
  long long Ans = 0;
  for ( int f = 0;f<=cnt[0];f++ )
    for ( int s = 0;s <= cnt[1];s ++ ) {
      memset ( dp,0,sizeof dp );
      dp[0][0] = 1;bool prv = 0;
      long long ans[2] = {0,0};
      for ( int i = 0;i<f;i++ ) {
        bool now = !prv ;
        dp[now][0] = dp[now][1] = 0;
        dp[now][0] = bpow ( 2, s ) * ( 
            ( cnt[1] == s ? 1 : bpow ( 2 , cnt[1] - s - 1 ) ) * dp[prv][0] % mod +
            ( cnt[1] == s ? 0 : bpow ( 2 , cnt[1] - s - 1 ) ) * dp[prv][1] % mod) % mod;
        dp[now][1] = bpow ( 2, s ) * ( 
            ( cnt[1] == s ? 1 : bpow ( 2, cnt[1] - s - 1 ) ) * dp[prv][1] % mod +
            ( cnt[1] == s ? 0 : bpow ( 2, cnt[1] - s - 1 ) ) * dp[prv][0] % mod ) % mod;
        prv = now;
      }
    }
  return 0;
}
