#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+6.66;
int a[MAXN],b[MAXN];

int main () {
  int n;cin >> n;
  int k1,k2; cin >> k1 >> k2;
  for(int i = 0;i<n;i++ ) cin >> a[i];
  for(int i = 0;i<n;i++) cin >> b[i];
  priority_queue<int> zz;
  for(int i = 0;i<n;i++) zz.push( abs(a[i] - b[i]) ) ;
  int c = k1 + k2;
  while( c ) {
    auto w = zz.top();
    zz.pop();
    if( w == 0 ) break;
    zz.push(w - 1 );
    if(!--c) break;
  }
  if( c ) {
    cout << c%2 << endl;
  } else {
    long long ans = 0;
    while( zz.size() ) {
      int w = zz.top();zz.pop();
      ans += 1LL * w * w;
    }
    cout << ans << endl;
  }
  return 0;
}
