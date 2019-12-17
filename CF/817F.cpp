#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
const int MAX = MAXN << 2;
struct Query {
  int t;long long l,r ; 
} queries [ MAXN ];
map<long long,int> cmp;
map<int,long long> revcmp;

struct Segment {
  bool *seg;
  bool *sege;
  struct Lazy { 
    bool shift;bool val;bool rev;
    Lazy ( ) { rev = shift = val = 0; } 
    Lazy ( bool shift,bool val,bool rev ) : shift ( shift ), val ( val ) ,rev ( rev )  { }
  } *laz ;

  Segment ( int n ) {
    seg = new bool [ n * 4 + 10] () ;
    sege = new bool [ n * 4 + 10 ] () ;
    fill ( sege, sege + n * 4 + 10, true );
    laz = new Lazy [ n * 4 + 10] () ;
  }

  void shift1 ( int id, Lazy la ) {
    laz[id] = { la.shift,la.val, 0 };
    if ( la.val ) seg[id] = true,sege[id] = false;
    else sege[id] = true, seg[id] = false;
  }

  void shiftre ( int id,Lazy la ) {
    laz[id].rev = !laz[id].rev ;
    swap ( seg[id],sege[id] ) ;
  }

  void shift ( int id ) {
    if ( laz[id].shift ) {
      shift1 ( id << 1, laz[id] );
      shift1 ( id<< 1|1, laz [id] );
      laz[id] = {0,0,laz[id].rev };
    }
    if ( laz[id].rev ) {
      shiftre ( id << 1,laz[id] );
      shiftre ( id<< 1|1, laz[id] ) ;
      laz[id].rev = 0;
    }
  }

  void make ( int id,int l,int r ,int b,int e ,bool val) {
    if ( l >= r ) return ;
    if ( l >= e || r <= b ) return ;
    if ( l >= b && r <= e ) {
      laz[id] = { 1,val,0 };
      shift1 ( id, laz[id] );
      return ;
    }
    shift ( id ) ;
    int mid = l + ( r - l ) /2;
    make ( id <<1, l,mid, b,e ,val);
    make ( id <<1|1 ,mid ,r ,b ,e ,val);
    seg[id] = seg[id<<1] || seg[id<<1|1] ;
    sege[id] = sege[id<<1] || sege[id << 1|1 ];
  }

  void make_inverse ( int id,int l,int r ,int b,int e ) {
    if ( l >= r ) return ;
    if ( l>= e || r <= b ) return ;
    if ( l>=b && r <=e ) {
      shiftre ( id , { 0,0,1} );
      return ;
    }
    shift ( id ) ;
    int mid = l + ( r - l ) /2;
    make_inverse ( id<<1,l,mid,b,e );
    make_inverse ( id<<1|1,mid,r,b,e );
    seg[id] = seg[id<<1] || seg[id<<1|1] ;
    sege[id] = sege[id<<1] || sege[id << 1|1 ];
  }

  int find_first (int id,int l,int r ) {
    if ( r - l == 1 ) return l ;
    shift ( id ) ;
    if ( seg[id << 1] ) return find_first ( id<<1,l,l + ( r- l )/2 );
    else return find_first ( id<<1|1, l + ( r- l ) /2, r ) ;
  }

  void traverse ( int id,int l ,int r ) {
    if ( l >= r ) return ;
    if ( r - l == 1 ) { cout << l << " "<< seg[id] << "," << sege[id] <<endl;return ; }
    cout << l << " " << r << " " << seg[id] << " " << sege[id] << endl;
    shift ( id ) ;
    traverse ( id,l, l + ( r - l ) /2 );
    traverse ( id,l + ( r- l ) /2 , r );
  }
};

void compress (int n) {
  int I = 0;
  cmp[1] = cmp[1e18+1] = cmp[1e18+2] = 0;
  for( int i = 0;i<n;i++ ) cmp[queries[i].l] = cmp[queries[i].r+1] = 0;
  for( auto&w : cmp ) w.second = I++;
  for( auto w : cmp ) revcmp[w.second] = w.first ;
}

int main () {
  int n;scanf( "%d",&n );
  for (int i = 0;i<n;i++ ) scanf ( "%d %lld %lld",&queries[i].t,&queries[i].l,&queries[i].r);
  compress ( n ) ;
  Segment seg ( cmp.size () ) ;
  seg.make ( 1 , 0 , cmp.size () , 0 ,cmp.size () , 1 ) ;
  for ( int i = 0;i<n;i++ ) {
    int ll = cmp[queries[i].l],rr = cmp[queries[i].r+1];
    switch ( queries[i].t ) {
      case 1:
        seg.make ( 1 ,0 ,cmp.size () , ll, rr,0 );
        break;
      case 2:
        seg.make ( 1 ,0,cmp.size() ,ll,rr,1 );
        break;
      case 3:
        seg.make_inverse ( 1, 0,cmp.size(),ll,rr );
        break;
    }
    printf ("%lld\n", revcmp[seg.find_first ( 1, 0, cmp.size () )]) ;
  }
  return 0;
}
