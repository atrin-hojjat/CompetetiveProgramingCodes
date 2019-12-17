#include <bits/stdc++.h>
using namespace std;

/* Start : 7:35 */

struct Segment { 
  static const int Max = 1e5 + 6.66;
  struct Node {
    int cnt [ 26 ] ;
    int shift = 0;
    
    Node ( ) { memset ( cnt,0,sizeof cnt ) ; };
    Node ( Node l,Node r ) {
      for ( int i = 0;i<26;i++ ) cnt[i] = l.cnt[i] + r.cnt[i] ;
    }
    void clear ( ) { memset ( cnt, 0 ,sizeof cnt ) ; } ;
  } * nodes ;
  char _str_ [ ( size_t ) ( 1e5+6.66 ) ] ;
  int ans [ 26 ];
  int tmp [ 26 ];
  int _str_len_ = 0;
  
  Segment ( ) { 
    nodes = new Node [ 4 * Max ] ( ) ;
    _str_len_ = 0;
    build ( ) ;
  }

  Segment ( string str ) {
    nodes = new Node [ 4 * Max ] ( ) ;
    make_string ( str );
  }

  void make_string ( string str) {
    memset ( _str_,0,sizeof _str_) ;
    int I = 0;
    for ( auto w : str ) _str_[I++] = w;
    _str_len_ = str.size ( ) ;
    build ( ) ;
  }

  void shift ( int id,int l,int r ) {
    if ( !nodes[id].shift ) return ;
    int sz1 = ( r - l ) /2;
    int sz2 = r - l - sz1 ;
    Node*ln = &nodes [id<<1];
    Node*rn = &nodes [id<<1|1];
    if ( nodes[id].shift == 2 ) swap ( sz1,sz2 ) ,swap ( ln,rn ) ;
    ln->shift = rn->shift = nodes[id].shift ;
    for ( int i = 0;i<26;i++ ) {
      int x = min ( sz1 ,  nodes[id].cnt[i] );
      sz1 -= x;
      ln->cnt[i] = x;
      rn->cnt[i] = nodes[id].cnt[i] - x ;
    }
    nodes[id].shift = 0;
  }

  void build ( int id = 1,int l = 0,int r = Max ) {
    if ( l >= r ) return ;
    if ( r - l == 1 ) {
      nodes[id] = Node ( ) ;
      if ( l < _str_len_ ) nodes[id].cnt[_str_[l] - 'a'] ++;
      return ;
    }
    int mid = l + ( r - l ) /2 ;
    build ( id<<1,l,mid ) ;
    build ( id<<1|1,mid,r  ) ;
    if ( mid < r ) nodes[id] = Node ( nodes[id<<1],nodes[id<<1|1] ) ;
    else nodes[id] = nodes[id<<1];
  }

  void get ( int id,int l,int r ,int b,int e ) {
    if ( l>= r ) return ;
    if ( l >= e || r <= b ) return ;
    if ( l >= b && r <= e ) {
      for ( int i = 0;i<26;i++ ) ans[i] += nodes[id].cnt[i] ;
      return ;
    }
    shift ( id ,l,r ); /* */
    int mid = l + ( r - l ) /2 ;
    get ( id<<1 ,l,mid, b,e );
    get ( id<<1|1,mid,r,b,e);
  }

  void get ( int l, int r ) {
    memset ( ans, 0 ,sizeof ans ) ;
    get ( 1,0,Max,l,r ) ;
  }

  int* alt ( int id,int l,int r ,int b,int e ,int * it ,int *be ,bool rev ) {
    if ( l >= r ) return it;
    if ( l >= e || r <= b ) return it;
    if ( l >= b && r <= e ) {
      nodes[id].clear ( ) ;
      int len = r - l;
      while ( len ) {
        int xx = min ( len,*it );
        nodes[id].cnt[ rev ? 25 - ( it - be ) : it - be ] += xx;
        *it -= xx,len -= xx;
        if ( it - be < 25 && !*it ) it ++ ;
      }
      nodes[id].shift = ( int ) rev + 1;
      return it;
    }
    shift ( id,l,r );
    int mid = l + ( r - l ) /2 ;
    it = alt ( id<<1,l,mid,b,e ,it,be,rev);
    it = alt ( id <<1|1,mid,r,b,e ,it,be,rev) ;
    for ( int i = 0;i<26;i++ ) nodes[id].cnt[i] = nodes[id<<1].cnt[i] + nodes[id<<1|1].cnt[i] ;
    return it;
  }

  bool check ( int l ,int r ) {
    int ss = 0;
    for ( int i = 0;i<26;i++ ) ss += ans[i]%2 ;
    if ( ss == ( l + r ) % 2 ) return true;
    return false;
  }

  void alt ( int l,int r ) {
    get ( l , r );
    if ( ! check ( l ,r ) ) return ;
    int sum = 0;
    for ( int i = 0;i<26;i++ ) sum += ans[i] ;
    for ( int i = 0;i<26;i++ ) tmp[i] = ans[i] /2 ;
    alt ( 1,0,Max,l,l + ( r - l ) /2 ,&tmp[0],&tmp[0] ,0) ;
    if ( ( r + l ) % 2 ){
      memset ( tmp ,0,sizeof tmp );
      for ( int i = 0;i<26;i++ )
        if ( ans[i] % 2 ) {
          tmp[i] = 1;
          alt ( 1,0,Max,l + ( r- l )/2,l + ( r - l + 1 )/2,&tmp[0],&tmp[0],0 ) ;
        }
    }
    for ( int i = 0;i<26;i++ ) tmp[i] = ans[i] / 2;
    for ( int i = 0;i<13;i++ ) swap ( tmp[i],tmp[25-i] ) ;
    alt ( 1, 0,Max,l + ( r - l + 1) /2,r,&tmp[0],&tmp[0] ,1) ;
  }

  void buildstr ( int id = 1,int l = 0,int r = Max ) {
    if ( l >= r ) return ;
    if ( r - l == 1 ) {
      if ( l < _str_len_ )
        for ( int i = 0;i<26;i++ ) if (nodes[id].cnt[i] ) { _str_[l] = 'a' + i ; break ; }
      return ;
    }
    shift ( id,l,r ) ;
    int mid = l + ( r - l ) / 2;
    buildstr ( id<<1,l,mid ) ;
    buildstr ( id<<1|1,mid,r ) ;
  }
} seg;

int main ( ) {
#ifdef Atrin
  ios::sync_with_stdio ( false );
  cin.tie ( NULL ) ,cout.tie ( NULL ) ;
#else
  freopen ( "input.txt","rt",stdin );
  freopen ( "output.txt","wt",stdout );
#endif
  int N,M; cin >> N >> M ;
  string str; cin >> str;
  seg.make_string ( str ) ;
  while ( M -- ) {
    int l,r;cin >> l >> r ;
    l -- ;
    seg.alt ( l ,r );
  }
  seg.buildstr ( );
  for ( int i = 0;i<N;i++ ) cout << seg._str_[i] ;
  cout << endl;
  return 0;
}
