#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 500 + 50 + 5;
long long arr [MAXN];
int sum [ MAXN ];
int ans [ MAXN ];

bool ok ( int x,int y ) {
  if ( ( arr [ x ] ^ arr [ y ] ) & ( 1LL << 63 ) ) return false;
  long long ws = sqrt ( 1LL * arr[x] * arr[y] );
  if ( ws * ws == arr[x] * arr[y] ) return true;
  return false;
}

int main ( ) {
  int n; scanf ( "%d" , &n );
  for ( int i = 0;i<n;i++ ) scanf ( "%lld",arr + i ) ;
  for ( int i = 0;i<n;i++ ) {
    if ( arr[i] ) sum [ i ] = 1;
    for ( int j = i - 1;arr[i] && j>-1;j-- )
      if ( arr[j] && ok ( i,j ) ) { sum [j] --; break ; };
    int ss = 0;
    for ( int j = i;j>-1;j-- ) 
    {
      ss += sum [ j ] ;
      if ( ss == 0 ) ans[1] ++;
      else ans [ ss ] ++ ;
    }
  }
  for ( int i = 1;i<=n;i++ ) printf ( "%d ", ans [i] ) ;
  printf ("\n" );
  return 0;
}
