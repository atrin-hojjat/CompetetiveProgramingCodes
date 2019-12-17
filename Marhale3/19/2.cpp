#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAX = 1e6 ;
const long long delta = 22273;
vector<int> fibs;

void make_fibs ( ) {
  int a = 1,b = 1,c;
  while ( a + b < MAX ) {
    c = a + b;
    fibs.push_back ( c ) ;
    swap ( a,b ) ;
    swap ( b,c ) ;
  }
}

int main ( ) {
  int cnt = 0;
  make_fibs ( ) ;
  for ( int i = MAXN;i<MAX;i++ ) 
  {
    bool ok = true;
    for ( auto w : fibs ) 
      if ( i % w == 0 ) { ok = false ; break ; } ;
    if ( ok ) cnt ++ ;
  }
  cout << cnt << endl;
  long long xx = 1LL * cnt *delta * 100 ;
  long double ddc = 1.l * xx / ( MAX - MAXN );
  long double percentage = 1.l * cnt * 100.l / ( MAX - MAXN ) ;
  long double ans = 1.l * delta * percentage ;
  cout << fixed << setprecision ( 7 ) << ddc << " "  << ans << endl << percentage << endl;
  return 0 ;
}
