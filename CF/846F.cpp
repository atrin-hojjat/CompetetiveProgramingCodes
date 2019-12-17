#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 6.66;
int arr[ MAXN ];
vector < int > nums [ MAXN ] ;

int main ( ) {
  int n;cin >> n;
  for ( int i = 0;i<n;i++ ) {
    cin >> arr[i];
    nums[arr[i]].push_back ( i ) ;
  }
  long long cnt = 0;
  for (int i = 0;i<MAXN;i++ ) {
    int prv = -1;
    long long cc = 0;
    for ( auto w : nums [i] )
      cc += 2LL * ( w - prv ) * ( n - w ) - 1,prv = w;
    cnt += cc;
  }
  long double ans = 1.l * cnt / ( 1LL * n * n ) ;
  cout << fixed << setprecision ( 13 ) << ans << endl;
  return 0;
}
