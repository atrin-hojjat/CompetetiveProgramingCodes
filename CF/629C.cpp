#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
const int MAX = 2000 + 200 + 20 + 2;
const long long mod = 1e9 + 7;
long long fact [ MAXN ];
long long ifact [ MAXN ] ;
long long inverse [ MAXN ] ;
long long dp [ MAX ] [ 2 * MAX ] ;

long long bpow ( long long base, long long exp ) {
  long long ans = 1;
  for ( ; exp ; exp >>= 1,base = base * base % mod ) 
    if ( exp & 1 ) ( ans *= base ) %= mod;
  return ans;
}

long long inv ( long long x ) { return bpow ( x , mod - 2 ) ; }

void init_fact ( ) {
  fact[0] = 1;
  for ( int i = 1;i<MAXN;i++ ) fact[i] = ( fact[i-1] * i ) % mod ;
  ifact[MAXN-1] = inv ( fact[MAXN -1] );
  for ( int i = MAXN - 2;i>-1;i-- ) fact[i] = ( fact[ i + 1 ] * ( i + 1 ) ) %mod ;
  for ( int i = 1;i<MAXN;i++ ) inverse [ i ] = inv ( i ) ;
}

long long C ( int n,int r ) {
  if ( r > n ) return 0;
  return ( fact [ n ] * ifact [ r ] % mod ) * ifact [ n - r ] % mod;
}

long long get_valids ( int len ) {
  return inv ( len - 1 ) *  C ( len * 2 , len ) % mod;
}


int main ( ) {
  ios::sync_with_stdio ( false ) ;
  cin.tie ( NULL ) ,cout.tie ( NULL ) ;
  int n,m;cin >> n >> m;
  string str;cin >> str;
  int out1 = 0,out2 = 0;
  init_fact ( ) ;
  for ( int i = 0;i<m;i++ ) out1 += ( str[i] == '(' ? 1 : ( out1 ? -1 : 0 ) ) ;
  for ( int i = m-1;i>-1;i-- ) out2 += ( str[i] ==')' ? 1 : ( out2 ? -1 : 0 ) ) ;
  if ( out1 + out2 > n - m ) { cout << 0 << endl; return 0 ; } 
  dp[0][0] = 1;
  for ( int len = 0;len <=n - m ;len ++) 
    for ( int out = 0;out < 2 * MAX - 1;out ++ )
      dp[len+1][out] = ( dp[len + 1][out] + dp[len][out + 1] + ( out > 0 ? dp[len][out-1] : 0 ) ) % mod ;
  long long ans = 0;
  for ( int l1 = 0;l1<=n-m;l1++ ) 
    for ( int bet = 0;bet<=l1;bet++ )
      ( ans += ( dp[l1][bet + out2] * dp[n-m-l1][bet + out1] ) % mod ) %= mod;
  cout << ans << endl;
  return 0;
}
