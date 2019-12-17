#include <bits/stdc++.h>
using namespace std;

int main() {
  int X,d;cin >> X >> d;
  vector<int> res;
  int min = 1;
  for(int i = 30;i>-1;i--) {
    if( ! ( ( X >> i ) & 1 ) ) continue;
    min += d + 2;
    res.push_back( min );
    min += d + 2;
    for(int ij = 0;ij<i;ij++) res.push_back( min ) ;
  }
  cout << res.size() << endl;
  for( auto w : res ) cout << w << " ";;
  return 0;
}
