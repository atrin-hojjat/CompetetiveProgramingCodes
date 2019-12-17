#include <bits/stdc++.h>
using namespace std;

struct Bit {
  const int Max = 3e5 + 12.66;
  long long bit [ ( int ) ( 1e5 + 6.66 ) * 3] ;

  Bit ( ) { memset ( bit,0,sizeof bit ) ; };

  void add ( int x,long long val ) {
    while ( x < Max ) 
      bit[x] += val, x+= x & -x;
  }

  long long get_par ( int x ) {
    long long ans = 0;
    while ( x ) ans += bit[x],x ^= x&-x ;
    return ans;
  }

  long long get_single ( int x ) {
    long long st = bit [ x ];
    int y = x - 1;x ^= x & -x ;
    if ( ! y ) return st ;
    while ( y > x ) st -= bit[y], y^= y&-y ;
    return st;
  }
} bit;

const int MAXN = 1e5 + 6.66;

int main ( ) {
  int n,q; scanf ( "%d %d", &n, &q ) ;
  for ( int i = MAXN + 2;i<=MAXN + n+1;i++ ) bit.add ( i,1 ) ;
  int L = n + 1 + MAXN ,R = 1 + MAXN, dir = -1;
  while ( q -- ) {
    int t; scanf ( "%d" , &t ) ;
    if ( t == 1 ) {
      int l; scanf ( "%d" , &l ) ;
      if ( l > n/2 ) {
        swap ( L,R ) ;
        dir *= -1;
        L+=dir,R+=dir;
        l = n - l;
      }
      for ( int i = 0;i<l;i++ ) 
        bit.add ( L + dir * ( 2 * l - i - 1) , bit.get_single ( L + dir * i ) ) ;
      L = L + dir * l;
      n -= l ;
    } else {
      int l,r ; scanf ( "%d %d",&l,&r ) ;
      long long ans = 0;
      if ( dir > 0 ) ans = bit . get_par ( L + r - 1 ) - bit . get_par ( L + l - 1 ) ;
      else ans = bit.get_par ( L - l ) - bit.get_par ( L - r ) ;
      if ( ans < 0 ) ans *= -1;
      printf ( "%lld\n" , ans ) ;
    }
  }
  return 0;
}
