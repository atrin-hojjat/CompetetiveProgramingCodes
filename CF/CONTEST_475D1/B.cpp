#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 6.66;
vector<int> tree[MAXN];
bool mark[MAXN];
int par[MAXN];
vector<int> O;

bool dfs(int v,int p = 0 ) {
  bool E = tree[v].size() &1;E = !E;
  par[v] = p;
  for(auto w : tree[v]) {
    if( w == p ) continue;
    if( dfs( w, v ) ) E = !E;
  }
  if ( E ) O.push_back( v );
  return E;
}

void dfs_rm( int v ) { 
  cout << v << endl;
  mark[v] = true;
  for( auto w : tree[v] )
    if( w != par[v] && !mark[w] ) dfs_rm( w );
}

int main() {
  ios::sync_with_stdio( false );
  cin.tie(NULL),cout.tie(NULL) ;
  int n;cin >> n;
  for(int i = 1;i<=n;i++) {
    int p;cin >> p;
    if ( p ) 
      tree[p].push_back( i ),tree[i].push_back ( p );
  }
  bool ans = dfs( 1 );
  if( ! ans ) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for(auto w : O ) dfs_rm( w ) ;
  return 0;
}
