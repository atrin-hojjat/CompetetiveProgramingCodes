#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+6.66;
const int mod = 1e9 + 7;
long long par[MAXN];

long long POW(long long base,long long exp) {
  if( ! exp ) return 1;
  return ( exp & 1 ? base : 1 ) * POW(base * base % mod, exp >> 1 ) % mod;
}

long long& mul ( long long &x,long long y ) {
  return ( x = ( x % mod ) * ( y % mod ) % mod ) ;
}

template<typename...T> 
long long& mul ( long long &x,long long y,T...re) {
  return mul( mul( x,y ) , re... );
}

long long& add ( long long &x,long long y) {
  return ( x = ( x%mod + y%mod ) % mod );
}

template<typename...T>
long long& add ( long long &x,long long y,T...re) {
  return add( add ( x, y ), re... );
}

long long get_sum ( long long x ) {
  if( x <= 0 ) return 0;
  if( x % 2 ) 
    return ( ( x + 1 ) / 2 ) % mod * x % mod;
  else 
    return ( x / 2 ) % mod * ( x + 1 ) % mod;
}

long long get_sum_2 ( long long x ) {
  long long ret = 1;
  return mul( ret , x, x + 1, 2 * x + 1, POW(6,mod-2) );
}

long long get ( int l, long long m ) {
  long long res = 0;
  long long x = sqrt(m) - l;
  cout << res << ":";
  add ( res , ( x + 1 ) * ( get_sum( m ) - get_sum(l * l-1) + mod ) % mod );
  cout << res << ":";
  if( l > 0 ) add ( res , ( l * l -1) %mod * get_sum_2(x)%mod * -1 + mod );
  cout << res << ":";
  add ( res , -par[x] + mod);
  cout << res << ":";
//  add ( res , x + 1 );
  return res;
}

int main () {
  long long m;cin >> m;
  for(int i = 1;i<40;i++) add( par [i] , par[i-1] , (i -1) * i * ( 2 * i -1) / 6 );
//  for(int i = 1;i<MAXN;++i) add(par[i],par[i-1],get_sum_2(i * i - 1));
  for(int i = 0;i<10;i++) cout << par[i] << " " ;cout << endl;
  long long ans = 0;
  for(int i = 0;i<=sqrt(m);i++) cout << get(i,m) << endl;
  for(int i = 0;i<=sqrt(m);i++) add ( ans , get( i , m ) );
  cout << ( 4 * ans ) % mod << endl;
  return 0;
}
