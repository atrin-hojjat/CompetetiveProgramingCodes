#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 6.66;
const int LOGMAXN = 20;
int par [ MAXN ] ;
int h [ MAXN ] ;
int lca [ LOGMAXN ] [ MAXN ] ;
bool mark [ MAXN ] ;
vector<int> tree [ MAXN ] ;

void lca_dfs ( int v,int p = 0,int hei = 0 ) {
    par [ v ] = p;
    h [ v ] = hei;
    for ( auto u : tree [ v ] )
        if ( u != p )
            lca_dfs ( u,v,hei + 1 );
}

void init_lca ( int n ) {
    for ( int i = 1;i<=n;i++ )
        lca [ 0 ] [ i ] = par [ i ];
    for ( int i = 1;i<LOGMAXN;i++ )
        for ( int j = 1;j<=n;j++ )
            lca [i][j] = lca [i-1][lca[i-1][j]];
}

int find_first ( int v ) {
    int u = v;
    for ( int i = LOGMAXN - 1;i>-1;i-- )
        if ( ( 1 << i ) <= h[u] + 1 && 
            lca[i][u] && !mark[lca[i][u]] ) u = lca[i][u];
    return lca [0][u] ;
}

void dfs_back ( int v ) {
    mark [ v ] = true;
    if ( par [ v ] && !mark[ par [ v ] ] ) dfs_back ( par [ v ] );
}

int main ( ) {
    ios::sync_with_stdio ( false );
    cin.tie ( NULL ) ,cout.tie ( NULL ) ;
    int n,k;cin >> n >> k;
    for ( int i = 1;i<n;i++ ) {
        int x,y;cin >> x >> y;
        tree[x].push_back ( y );
        tree[y].push_back ( x ) ;
    }
    int rem = n - 1 - k;
    lca_dfs ( n ) ;mark[ n ] = mark [ 0 ] = true;
    init_lca ( n ) ;
    for ( int i = n - 1; rem && i > 0 ;i -- ) {
        if ( mark [i] ) continue;
        int u = find_first ( i ) ;
        if ( ( h[i] - h[u] )  > rem ) continue;
        rem -= h[i] - h[u];
        dfs_back ( i ) ;
    }
    for ( int i = 1;i<=n;i++ ) if ( !mark [i] ) cout << i << " " ;cout << endl;
    return 0;
}
