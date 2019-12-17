#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 6.66;
vector<int> tree [ MAXN ] ;
vector<int> Start [ MAXN ] ;
vector<int> End [ MAXN ] ;
pair<int, int> se [ MAXN ] ;
long long price [ MAXN ] ;
int root [ MAXN ] ;
long long thresh [ MAXN ];
int h [ MAXN ] ;
multiset<pair<long long,int>> prs [ MAXN ];
long long TotalPrice = 0;

int get_root ( int v ) { return ( root[v] ? root[v] = get_root( root[v] ) : v ) ; }

void merge ( int v, int u ) {
  int rv = get_root ( v ) ;
  int ru = get_root ( u ) ;

  if ( rv == ru ) return ;
  if ( prs[rv].size ( ) < prs[ru].size ( ) ) swap ( rv, ru ) ;
  root[ru] = rv;

  auto it = prs[rv] .begin ( ) ;
  for ( auto x : prs[ru] ) 
    it = prs[rv].insert ( it
        , { ( price[ x.second ] = x.first + thresh[ru] - thresh[rv] ), x.second } ) ;
}

void erase_waste( int v ) {
  int rv = get_root( v ) ;

  for( auto x : End [ v ] ) {
    auto it = prs[rv].find ( { price[x], x} );
    if( it != prs[rv].end() ) prs[rv].erase( it ) ;
  }
}

void init_dfs( int v, int p, int hei ) {
  h[v] = hei;
  for ( auto u : tree[v] )
    if( u != p ) init_dfs( u, v, hei + 1 );
}

int dfs ( int v, int p ) {
  for ( auto x : Start[v] ) 
    prs [ v ] .insert ( {price[x], x} );

  int high = h[v];

  for ( auto u : tree [v] ) 
    if ( u != p ) {
      high = min( high, dfs( u, v ) ) ;
      merge(u,v);
    }

  erase_waste( v ) ;

  if( v > 1 && high >= h[v] ) {
    int rv = get_root( v ) ;
    if ( prs[rv].size ( ) == 0 ) { printf("-1\n"); exit ( 0 ) ;}
    auto it = prs[rv].begin ( ) ;
    int best_id = it->second ;
    long long pr = it->first ;
    it ++ ;
    while( it != prs[rv].end( ) && 
        it->first == pr ) {
      if( h[se[it->second].second] < h[se[best_id].second] ) best_id = it->second;
      it ++;
    }
    TotalPrice += thresh[rv] + pr;
    thresh[rv] = -pr;
    high = min( high,h[se[best_id].second] ) ;
    while ( prs[rv].size ( ) &&
        prs[rv].begin() -> first == pr ) prs[rv].erase(prs[rv].begin ( ) );
  }

  return high;
}

int main() {
  int n,m; scanf( "%d %d", &n, &m);
  for ( int i = 1;i<n;i++ ) {
    int x,y; scanf("%d %d", &x, &y);
    tree[x].push_back(y) ;
    tree[y].push_back(x) ;
  }
  init_dfs(1, 0, 0) ;
  for ( int i = 0;i<m;i++ ) {
    scanf("%d %d %lld",&se[i].first,&se[i].second,price + i ) ;
    Start[se[i].first].push_back( i );
    End[se[i].second].push_back( i ) ;
  }
  dfs(1,0);
  printf("%lld\n", TotalPrice);
  return 0;
}
