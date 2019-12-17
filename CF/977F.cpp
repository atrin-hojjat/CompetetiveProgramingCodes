#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 6.66;
int arr[MAXN];
pair<int,int> sr [MAXN];
pair<int,int> ans [ MAXN ] ;

int main ( ) {
  int n; scanf ( "%d" , &n );
  for ( int i = 0;i<n;i++ ) scanf ( "%d",arr + i ) ;
  for ( int i = 0 ;i<n;i++ ) sr[i] = { arr[i], i } ;
  sort ( sr, sr + n ) ;
  int prv = -1;
  set<pair<int,int>> P,N;
  for ( int i = 0;i<n;i++ ) {
    if ( sr[i].first != prv ) {
      if ( prv == sr[i].first - 1 ) N.swap ( P ) ;
      else P.clear ( ) ;
      N.clear ( ) ;
      prv = sr[i].first ;
    }
    pair<int,int> c = { -1 , -1 };
    for ( auto w : P )
      if ( w.first < sr[i].second ) c = max ( c , { w.second,w.first } ) ;
      else break;
    P.erase ( P.begin () , P.upper_bound ( { sr[i].second,0 } ) ) ;
    N.insert ( { sr[i].second , c .first + 1 } ) ;
    ans [sr[i].second] = c ; ans[sr[i].second].first ++ ;
  }
  pair<int,int> mx = { 0 , -1 };
  for ( int i = 0;i<n;i++ ) mx = max ( mx, { ans[i].first + 1,i } )  ;
  vector<int> vv ;
  printf ( "%d\n", mx.first );
  while ( ~mx.second ) {
    vv.push_back ( 1 + mx.second );
    mx = { mx.first - 1 , ans[mx.second].second };
  }
  reverse ( vv.begin () , vv.end ( ) ) ;
  for ( auto w : vv ) printf ( "%d ", w ) ;
  printf ( "\n" );
  return 0;
}
