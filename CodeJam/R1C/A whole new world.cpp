#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 200 + 20 + 2;
string str[MAXN];
bool mark[30][26];

int main () {
  ios::sync_with_stdio( false ) ;
  int T;cin >> T;
  for ( int TT = 1;TT<=T;TT ++ ) {
    int N,L;cin >> N >> L;
    for ( int i = 0;i<N;i++ ) cin >> str[i];
    memset ( mark,0,sizeof mark ) ;
    for ( int i = 0;i<N;i++ )
      for ( int j = 0;j<L;j++ )
        mark [j ][ str[i][j] - 'A' ] = true;
    if ( L == 1 ) {
      cout << "Case  #"<<TT<< ": -" << endl;
      continue;
    } if ( L < 3 ) {
      bool done = false;
      for ( int i = 0;i<26 && !done;i++ )
        for ( int j = 0;j<26;j++ ) {
          bool ok = true;
          if ( ! mark[0][i] || ! mark[1][j] ) continue; 
          for ( int k = 0;k<N;k++ )
            if ( str[k][0] - 'A' == i && str[k][1] - 'A' == j ) ok = false;
          if ( ok )
          {
            cout << "Case #" << TT <<": " << ( char ) ( i + 'A' ) << ( char ) ( j + 'A' ) << endl;
            done = true;break;
          }

        }
      if ( done ) continue;
      else {
        cout << "Case #" << TT <<": -" << endl;
        continue;
      }
    }

  }
}
