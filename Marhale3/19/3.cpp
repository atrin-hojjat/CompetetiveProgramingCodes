#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10 + 1;
const int mod = 22273;
int fact [ MAXN ];
int ifact [ MAXN ];

long long bpow ( long long base,long long exp,long long m = mod ) {
  long long ans = 1;
  for ( ; exp ; exp >>= 1,base = base * base % m )
    if ( exp & 1 ) ans = ( ans * base ) % m;
  return ans;
}


void init_fact ( ) {
  fact[0] = 1;
  for ( int i = 1;i<MAXN;i++ ) fact [i] = 1LL * fact [i - 1] * i % mod;
  ifact[MAXN-1] = bpow ( fact[MAXN-1], mod - 2 ) ;
  for ( int i = MAXN-2;i>-1;i-- ) ifact[i] = 1LL * ifact[i + 1] * ( i + 1 ) % mod;
}

int C ( int n,int r ) {
  if ( r > n ) return 0;
  return 1LL* ( 1LL * fact [ n ] * ifact [ r ] % mod ) * ifact [ n - r ] % mod;
}

int main ( ) {
  int a,b; scanf ( "%d %d", &a ,& b );
  init_fact ( ) ;
  cout << C ( a, b ) << endl;
  return 0;
}
