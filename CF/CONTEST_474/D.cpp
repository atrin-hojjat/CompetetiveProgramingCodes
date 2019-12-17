#include <bits/stdc++.h>
using namespace std;

const unsigned long long MAX = 1LL << 63;
const int MAXN = 100;
unsigned long long shifts[MAXN];

int _log(unsigned long long x ) {
  unsigned long long ww = 1;
  int res = 0;
  int i = 63;
  for(;i>=0;i--) if( x & ( 1LL << i) ) break;
  return i;
}

long long sz( int x ) { return 1LL << x ; };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int Q;cin >> Q;
  for( int III = 0;III<Q;III++) {
    int T;cin >> T;
    long long x1,x2; 
    int w ;
    if( T == 1 ) {
      cin >> x1 >> x2; 
      w = _log(x1);
      shifts[w] += x2%sz(w) + sz(w);
      shifts[w] %= sz(w);
    } else if ( T == 2 ) {
      cin >> x1 >> x2; 
      int lev = _log(x1);
      long long www[MAXN];
      for(int i = lev;i<64;i++) www[i] = (x2%sz(i) + sz(i) ) %sz(i);
      while( lev < 64 ) {
        w = lev;
        shifts[w] += www[w];
        shifts[w] %= sz(w);
        lev ++;
        for( int i = lev;i<64;i++) (www[i] <<= 1) %=sz(i);
      }
    } else {
      cin >> x1;
      int c;
      x2 = sz(_log(x1)) +  (x1 + shifts[_log(x1)]) % sz(c = _log(x1)) ;
      cout << x1 << " ";
      x2 >>= 1,c--;
      while( c > -1 ) {
        cout << sz(c) + ( x2 - shifts[c] + sz(c) ) % sz(c) << " ";
        x2 >>= 1;
        c --;
      }
      cout << endl;
    }
  }
  return 0;
}
