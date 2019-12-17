#include <bits/stdc++.h>
using namespace std;

struct Bit {
  int * bit ;
  int N ;
  
  Bit ( ) { bit = nullptr ; }
  Bit ( int n ) { N = n +2 ;bit = new int [ n + 10 ] ( ) ; }

  long long get ( int x ) {
    x ++ ;
    long long sum = 0;
    while ( x > 0 ) sum += bit[x],x ^= x&-x ;
    return sum ;
  }

  void add ( int x,long long val ) {
    x ++ ;
    while (  x > 0 && x < N ) bit[x] += val, x += x&-x;
  }
  
  long long operator [ ] ( int x ) { return get ( x ) ; } 
} ;

const int MAXN = 1e5 + 6.66;
char DNA[4] = { 'A','T','G','C' } ;
int main ( ) {
  ios::sync_with_stdio ( false ) ;
  cin.tie( NULL ),cout.tie ( NULL ) ;
  string str;cin >> str;
  map<char,int> revD;
  for ( int i = 0;i<4;i++ ) revD [ DNA [i]] = i ;
  int N = str.size ( ) ;
  Bit bits [ 4 ] [ 11 ] [ 11 ];
  for ( int i = 1;i<=10;i++ ) {
    for ( int j = 0;j<i;j++ )
     for ( int ww = 0;ww<4;ww++ ) bits[ww][i][j] = Bit ( ( N + i -1 ) / i ) ;
    for ( int j = 0;j<( N + i - 1 ) /i;j++ )
      for ( int k = 0;k<min ( i,N - j * i ) ;k ++ )
        bits[ revD [ str [ i * j + k ] ] ] [ i ] [ k ] .add ( j, 1 ) ;
  }
  int Q;cin >> Q;
  while ( Q -- ) {
    int t;cin >> t;
    if ( t == 1 ) {
      int x;cin >> x;
      x--;
      char w ; cin >> w;
      int wor = revD [ w ];
      int wro = revD [ str [ x ] ] ;
      str [ x ] = w;
      for ( int i = 1;i<=10;i++ )
        bits[wor][i][x%i].add ( x/i , 1) ,bits[wro][i][x%i].add ( x / i , -1) ;
    } else {
      int l,r;cin >> l >> r;
      l--,r--;
      string ee;cin >> ee;
      int e = ee.size () ;
      long long ans = 0;
      for ( int i = 0;i<min ( r - l + 1, e ) ;i++ )
      {
        int c ;
        int a,b;
        a = bits[revD[ee[i]]][e][ ( l + i ) % e].get ( c = ( r % e < ( l + i ) % e ? r / e - 1 : r/e) ) ;
        b =  bits[revD[ee[i]]][e][ ( l + i ) % e].get ( ( l + i ) / e -1 );
        ans += a - b;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
