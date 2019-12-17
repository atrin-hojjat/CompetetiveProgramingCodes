#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+ 6.66;
pair<int,int> arr[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,x1,x2;
  cin >> n >> x1 >> x2;
  for(int i = 0;i<n;i++) cin >> arr[i].first;
  for(int i = 0;i<n;i++) arr[i].second = i + 1;
  sort( arr ,arr + n) ;
  for(int cnt = 1;cnt < n;cnt++) {
    int w = ( cnt -1 + x1) / cnt;
    pair<int,int> ccd = { w , 0 } ;
    int t = lower_bound( arr,arr + n,ccd) - arr;
    if( t > n-cnt ) continue;
    int N = n - cnt;
    int l = 1,r = N;
    while( l < r ) {
      int mid = l + (( r- l ) >> 1);
      int WW;
      if( n - mid >= t + cnt ) WW = n - mid;
      else WW = n - cnt - mid;
      int zz = ( mid -1 + x2 ) / mid;
      if( zz <= arr[WW].first ) r = mid;
      else l = mid + 1;
    }
    int WW ,mid = r;
    if( n - r >= t + cnt ) WW = n - mid;
    else WW = n - mid - cnt;
    int zz = ( r - 1 + x2 ) / r;
    if( zz <= arr[WW] .first ) {
      vector<int> ttt;
      cout << "Yes" << endl;
      cout << cnt << " " << r << endl;
      int cc = cnt;
      int i;
      for(i = n-1;i>-1;i--) {
        cout << arr[i].second << " ";
        if( arr[i].first < ( cnt -1 + x1 ) / cnt )  exit ( -2 );
        cc--;
        if( cc == 0 ) break;
      }
      if( cc > 0 ) exit( -1 );
      cc = r;cout << endl;
      i--;
      for(;i>-1;i--) {
        cc --;
        cout << arr[i].second << " "; 
        if( arr[i].first < zz )  exit ( -2 );
        if( cc == 0 ) break;
      }
      cout << endl;
      if( cc > 0 ) exit( -1 );
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
