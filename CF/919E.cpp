#include <bits/stdc++.h>
using namespace std;

const int MAXP = 1e6 + 3;
long long mod ;
map<long long , bool > mark;

long long bpow ( long long base, long long exp ) {
  long long ans = 1;
  for ( ; exp ; exp >>= 1,base = 1LL * base * base % mod ) 
    if ( exp & 1 ) ( ans *= base ) %= mod ;
  return ans;
}

long long inverse ( long long num ) {
  return bpow ( num , mod - 2 ) ;
}

int main ( ) {
  long long a,b; 
  long long x;
  scanf ( "%lld %lld %lld %lld" , &a, &b,&mod,&x ) ;
  long long p = mod;
  long long ans = 0;
  for ( int n = 0;n<p;n++ ) {
    int nn = inverse ( bpow ( a , n ) ) * b % mod;
    int nc = ( n - nn ) % mod;
    while ( nc < 0 ) nc = mod + nc;
    long long fn = n + 1LL * nc * ( p - 1 ) ;
    if ( fn > x || mark [ fn ]) continue ;
    mark[fn] = true;
    ans += ( x - fn + ( 1LL * p * ( p - 1 ) ) )  / ( 1LL * p * ( p - 1 ) ) ;
  }
  printf ( "%lld\n",ans ) ;
  return 0;
}
