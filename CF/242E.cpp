#include <bits/stdc++.h>
using namespace std;

struct Segment {
  struct Node {
    int valon = 0,valoff = 0;
    bool changed = 0;
    Node () { valon = valoff = 0 ;}
    Node ( int val ) : valon ( val ),valoff ( 1- val ) { };
    Node ( int valon,int valoff ) 
      : valon ( valon ), valoff ( valoff ) { };
    Node ( Node ln,Node rn ) {
      recalc ( ln,rn );
    }
    void recalc ( Node ln,Node rn ) {
      valon = ln.valon + rn.valon ;
      valoff = ln.valoff + rn.valoff;
    }
    void swap ( ) { ::swap ( valon,valoff ); changed = !changed ; }
  } *nodes ;

  int MAXN = 1e5 + 6.66;

  Segment( ) { 
    nodes = new Node [ 4 * MAXN ] ( );
    build_0 (  );
  }

  Segment (int * arr,int n ) {
    nodes = new Node [ 4 * MAXN ] ( );
    build ( 1, 0,MAXN,[arr,n] ( int i ) { return i>=n ? 0 : arr[i] ; } ) ;
  }

  Segment ( function <int( int ) > func ) {
    nodes = new Node [ 4 * MAXN ] ( );
    build ( 1, 0,MAXN,func ) ;
  }

  void build ( int id,int l,int r,function<int(int)> func ) {
    if ( l >= r ) { nodes[id] = Node () ; return ; };
    if ( r - l == 1 ) {
      nodes[id] = Node ( func ( l ) );
      return ;
    }
    int mid = l + ( r - l ) /2;
    build ( id<<1,l,mid,func);
    build ( id<<1|1,mid,r, func);
    nodes[id] = Node ( nodes[id<<1].valon + nodes[id<<1|1].valon,nodes[id<<1].valoff + nodes[id<<1|1].valoff ) ;
  }

  void build_0 ( ) {
    build ( 1,0,MAXN, [] (int x ) { return 0 ; } ) ;
  }

  void shift ( int id ) {
    if ( ! nodes[id].changed ) return ;
    nodes[id << 1].swap ();
    nodes[id << 1 | 1] . swap ();
    nodes[id].changed = 0;
  }

  void alter ( int id,int l,int r,int b,int e ) {
    if ( l >= r ) return ;
    if ( l >= e || r <= b ) return ;
    if ( l >= b && r <= e ) {
      nodes[id].swap () ;
      return ;
    }
    shift ( id ) ;
    int mid = l + ( r - l ) /2;
    alter ( id << 1, l, mid, b ,e );
    alter ( id << 1 | 1, mid, r, b , e );
    nodes[id].recalc ( nodes[id<<1],nodes[id<<1|1] ) ;
  }

  int get ( int id,int l,int r,int b,int e ) {
    if ( l >= r ) return 0;
    if ( l >= e || r <= b ) return 0;
    if ( l >= b && r <= e ) return nodes[id].valon ;
    shift ( id ) ;
    int mid = l + ( r - l ) /2;
    return get ( id << 1 , l,mid,b,e ) + get ( id <<1 | 1, mid, r, b , e ) ;
  }

  int get ( int b,int e ) { return get ( 1,0,MAXN , b ,e ) ; }
  void alter ( int b,int e ) { alter ( 1,0,MAXN, b, e ) ; }
} ;

const int MAXN = 1e5 + 6.66;
int arr[MAXN];
Segment segs [ 20 ];

int main () {
  int n;scanf ( "%d", &n ) ;
  for ( int i = 0;i<n;i++ ) scanf ( "%d",arr + i );
  for ( int i = 0;i<20;i++ )
    segs[i] = Segment ( [n,i] ( int x ) { return x >= n ? 0 : ( arr[x] >> i ) & 1 ; } ) ;
  int Q;scanf ( "%d", &Q );
  while ( Q -- ) {
    int t; scanf ( "%d" , & t ) ;
    if ( t == 1 ) {
      int l,r; scanf ( "%d %d" , &l , & r ) ;
      l --;
      long long ans = 0;
      for ( int i = 0;i<20;i++ )
        ans += ( 1LL << i ) * segs[i] . get ( l ,r  );
      printf ( "%lld\n" , ans ) ;
    } else { 
      int l,r,c; scanf ( "%d %d %d",&l,&r,&c );l--;
      for ( int i = 0;i<20;i++ )
        if ( ( c >> i ) & 1 ) 
          segs[i] .alter ( l, r ) ;
    }
  }
  return 0;
}
