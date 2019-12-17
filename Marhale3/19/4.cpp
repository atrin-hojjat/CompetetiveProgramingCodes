#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 6.66;
const int mod = 22273;
int cnt [ MAXN ];

int main ( ) {
  for ( int i = 1;i<MAXN;i++ ) 
    for ( int j = i;j<MAXN;j+=i ) 
      cnt[j] ++ ;
  set<pair<int,int>> ss;
  for ( int i = 1;i<MAXN;i++ )
  {
    ss.insert ( { -cnt[i],i } );
    while ( ss.size ( ) > 5 ) ss.erase ( std::prev ( ss.end ( ) ) );
  }
  for ( auto x : ss ) cout << -x.first << " " << x.second << " " << x.second % mod<< endl;
  return 0;
}
