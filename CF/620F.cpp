#include <bits/stdc++.h>
using namespace std;

struct Bit {
  const int Max = 5e4 + 6.66;
  long long bit [ ( int ) ( 5e4 + 6.66 + 10 ) ];
  
  Bit ( ) { memset (bit, 0,sizeof bit ) ; }

  void add ( int x , int y ) {
    while ( x < Max ) bit [x] += y, x += x&-x;
  }

  long long get ( int x ) {
    long long ans = 0;
    while ( x ) ans += bit [ x ] ,x ^= x & -x ;
    return ans;
  }
} bit [ 2 ] [ 2 ] [ 40 ];

const int MAXN = 5e4 + 6.66;
const int MAXM = 5e3 + 6.66;
const int MAX = 1e6 + 6.66;
const int SQ = 100 + 10 + 1;
int arr [ MAXN ];
int par [ MAX ];
int cmprev [ MAXN ] ;
long long Ans;
long long ans [ MAXM ] ;
map<int,int> cmp ;
struct Query {
  int l; int r;
  int II ;
  
  bool operator < ( Query x ) {
    return ( l/SQ == x.l/SQ ? ( l / SQ ) ^ ( r < x.r ) : l/SQ < x.l/SQ ) ;
  }
} queries [ MAXM ] ;

void compress ( int n ) {
  for ( int i = 1;i<=n;i++ ) cmp[arr[i]] = 0;
  int I = 1;
  for ( auto&w : cmp ) cmprev[I] = w.first,w.second = I++;
}

void add ( int x ) {
  for ( int i = 0 ;i<20;i++ ) {
    Ans += 1LL * ( 1LL << i ) * 
      bit [ 0 ] [ ( ( par[arr[x]] >> i ) & 1 ) ^ 1 ] [ i ] .get ( cmp [ arr[x] ] );
    Ans += 1LL * ( 1LL << i ) * ( bit [ 1 ] [ ( ( par[arr[x]-1] >> i ) & 1 ) ^ 1 ] [ i ] .get ( MAXN - 1 ) -
      bit [ 1 ] [ ( ( par[arr[x]-1] >> i ) & 1 ) ^ 1 ] [ i ] .get (cmp [ arr [ x ] ]) );
    bit [ 0 ] [ ( par[arr[x]-1] >> i ) & 1 ] [ i ] .add ( cmp[arr[x]], 1);
    bit [ 1 ] [ ( par[arr[x]] >> i ) & 1 ] [ i ] .add ( cmp[arr[x]], 1 );
  }
  Ans += arr[x] ;
}

void rem ( int x ) {
  Ans -= arr[x];
  for ( int i = 0;i<20;i++ ) {
    bit [ 0 ] [ ( par[arr[x]-1] >> i ) & 1 ] [ i ] .add ( cmp[arr[x]], -1 );
    bit [ 1 ] [ ( par[arr[x]] >> i ) & 1 ] [ i ] .add ( cmp[arr[x]], -1 );
    Ans -= 1LL * ( 1LL << i ) * 
      bit [ 0 ] [ ( ( par[arr[x]] >> i ) & 1 ) ^ 1 ] [ i ] .get ( cmp [ arr[x] ] );
    Ans -= 1LL * ( 1LL << i ) * ( bit [ 1 ] [ ( ( par[arr[x]-1] >> i ) & 1 ) ^ 1 ] [ i ] .get ( MAXN - 1) -
      bit [ 1 ] [ ( ( par[arr[x]-1] >> i ) & 1 ) ^ 1 ] [ i ] .get ( cmp [ arr [ x ] ] ) );
  }
}

int main ( ) {
  int n,m; scanf ( "%d %d",&n,&m );
  for ( int i = 1;i<=n;i++ ) scanf ( "%d" , arr + i ) ;
  compress ( n );
  for ( int i = 1;i<MAX;i++ ) par[i] = par[i-1] ^ i;
  for ( int i = 0;i<m;i++ ) queries[i].II = i;
  for ( int i = 0;i<m;i++ ) scanf ( "%d %d",&queries[i].l,&queries[i].r );
  for ( int i = 0;i<m;i++ ) queries[i].r++;
  for ( int i = 0 ;i<10;i++ ) cout << par [i] << " " ;cout << endl;
  auto __compare__ = [ ] ( Query a,Query x ) -> bool {
    return ( a.l/SQ == x.l/SQ ? ( a.l / SQ ) ^ ( a.r < x.r ) : a.l/SQ < x.l/SQ ) ;
  } ;
  sort ( queries,queries + m ,__compare__);
  int l = 1,r = 1;
  for ( int i = 0;i<m;i++ ) {
    int ll = queries [ i ] .l;
    int rr = queries [ i ] .r;
    while ( r < rr ) add ( r++ ) ;
    while ( l > ll ) add ( --l ) ;
    while ( r > rr ) rem ( --r ) ;
    while ( l < ll ) rem ( l++ ) ;
    ans [ queries[i].II ] = Ans ;
  }
  for ( int i = 0;i<m;i++ ) printf ( "%lld\n" , ans [ i ] );
  return 0;
}
