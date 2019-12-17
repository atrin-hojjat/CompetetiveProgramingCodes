#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5;
const int MAXX = 5 * 5;
const int mod = 22273;

int table [ MAXN + 10 ] [ MAXN + 10 ];
int ways [ MAXN + 10 ] [ MAXN  + 10 ];

int main ( ) {
  int cnt = 0;
  for ( int i = 0;i<( 1 << ( MAXX ) ) ;i ++ ) {
    if ( ! ( i & 1 ) || ! ( (i >> ( MAXX - 1 ) ) & 1 ) ) continue;
    for ( int j = 0;j<MAXN;j++ )
      for ( int k = 0;k<MAXN;k++ ) 
        table[j][k] = ways[j][k] = 0;
    for ( int j = 0;j<MAXN;j++ )
      for ( int k = 0;k<MAXN;k++ ) 
        table [j][k] = ( i >> ( j * MAXN + k ) ) & 1;
    ways[0][0] = 1;
    for ( int j = 0;j<MAXN;j++ )
      for ( int k = 0;k<MAXN;k++ ) 
        if ( table [j][k] ) {
          if ( table [ j + 1 ] [ k ] ) ways [ j + 1 ] [ k ] += ways [j][k];
          if ( table [ j ] [ k + 1 ] ) ways [ j ] [ k + 1 ] += ways [j][k];
        }
    if ( ways [ MAXN-1 ] [ MAXN-1 ] == 1 ) cnt = cnt + 1 ;
  }
  cout << cnt << " " << cnt % mod<< endl;
  return 0;
}
