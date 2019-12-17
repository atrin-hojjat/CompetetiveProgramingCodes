#include <bits/stdc++.h>
using namespace std;

/* Start : 9 : 07 */

struct Segment {
  static const int Max = 1e5 + 6.66;
  long long seg [ ( int ) ( 4 * ( 1e5 + 6.66 ) ) ];

  Segment ( ) { memset ( seg,0,sizeof seg ) ; }

  long long get ( int id,int l,int r ,int p ) {
    if ( l >= r ) return 0;
    if ( r - l == 1 ) return seg[id] ;
    int mid = l + ( r - l ) /2;
    if ( p < mid ) return seg[id] + get ( id<<1,l,mid,p ) ;
    else return seg[id] + get ( id<<1|1,mid,r,p ) ;
  }

  long long get ( int x ) { return get ( 1,0,Max,x ) ; }

  void add ( int id,int l,int r ,int b,int e ,long long d ) {
    if ( l>=r ) return;
    if ( l >= e || r <= b ) return ;
    if ( l >= b && r <= e ) {
      seg[id] += d;
      return ;
    }
    int mid = l + ( r - l ) /2;
    add ( id<<1,l,mid,b,e,d );
    add ( id<<1|1,mid,r,b,e,d ) ;
  }

  void add ( int l,int r ,long long d ) {
    add ( 1,0,Max,l,r,d ) ;
  }
} s1,s2 ;

struct Query {
  int l,r;long long d;
  Query ( ) { l = r = d = 0; };
  Query ( int l,int r,long long d ) : l ( l ), r ( r ) ,d ( d ) { } ;
} queries [ ( int ) ( 1e5 + 6.66 ) ] ;

const int MAXN = 1e5 + 6.66;
long long arr [ MAXN ] ;

int main ( ) {
  int n,m,k; scanf ( "%d %d %d" ,&n, &m ,&k ) ;
  for ( int i = 0;i<n;i++ ) scanf ( "%lld" , arr + i );
  for ( int i = 0;i<m;i++ ) scanf ( "%d %d %lld",&queries[i].l,&queries[i].r,&queries[i].d ) ;
  for ( int i = 0;i<k;i++ ) {
    int x,y; scanf ( "%d %d",&x,&y ) ;
    x--;
    s2.add ( x,y , 1 ) ;
  }
  for ( int i = 0;i<m;i++ )
    s1.add ( queries[i].l-1,queries[i].r,s2.get ( i ) * queries[i].d ) ;
  for ( int i = 0;i<n;i++ ) printf ( "%lld%c",arr[i] + s1.get ( i ) ," \n"[i == n-1] ) ;
  return 0;
}

