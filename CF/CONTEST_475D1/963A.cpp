#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1e5+ 6.66;
const long long mod = 1e9 + 9;
long long seq[MAXK];

long long bpow ( long long base,long long exp ) {
  long long res = 1;
  for ( ;exp ; exp>>=1,( base *= base ) %=mod ) if( exp &1 ) ( res *= base ) %= mod;
  return res;
}

int main () {
  int n,a,b,k; scanf( "%d %d %d %d",&n,&a,&b,&k );
  string str;cin >> str;
  for(int i = 0;i<k;i++) seq[i] = ( str[i] == '+' ? 1 : -1 );
  long long ans = 0;
  long long A = bpow( a,n ) ;
  long long sh = bpow( a, mod -2 ) * b % mod ;
  for(int i = 0;i<k;i++) 
    (ans += mod + seq[i] * A)%= mod,(A *= sh) %= mod;
  sh = bpow ( bpow ( a, mod -2 ),k ) * bpow ( b, k ) % mod;
  if( sh == 1 ) {
    long long CC = ( n + 1 ) / k;
    cout << ( 1LL * CC * ans ) % mod << endl;
    return 0;
  }
  long long W = 1LL - sh + mod;W%=mod;
  long long Z = bpow( sh , ( n + 1 ) /k );
  long long X = ( 1LL - Z + mod ) %mod;
  long long C = (ans * X) % mod * bpow ( W, mod -2 ) ;
  C%= mod;
  cout << C << endl;
  return 0;
}
