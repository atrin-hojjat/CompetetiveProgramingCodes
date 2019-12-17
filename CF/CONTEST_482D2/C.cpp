#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 6.66;
vector<int> tree [ MAXN ];
int W[ 2 ];
long long Ans = 0, AA = 0;

pair<int,bool> dfs ( int v,int p ) {
  int ret = 1;
  bool ok = ( v == W[1] ) ;
  for ( auto w : tree[v] ) 
    if ( w != p ) {
      pair<int,bool> cc = dfs ( w,v ) ;
      ok |= cc.second;
      if ( v!=W[0] || !cc.second) ret += cc.first ;
    }
  if ( v == W[1] ) AA = ret ;
  return { ret , ok } ;
}

int main ( ) {
  ios::sync_with_stdio ( false ) ;
  cin.tie (NULL ) ,cout.tie (NULL ) ;
  int n;cin >> n;
  for ( int i = 0;i<2;i++ ) cin >> W[i];
  for ( int i = 1;i<n;i++ ) {
    int x,y;cin >> x >> y;
    tree[x].push_back ( y ) ;
    tree[y].push_back ( x ) ;
  }
  int w = dfs ( W[0] , 0 ) .first ;
  Ans = 1LL * n * ( n - 1 ) - 1LL * AA * w ;
  cout << Ans << endl;
  return 0;
}
