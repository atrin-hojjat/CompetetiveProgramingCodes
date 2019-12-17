#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
long long val [ MAXN ] ;
vector<int> tree [ MAXN ] ;

long long dfs ( int v,int p ) {
  if ( tree[v].size ( ) == 1 ) return val [ v ] ;
  if ( p != -1 && tree[v].size ( ) == 2 ) {
    int u = tree[v][0] ;
    if ( u == p ) u = tree[v][1] ;
    if ( dfs ( u , v ) != val [ v ] ) { printf("NO\n") ; exit ( 0 ) ; }
    return val [ v ];
  }
  long long sum = 0,mx = 0;
  for ( auto u : tree[v] )
    if ( u != p )
    {
      long long x = dfs ( u , v ) ;
      sum += x;mx = max ( mx , x ) ;
    }
  mx = max ( mx , 2 * val [ v ] - sum ) ;
  if ( 2LL * val [ v ] < 2LL * mx || val [ v ] < sum /2 || val [ v ] > sum ) { 
    printf ( "NO\n" ) ; exit ( 0 ) ; };
  return val[v] * 2 - sum;
}

int main ( ) {
  int n;scanf ( "%d" , &n ) ;
  for ( int i = 0;i<n;i++ ) scanf ( "%lld",val + i );
  for ( int i = 1;i<n;i++ ) {
    int x,y; scanf ( "%d %d",&x,&y ) ;
    tree[--x].push_back( --y );
    tree[  y].push_back(   x );
  }
  if ( n == 2 ) {
    if ( val[0] == val[1] ) printf ( "YES\n" );
    else printf ( "NO\n" ) ;
  } else {
    int root = 0;
    while ( tree[root].size ( ) == 1 ) root ++ ;
    if ( dfs ( root, -1 ) ) printf ( "NO\n" ) ;
    else printf ( "YES\n" ) ;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
long long val [ MAXN ] ;
vector<int> tree [ MAXN ] ;

long long dfs ( int v,int p ) {
  if ( tree[v].size ( ) == 1 ) return val [ v ] ;
  if ( p != -1 && tree[v].size ( ) == 2 ) {
    int u = tree[v][0] ;
    if ( u == p ) u = tree[v][1] ;
    if ( dfs ( u , v ) != val [ v ] ) { printf("NO\n") ; exit ( 0 ) ; }
    return val [ v ];
  }
  long long sum = 0,mx = 0;
  for ( auto u : tree[v] )
    if ( u != p )
    {
      long long x = dfs ( u , v ) ;
      sum += x;mx = max ( mx , x ) ;
    }
  if(2 * val[v] - sum < 0){
    printf("NO\n");exit(0);
  }
  mx = max(mx,val[v] * 2 - sum);
  if(mx > val[v] * 2 - mx){ 
    printf ( "NO\n" ) ; exit ( 0 ) ;
  }
  return val[v] * 2 - sum;
}

int main ( ) {
  int n;scanf ( "%d" , &n ) ;
  for ( int i = 0;i<n;i++ ) scanf ( "%lld",val + i );
  for ( int i = 1;i<n;i++ ) {
    int x,y; scanf ( "%d %d",&x,&y ) ;
    tree[--x].push_back( --y );
    tree[  y].push_back(   x );
  }
  if ( n == 2 ) {
    if ( val[0] == val[1] ) printf ( "YES\n" );
    else printf ( "NO\n" ) ;
  } else {
    int root = 0;
    while ( tree[root].size ( ) == 1 ) root ++ ;
    if ( dfs ( root, -1 ) ) printf ( "NO\n" ) ;
    else printf ( "YES\n" ) ;
  }
  return 0;
}
