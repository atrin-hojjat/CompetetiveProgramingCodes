#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 6.66;

int main ( ) {
  ios::sync_with_stdio ( false ) ;
  cin.tie ( NULL ), cout.tie ( NULL ) ;
  string str;cin >> str;
  deque<pair<char,int> > q1,q2;
  int cnt = 0;char prv = '\0';
  for ( auto w : str ) 
    if ( w == prv ) cnt ++;
    else {
      if ( cnt > 0 ) q1.push_back ( { prv,cnt } );
      cnt = 1,prv = w ;
    }
  q1.push_back ( { prv,cnt } ) ;
  int step = 0 ;
  while ( q1.size ( ) > 1 ) {
    bool first = true;
    while ( q1.size ( ) ) {
      char ch = q1.front () .first ;
      int cn = q1.front ( ) .second ;
      q1.pop_front () ;
      if ( !q1.size ( ) || first ) {
        if ( cn > 1 ) q2.push_back ( { ch,cn -1 } );
        first = false;
        continue;
      }
      if ( cn < 3 ) {
        if ( q2.size () && q1.size ( ) && q1.front ( ) .first == q2.back ( ) .first ) {
          int cnn = q1.front ( ) .second ;
          q1.pop_front ( );
          if ( cnn > ( min ( ( int ) q1.size ( ) + 1, 2 ) ) ) {
            pair<char,int> cc = q2.back ();q2.pop_back ( );
            cc.second += cnn - ( min ( ( int ) q1.size () + 1 , 2 ) );
            q2.push_back ( cc ) ;
          }
        }
      } else {
        q2.push_back ( { ch, cn - 2 } );
      }
    }
    q1.swap ( q2 ) ;
    step ++ ;
  }
  cout << step << endl;
  return 0;
}
