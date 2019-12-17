#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400 + 40 + 4;
int arr [ MAXN ] ;
int par [ MAXN ] ;
long double res [ MAXN ];
int n;

long double get_ans ( long double dis, int i ) {
  long double ans = 0;
  for ( int j = 0;j<n;j++ )
    ans += abs ( 1.l * arr [ i ] + ( j - i ) * dis - arr [ j ] ) ;
  return ans;
}

void generate_ans(pair<long double, pair<long double, int>> ans ) {
  int i = ans.second.second;
  long double dis = ans.second.first;
  cout << fixed << setprecision(10) ;
  cout << ans.first << endl;
  for ( int j = 0;j<n;j++ ) 
    cout << ( arr[ i ] + ( j - i ) * dis ) << " " ;
  cout << endl;
}

int main ( ) {
  scanf ( "%d", &n );
  for ( int i = 0;i<n;i++ ) scanf( "%d", arr + i );
  sort ( arr, arr + n ) ;
  long double mn = 4e8 + 12 ;
  pair<long double,pair<long double,int>> ans = { mn, { 100, 100 } } ;
  for ( int i = 0;i<n;i++ ) {
    long double l = 0, r = 1e5 ; 
    for( int I = 0;I < 200;I ++ ) {
      long double s1 = l + 4.l * ( r - l ) / 9 ;
      long double s2 = l + 5.l * ( r - l ) / 9 ;
      if ( get_ans ( s1, i ) < get_ans ( s2, i ) ) r = s2;
      else l = s1;
    }
    ans = min( ans, { get_ans( l, i), { l, i } } );
  }
  generate_ans ( ans ) ;
  return 0;
}
