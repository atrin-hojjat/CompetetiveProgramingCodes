#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
const int MAX = ( 1<<8 ) + 6.66;
int arr[MAXN];
int last [ MAXN ];
int first [ MAXN ];

int main ( ) {
  int n,k;scanf ( "%d %d",&n,&k ) ;
  for ( int i = 0;i<n;i++ ) scanf ( "%d", arr + i ) ;
  for ( int i = 0;i<MAX;i++ ) first [i] = i,last[i] = i ;
  for ( int i = 0;i<n;i++ ) {
    for ( int j = arr[i]-1 ; j > -1 ; j -- ) {
      if ( last[arr[i]] - first [j] + 1 <= k ) first[arr[i]] = first[j] ;
    }
    for ( int j = first[arr[i]];j<=last[arr[i]];j++ ) 
      first [j] = first[arr[i]],last[j] = last[arr[i]] ;
  }
  for ( int i = 0;i<n;i++ ) printf ( "%d ",first[arr[i]] );
  printf ( "\n" ) ;
  return 0;
}
