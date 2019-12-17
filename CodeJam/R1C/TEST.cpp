#include <bits/stdc++.h>
using namespace std;

int main ( ) {
  long long len = 0,sum = 0;
  while ( sum/6 <= 1e9 ) {
    len ++;sum += max ( 1LL,( sum + 5 ) / 6 ) ;
    cout << len << " " << sum << endl;
  }
  cout << len << endl;
  return 0;
}
