#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400 + 40 + 4;
int arr [ MAXN ];
int n;

long double calc(int l,int r) {
  long double ans = 0;
  long double dis = 1.l * ( arr [ r ] - arr [ l ] ) / ( r - l ) ;
  for ( int i = 0; i<n; i++ ) 
    ans += abs ( arr [ l ] + dis * ( i - l ) - arr [ i ] ) ;
  return ans;
}

void generate_ans( pair<long double,pair<int, int>> ans ) {
  int l = ans.second.first;
  int r = ans.second.second;
  cout << fixed << setprecision(10) ;
  cout << ans.first << endl;
  long double dis = 1.l * ( arr [ r ] - arr [ l ] ) / ( r - l ) ;
  for ( int i = 0; i<n; i++ ) 
    cout << arr [ l ] + ( i - l ) * dis << " " ; cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  cin >> n ;
  for(int i = 0; i<n; i++) cin >> arr [ i ] ;
  sort( arr, arr + n ) ;
  pair<long double,pair<int,int>> ans = { 1e9+ 7, { 0, 0 } } ;
  for ( int l = 0; l<n; l++ )
    for(int r = 0; r<n; r++)
      ans = min(ans, {calc(l, r), { l, r } } ) ;
  generate_ans ( ans ) ;
  return 0;
}
