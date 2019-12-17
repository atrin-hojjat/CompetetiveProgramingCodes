#include <bits/stdc++.h>
using namespace std;

const int mod = 22273.666;
const int mod2 = 1e6;

long long bpow ( long long base,long long exp,long long m ) {
  long long ans = 1;
  for ( ; exp ; exp>>=1, base = base * base % m )
    if ( exp & 1 ) ans = ( ans * base ) % m ;
  return ans ;
}

int main ( ) {
  long long a,b; scanf ( "%lld %lld", &a, &b ) ;
  long long w = bpow ( a,b,mod2 ) ;
  long long cc = w;
  long long ans = 1;
  while ( cc ) ans = ( ans * ( cc % 10 ) ) % mod, cc/= 10;
  cout << bpow ( a ,  b , mod2 ) << " " << ans << endl;;
  return 0;
}

