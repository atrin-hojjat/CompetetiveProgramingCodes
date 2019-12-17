#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 6.66;
map<long long,int> vals;

int main ( ) {
  int n;long long a,b;cin >> n >> a >> b;
  for( int i = 0;i<n;i++ ) {
    long long x,vx,vy;cin >> x >> vx >> vy;
    vals[ vy + a * vx ] ++;
  }
  long long ans = 1LL * n * ( n -1 ) / 2;
  for( auto w : vals ) ans -= 1LL * w.second * ( w.second - 1 ) / 2;
  cout << ( ans << 1 ) << endl;
  return 0;
}
