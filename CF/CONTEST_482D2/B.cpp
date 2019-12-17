#include <bits/stdc++.h>
using namespace std;

int ans [ 4 ] ;
int cnt [ 257 ] ;

int main ( ) {
  int n;cin >> n;
  for ( int j = 0;j<3;j++ ) {
    string str;cin >> str;
    memset ( cnt,0,sizeof cnt ) ;

    for ( auto w : str ) cnt [ w ] ++;
    int mx = 0;
    for ( int i = 0;i<257;i++ ) mx = max ( mx,cnt[i] );
    if ( mx < str.size ( )  ) ans [ j ] = min ( ( int ) str.size ( ) , n + mx ) ;
    else ans [ j ] = mx - ( n == 1 ) ;
  }
  int mxx = max ( { ans[0],ans[1],ans[2] } );
  int ccc = ( ans [0] == mxx ) + ( ans [ 1 ] == mxx ) + ( ans[2] == mxx ) ;
  if ( ccc > 1 ) 
    cout << "Draw" << endl;
  else 
  {
    pair<int,int> mx = { ans[0],0 };
    for ( int i = 0;i<3;i++ ) mx = max ( mx, { ans[i],i } );
    string strs[ 3 ] = { "Kuro","Shiro","Katie" };
    cout << strs [ mx.second ] << endl;
  }
  return 0;
}
