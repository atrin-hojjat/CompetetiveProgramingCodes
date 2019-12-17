#include <bits/stdc++.h>
using namespace std;

long long mul ( long long x, long long y, long long mod ) {
  long long ans = 0;
  if ( x < y ) swap ( x,y ) ;
  for(; y; y/= 10,x = ( unsigned long long ) x * 10ULL % mod )
    ans = ( 1ULL * ans + 1ULL * x * ( y%10 ) % mod) % mod ;
  return ans;
}

long long bpow ( long long base, long long exp, long long mod ) {
  base%=mod;
  long long ans = 1;
  for(; exp; exp>>=1, base = mul( base, base, mod ) )
    if ( exp & 1 ) ans = mul( ans, base, mod );
  return ans;
}

long long gcd ( long long a, long long b ) {
  return ( a ? gcd ( b%a, a ) : b ) ;
}

int main ( ) {
  int Q; scanf( "%d", &Q );
  while ( Q-- ) {
    long long a,b,c; scanf ( "%lld %lld %lld",&a,&b,&c ) ;
    long long z = gcd ( a,b ) ;
    a /= z;
    b /= z;
    long long w = bpow ( c, 64, b ) ;
    if ( w == 0 ) printf ( "Finite\n" ) ;
    else printf ( "Infinite\n" );
  }
  return 0;
}
