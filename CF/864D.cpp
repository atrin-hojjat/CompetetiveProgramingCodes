#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 6.66;
map<int,int> cnt ;
int arr[MAXN];
bool oked [ MAXN ] ;

int main ( ) {
  int n; scanf ( "%d" , &n ) ;
  for ( int i = 0;i<n;i++ ) scanf ( "%d" , arr + i ) ;
  for ( int i = 0;i<n;i++ ) cnt [ arr [i] ] ++ ;
  deque < int > unused;
  for ( int i = 1;i<=n;i++ ) if ( !cnt.count ( i ) ) unused .push_back ( i ) ;
  int ans = 0;
  for ( auto w : cnt ) ans += w.second - 1 ;
  for ( int i = 0;i<n;i++ ) {
    if ( cnt [ arr[i] ] == 1 ) continue;
    if ( !oked [arr[i]] && arr [i] < unused.front ( ) ) oked[arr[i]] = true;
    else {
      cnt[arr[i]] -- ;
      arr[i] = unused.front ( ) ;
      unused.pop_front ( ) ;
    }
  }
  printf ( "%d\n" , ans ) ;
  for ( int i = 0;i<n;i++ ) printf ( "%d " , arr [i] ) ;
  printf ( "\n" ) ;
  return 0;
}
