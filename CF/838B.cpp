#include <bits/stdc++.h>
using namespace std;

struct Bit {
  const int Mx = 2 * ( 2e5 + 6.66 ) ;
  long long bit [ (int) 4e5 + 18 ] ;

  Bit ( ) { memset ( bit,0 , sizeof bit ) ; };

  void alter ( int x , long long y ) {
    while ( x < Mx )
      bit [x] += y, x += x & - x;
  }

  long long get_single ( int x ) {
    long long sum = bit[x] ;
    if ( x == 1 ) return sum;
    return sum - get ( x - 1 ) ;
  }

  long long get ( int x ) {
    long long ans = 0;
    while ( x ) ans += bit[x], x ^= x&-x;
    return ans;
  }
} par;

struct Segment {
  const int Mx = 4 * ( 2e5+6.66 );
  long long* seg;
  long long* lez;
  long long inf = 1e16 + 6.66;;
  int N ;
  
  Segment ( ) { 
    seg = new long long [ Mx ] ();
    lez = new long long [ Mx ] () ;
    fill ( lez,lez + Mx, 0 );
    fill ( seg, seg + Mx , inf );
    N = Mx/4 ;
  }
  
  Segment ( int N ) : N ( N ) {
    seg = new long long [ 4 * N + 2] ( ) ;
    lez = new long long [ 4 * N + 2] ( ) ;
    fill ( lez,lez + N + 2, 0 );
    fill ( seg,seg + N + 2, inf);
  }

  void shift ( int id,long long val ) {
    lez[id] += val;
    seg[id] += val;
  }

  void shift ( int id ) {
    if ( lez[id] == 0 ) return ;
    shift ( id <<1 , lez[id] );
    shift ( id <<1 |1 , lez [id] );
    lez[id] = 0;
  }

  void alter ( int x,long long val ) {
    alter ( 1, 1, N + 1,x,val );
  }

  void alter ( int id, int st,int en,int x,long long val ) {
    if ( st >= en ) return ;
    if ( st > x || en <= x ) return ;
    if ( en - st == 1 ) {
      seg[id] = val ;
      return ;
    }
    shift ( id );
    int mid = st + ( en - st ) /2 ;
    alter ( id << 1 , st, mid, x,val );
    alter ( id << 1 | 1 , mid, en, x,val );
    seg[id] = min ( seg[id<<1],seg[id<<1|1] );
  }

  void add ( int l,int r ,long long val ) {
    add ( 1 , 1 , N + 1, l ,r , val ) ;
  }

  void add ( int id,int l,int r,int b,int e ,long long val) {
    if ( l >= r ) return ;
    if ( l >= e || r <= b ) return ;
    if ( l >= b && r <= e ) {
      shift ( id, val );
      return;
    }
    shift ( id ) ;
    int mid = l + ( r - l ) /2;
    add ( id <<1,l,mid,b,e,val );
    add ( id<<1|1,mid,r,b,e,val ) ;
    seg[id] = min ( seg[id<<1],seg[id<<1|1] );
  }

  long long get ( int l,int r ) {
    return get ( 1 , 1, N + 1, l, r );
  }

  long long get ( int id,int l,int r,int b,int e ) {
    if ( l >= r ) return inf;
    if ( l >= e || r <= b ) return inf;
    if ( l >= b && r <= e ) return seg[id];
    shift ( id );
    int mid = l + ( r - l ) /2;
    return min ( get ( id<<1,l,mid,b,e ), get ( id<<1|1,mid,r,b,e ) ) ;
  }
} seg;

const int MAXN = 2e5+6.66;
vector<pair<int,long long>> children [MAXN];
pair<pair<int,int>,long long> eds [ MAXN * 2 ];
long long dist [ MAXN ];
long long up[MAXN];
int st [MAXN];
int et [MAXN];
int sst[MAXN] ;
int eet[MAXN];
int h[MAXN];
int now = 1;
int now2 = 1;

void dfs ( int v ,long long dis = 0,int H = 0,int par = 0) {
  st[v] = now ++;
  sst[v] = now2 ++;
  h[v] = H+1;
  dist [v] = dis;
  for ( auto w : children[v] ) 
    if ( w.first != par )
      dfs ( w.first, w.second,H+1,v) ;
  et[v] = now;
  eet[v] = now2 ++ ;
}

int main () {
  int n ,Q; scanf ( "%d %d",&n,&Q ) ;
  for ( int i = 1;i<n;i++ ) {
    long long w;
    int x,y; scanf ( "%d %d %lld" ,&x,&y,&w );
    eds [i] = { { x,y } , w };
    children [ x ] .push_back ( { y , w } ) ;
    children [ y ] .push_back ( { x , w } ) ;
  }
  dfs ( 1 ) ;
  for ( int i = 1;i<n;i++ ) {
    long long w;
    int x,y; scanf ( "%d %d %lld" , &x,&y,&w ) ;
    eds[i + n - 1] = { { x, y } , w } ;
    up[ x == 1 ? y : x ] = w;
  }
  for ( int i = 1;i<=n;i++ ) 
    par.alter ( sst[i], dist[i] ) ,par.alter ( eet[i],-dist[i] ); 
  for ( int i = 1;i<=n;i++ )
    seg.alter ( st[i], par.get ( sst[i] ) + up[i] ) ;
  while ( Q -- ) {
    int t; scanf ( "%d" , &t ) ;
    if ( t == 1 ) {
      int id;long long w;
      scanf ( "%d %lld" , &id,&w ) ;
      int i = id;
      long long altval = w - eds[id].second ;
      eds[id].second += altval;
      if ( id < n ) {
        int v = h[eds[i].first.first] > h[eds[i].first.second] ? eds[i].first.first : eds[i].first.second;
        par.alter (
            sst[v],altval ) ;
        par.alter (
            eet[v],-altval ) ;
        seg.add ( st[v],et[v],altval ) ;
      } else {
        int v = eds[id].first.first == 1 ? eds[id].first.second : eds[id].first.first ;
        seg.add ( st[ v ] ,st[v] + 1, altval);
      }
    } else {
      int u,v;
      scanf ( "%d %d", &v,&u ) ;
      if ( st[v] <= st[u] && et[v] >= et[u] ) {
        printf ( "%lld\n",(long long ) par.get(sst[u]) - par.get ( sst[v] ) );
        continue;
      }
      long long ans = seg.get ( st[v],et[v] ) - par.get ( sst[v] ) + par.get ( sst[u] ) ;
      printf ( "%lld\n",ans ) ;
    }
  }
  return 0;
}
