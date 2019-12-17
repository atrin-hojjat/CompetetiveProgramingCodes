#include <bits/stdc++.h>
using namespace std;

struct Segment {
  const int Max = 2e5 + 6.66 ;
  int seg [ ( int ) ( 2e5 + 6.66 ) * 4 ] ;

  Segment ( ) { memset ( seg, 0, sizeof seg ) ; };

  void add ( int id,int l,int r,int x,int y ) {
    if ( l >= r ) return ;
    if ( l > x || r <= x ) return ;
    if ( r - l == 1 ) { seg[id] = y; return ; }
    int mid = l + ( r - l ) /2 ;
    add ( id<<1,l,mid,x,y );
    add ( id<<1|1,mid,r,x,y );
    seg[id] = max ( seg[id<<1],seg[id<<1|1] ) ;
  }

  void add ( int x,int y ) {
    add ( 1,0,Max,x,y ) ;
  }

  int get ( int id,int l,int r,int x,int y ) {
    if ( l>=r ) return -1;
    if ( r <= x ) return -1;
    if ( r - l == 1 )
      return seg[id] > y ? l : -1 ;
    if ( seg[id] <= y ) return -1 ;
    int mid = l + ( r - l ) /2 ;
    int c = get ( id<<1,l,mid,x,y );
    if ( !~ c ) c = get ( id<<1|1,mid,r,x,y );
    return c;
  }

  int get ( int x,int y ) {
    return get ( 1,0,Max,x,y ) ;
  }
} seg;

struct Query {
  char t;
  int x,y;
} queries [ ( int ) ( 2e5 + 6.66 ) ];
const int MAXN = 2e5 + 6.66;
map<int,int> cmp ;
set<int> pnts[ MAXN ] ;
int cmprev [ MAXN ];

void compress ( int n ) {
  int I = 0;
  for (int i = 0;i<n;i++ ) cmp[queries[i].x] = 0;
  for ( auto & w : cmp ) cmprev[I] = w.first ,w.second = I++;
}

int main ( ) {
  ios::sync_with_stdio( false ) ;
  cin.tie ( NULL ),cout.tie ( NULL ) ;
  int n;cin >> n;
  for ( int i = 0;i<n;i++ ) {
    string str;cin >> str;
    int x,y;cin >> x >> y;
    queries[i].t = str[0];
    queries[i].x = x;
    queries[i].y = y;
  }
  compress ( n ) ;
  for ( int i = 0;i<n;i++ ) {
    Query&q = queries [i];
    if ( q.t == 'a' ) {
      if ( !pnts[cmp[q.x]].size ( ) ||
          q.y > *pnts[cmp[q.x]].rbegin ( ) ) seg.add ( cmp[q.x],q.y ) ;
      pnts[cmp[q.x]].insert ( q.y ) ;
    } else if ( q.t == 'r' ) {
      int mx = *pnts[cmp[q.x]].rbegin ( ) ;
      pnts[cmp[q.x]].erase ( pnts[cmp[q.x]].find ( q.y ) ) ;
      if ( mx == q.y ) {
        if ( pnts[cmp[q.x]].size ( ) ) seg.add ( cmp[q.x], *pnts[cmp[q.x]].rbegin ( ) );
        else seg.add ( cmp[q.x] , 0 );
      }
    } else {
      int xx = seg.get ( 1+cmp[q.x],q.y );
      if ( ~ xx ) cout << cmprev[xx] << " " << *pnts[xx].upper_bound( q.y ) << "\n";
      else cout << -1 << endl;
    }
  }
  return 0;
}
