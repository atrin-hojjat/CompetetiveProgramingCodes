#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 6.66;
int root [ MAXN ];
bool mark[MAXN];
vector<int> rm;
set<int> roots;
int sz[ MAXN ];
set<int> eds[ MAXN ];

int get_root ( int x ) { return root[x] ? root[x] = get_root( root[x] ) : x ; }

void merge ( int v,int u ) {
  int rv = get_root ( v ) ;
  int ru = get_root ( u ) ;

  if ( rv == ru ) return ;
  if ( eds[rv] < eds[ru] ) swap ( rv,ru );

  root[rv] = ru;
  sz[ru] += sz[rv];
  rm.push_back ( rv ) ;
  for( auto w : eds[rv] ) 
    eds[ru] . insert ( w );
}

int main ( ) {
  ios::sync_with_stdio ( false ) ;
  cin.tie ( NULL ), cout . tie ( NULL ) ;
  int n,m;cin >> n >> m;
  for ( int i = 0;i<m;i++ ) {
    int x,y;cin >> x >> y;
    eds[x]. insert ( y ) ;
    eds[y]. insert ( x ) ;
  }
  for ( int i = 1;i<=n;i++ ) roots.insert ( i ) ;
  for ( int i = 1;i<=n;i++ ) sz[i] = 1;
  for ( int i = 1;i<=n;i++ ) {
    int v = get_root ( i ) ;
    if ( mark [ v ] ) continue;
    for ( auto w : roots ) 
      if ( * eds[v].lower_bound ( w ) != w )
        merge ( v, w ) ;
    for ( auto w : rm ) roots.erase ( roots.find ( w ) );
    rm.clear () ;
  }
  multiset <int > vals ;
  for ( auto w : roots )
    vals.insert ( sz [ get_root ( w ) ] );
  cout << vals.size () << endl;
  for ( auto x : vals ) cout << x << " " ;cout << endl;
  return 0;
}
