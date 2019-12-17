#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
int arr[MAXN];
long long ans [MAXN];

int main () {
  ios::sync_with_stdio ( false ) ;
  cin.tie (NULL ) ,cout .tie ( NULL ) ;
  int T;cin >> T;
  for ( int tt = 1;tt<=T;tt++ ) {
    int N;cin >> N;
    for ( int i = 0;i<N;i++ ) cin >> arr[i] ;
    memset ( ans, 63, sizeof ans ) ;
    ans[0] = 0;
    for ( int i = 0;i<N;i++ ) {
      for ( int j = N;j>0;j-- ) {
        if ( arr[i] * 6 < ans[j-1] ) continue;
        ans[j] = min ( ans[j], ans[j-1] + arr[i] ) ;
      }
    }
    int t = 0;
    for ( int i = 0;i<=N;i++ ) if ( ans[i] < ans[MAXN-1] ) t = i;
    cout << "Case #" << tt << ": " << t << endl;
  }
  return 0;
}
