#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200 + 20 + 2;
int pos[MAXN];

int main () {
  int T;cin >> T;
  while ( T -- ) {
    int N;cin >> N;
    memset ( pos,0,sizeof pos ) ;
    for ( int i = 0;i<N;i++ ) {
      int D;cin >> D;
      vector<int > cc = vector <int > ( D );
      for ( int j = 0;j<D;j++ ) cin >> cc[j];
      pair<int,int> ch = {1e9+7,-1};
      for ( int j = 0;j<D;j++ )
        if ( pos[cc[j]] > 0 ) ch = min ( ch, { pos[cc[j]],cc[j] } ) ;
      cout << ch.second << endl;
    }
  }
  return 0;
}
