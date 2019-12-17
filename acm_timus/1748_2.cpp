#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 10 + 1;
long long primes [ 20 ] ;
long long in[MAX];
long long ww[MAX];
int T;
pair<int , long long > ans[MAX];

bool is_prime ( long long x ) {
  for(int i = 2;i<=sqrt(x ) ;i++) 
    if( x % i == 0 ) return false;
  return true;
}

void prep () {
  int cnt = 0;
  int prv = 2;
  while( cnt < 20 ) {
    int i ;
    for(i = prv;i<1e18;i++) 
      if( is_prime ( i ) ) break;
    primes[cnt++] = i;prv = i + 1;
  }
}

void backtrack ( int s = 1,long long w = 1,int k = 0,int t = 61) {
  pair<int ,long long > res = { s , w };
  int wt = lower_bound ( ww , ww + T, res.second ) - ww;
  ans[wt] = max( ans[wt], { res.first, -res.second } );
  if ( k >= 20 ) return ;
  long long tt = primes[k];
  for(int p = 1;p<=t;p++,tt *= primes[k]) {
    if ( w > ww[T-1] / tt ) break;
    backtrack ( s * ( p + 1 ),w * tt,k + 1,p ) ;
  }
  return ;
}

int main () {
  prep ();int Q;
  cin >> Q;
  while ( Q-- ) {
    long long i;cin >> i;
    ww[0] = i;T = 1;ans[0] = {0,0};
    backtrack ( ) ;
    cout << -ans[0].second << " " << ans[0].first << endl;
  }
  /*
  for(int i = 0;i<T;i++) cin >> in[i];
  for(int i = 0;i<T;i++) ww[i] = in[i];
  sort( ww, ww + T ) ;
  backtrack ( );
  for(int i = 0;i<T;i++) {
    pair<int,long long> res = { 0 , 0 };
    for(int j = 0;j<T;j++) {
      if( ww [j] > in[i] ) break;
      res = max ( res, ans [j] );
    }
    cout << -res.second << " " << res.first << endl;
    }*/
  return 0;
}
