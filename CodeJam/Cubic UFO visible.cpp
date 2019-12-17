#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-12;
const long double sq2 = sqrt(2.l);

long double Abs(long double x) {
  return ( x > 0 ? x : -x );
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int T;cin >> T;
  for(int tt = 1;tt<=T;tt++) {
    long double A;cin >> A;
    long double l = 0;
    long double r = M_PI/4;
    for ( ;; ) {
      long double mid = ( l + r ) / 2;
      long double S = sq2 * cos ( M_PI*1.l/4 - mid ) ;
      if( S > A ) r = mid;
      else l = mid;
      if ( abs( A - S ) < eps ) break;
    }
    cout << "Case #" << tt << ": " << endl;
    cout << fixed << setprecision(12) ;
    long double y1 = .5 * cos( l );
    long double x1 = .5 * sin( l );
    long double x2 = .5 * cos( l );
    long double y2 = .5 * sin( l );
    cout << x2 << " " << y2 << " 0" << endl;
    cout << x1 << " " << y1 << " 0" << endl;
    cout << "0 0 0.5" << endl;
  }
  return 0;
}
