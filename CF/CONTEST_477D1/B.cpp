#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+6.66;
int arr[MAXN];
pair<int,int> srt [ MAXN ] ;
int cnt1[MAXN];
int cnt2[MAXN];

int main ( ) {
  int n,x1,x2;cin >> n >> x1 >> x2;
  for( int i = 0 ;i < n;i ++ ) cin >> arr[i];
  for( int i = 0 ; i < n;i ++ ) srt[i].first = arr[i];
  for ( int i = 0;i<n;i++ ) srt[i].second = i + 1;
  sort ( srt , srt + n ) ;
  for ( int i = 0;i<n;i++ ) cnt1[i] = ( x1 + srt[i].first -1 ) / srt[i].first ;
  for ( int i = 0;i<n;i++ ) cnt2[i] = ( x2 + srt[i].first -1 ) / srt[i].first ;
  for ( int i = 0;i<n;i++ ) {
    if( cnt1[i] + i < n && cnt2[i + cnt1[i]] + i + cnt1[i] <= n ) {
      cout << "Yes" << endl;
      cout << cnt1[i] << " " << cnt2[i + cnt1[i] ] << endl;
      for( int j = 0;j<cnt1[i];j++ ) cout << srt[j + i ].second << " "; cout << endl;
      for( int j = 0;j< cnt2[i + cnt1[i]] ;j++ ) cout << srt[j + i + cnt1[i]].second << " " ;cout << endl;
      return 0;
    }
    if ( cnt2[i] + i < n && cnt1[i + cnt2[i]] + i + cnt2[i] <= n ) {
      cout << "Yes" << endl;
      cout << cnt1[i + cnt2[i]] << " " << cnt2[i] << endl;
      for( int j = 0;j< cnt1[i + cnt2[i]] ;j ++ ) cout << srt[j + i + cnt2[i] ].second << " " ; cout << endl;
      for( int j = 0;j < cnt2[i] ; j ++ ) cout << srt[j + i].second << " " ; cout << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
