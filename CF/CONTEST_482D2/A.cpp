#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e0 + 1;

int main ( ) {
  long long n; cin >> n;
  n ++ ;
  if ( n == 1 ) cout << 0 << endl;
  else if ( n % 2 ) cout << n << endl;
  else cout << n/2 << endl;
  return 0;
}
