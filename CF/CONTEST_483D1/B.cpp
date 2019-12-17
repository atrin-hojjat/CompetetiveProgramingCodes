#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 500 + 50 + 5;
const int MAXQ = 1e5 + 6.66;
int func[ MAXN ][ MAXN ];
int revmx [ MAXN ] [ MAXN ] ;
int ans [ MAXN ] [ MAXN ] ;
int a [ MAXN ];

int main ( ) {
  int n; scanf ( "%d", &n ) ;
  for ( int i = 0;i<n;i++ ) scanf ( "%d", a + i );
  for ( int i = 0;i<n;i++ ) func [ 1 ] [ i ] = a [ i ];
  for ( int len = 2;len<=n;len ++ ) 
    for ( int s = 0;s < n - len + 1; s++ )
      func [ len ] [ s ] = func [ len - 1 ] [ s ] ^ func [ len - 1 ] [ s + 1 ] ;
  for ( int i = 0; i<n; i++ ) {
    revmx [ i ] [ i ] = func [ 1 ] [ i ] ;
    for ( int j = i - 1; j>-1; j-- ) 
      revmx [ i ] [ j ] = max ( func [ i - j + 1 ] [ j ], revmx [ i ] [ j + 1 ] );
  }
  for ( int i = 0;i<n;i++ ) {
    ans [ i ] [ i ] = func [ 1 ] [ i ];
    for ( int j = i + 1; j < n; j++ ) 
      ans [ i ] [ j ] = max( ans [ i ] [ j - 1 ], revmx [ j ] [ i ] ) ;
  }
  int Q; scanf ("%d", &Q ) ;
  while ( Q-- ) {
    int l,r; scanf ( "%d %d", &l, &r ) ;
    l--,r--;
    printf ("%d\n", ans [ l ] [ r ] ) ;
  }
  return 0;
}
