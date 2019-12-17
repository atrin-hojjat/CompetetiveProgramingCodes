#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+6.66;
vector<int> graph[MAXN];
bool mark[MAXN];

void dfs ( int v , vector<int>& prv ,bool&OK,vector<int>&ans) {
  mark[v] = true;
  int pp = v;
  reverse ( prv.begin () , prv.end () );
  for ( auto w : prv )
    if ( * lower_bound ( graph[v].begin (), graph[v] .end () , w) != w ) {
      OK = true;
      ans = vector<int> ( {v,pp,w} );
      return ;
    } else pp = w;
  reverse ( prv.begin () , prv.end () );
  prv . push_back ( v ) ;
  int cnt = 0;
  pp = -1;
  for ( auto w : graph[v] ) {
    if( mark[w] ) continue;
    cnt ++;
    if ( cnt > 1 ) {
      OK = true;
      ans = vector<int> ( { w,v,pp } );
      return ;
    }
    dfs ( w , prv, OK, ans );
    if ( OK ) return ;
    pp = w;
  }
}

int main ( ) {
  int n,m; scanf( "%d %d" , &n, &m );
  for ( int i = 0;i<m;i++ ) {
    int x,y; scanf( "%d %d", &x,&y ) ;
    if ( ( x == 1 && y == n ) || ( x == n && y == 1 ) ) {
      printf ( "1\n1 %d\n" ,n); exit ( 0 ); }
    graph[x].push_back ( y ) ;
    graph[y].push_back ( x ) ;
  }
  for ( auto w : graph [ 1 ] ) 
    for ( auto u : graph [ w ] )
      if ( u == n ) {
        printf( "2\n1 %d %d\n",w,u ); exit ( 0 ) ;}
  for( int i = 0;i<MAXN;i++ ) sort ( graph[i].begin () , graph[i] .end () );
  for ( auto w : graph [ 1 ] ) 
    for ( auto z : graph [ w ] ) 
      if ( !mark [ z ] ) {
        mark[z] = true;
        if ( * lower_bound ( graph[z].begin(), graph[z].end(), n ) == n ) 
          printf ( "3\n1 %d %d %d\n",w,z,n ), exit ( 0 );
      }
  memset ( mark , 0 , sizeof mark );
  for( auto w : graph [ 1 ] )
    for ( auto u : graph [ w ] )
      if ( u != 1 && * lower_bound ( graph[1].begin(),graph[1].end() , u) != u )
        printf( "4\n1 %d %d 1 %d\n",w,u,n),exit ( 0 );
  vector<int> P ;
  bool OK = false;
  vector<int> ans ;
  mark[1] = true;
  for( auto w : graph [ 1 ] ) {
    if ( mark[w] ) continue ;
    P.clear();
    dfs ( w , P , OK, ans);
    if ( OK ) {
      printf ( "5\n1 %d %d %d %d %d\n" ,ans[0],ans[1],ans[2],ans[0],n);
      return 0;
    }
  }
  printf ( "-1\n" );
  return 0;
}
