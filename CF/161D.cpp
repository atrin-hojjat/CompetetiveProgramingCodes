#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 6.66;
const int MAXK = 500 + 50 + 5;
vector<int> tree [ MAXN ] ;
int dis [ MAXN ] [ MAXK ] ;
long long Ans = 0;

void dfs_up ( int v,int p ) {
  dis[v][0] = 1;
  for ( auto u : tree[v] )
    if ( u != p ) {
      dfs_up ( u , v ) ;
      for ( int i = 0;i<=500;i++ ) 
        dis[v][i + 1] += dis[u][i];
    }
}

void dfs_down ( int v,int p,int k ) {
  Ans += dis[v][k] + ( p ? dis[p][k-1] - dis[v][k-2] : 0 ) ;
  for ( int i = 500;p && i > -1 ;--i ) 
    dis[v][i+1] += dis[p][i] - ( i > 0 ? dis[v][i-1] : 0 ) ;
  for ( auto u : tree[v] )
    if ( u!= p )
      dfs_down ( u,v,k );
}

int main ( ) {
  int n,k; scanf ( "%d %d",&n,&k ) ;
  for ( int i = 1;i<n;i++ ) {
    int x,y; scanf ( "%d %d",&x, &y ) ;
    tree[x].push_back ( y ) ;
    tree[y].push_back ( x ) ;
  }
  /**/
  dfs_up ( 1, 0 );
  dfs_down ( 1,0,k );
  printf( "%lld\n",Ans / 2) ;
  return 0;
}
