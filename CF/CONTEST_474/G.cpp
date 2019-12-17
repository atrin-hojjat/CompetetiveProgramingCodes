#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const long long mod = 998244353;
long long fact[MAXN];
long long rfact[MAXN];
namespace FFT {
  const long long mod = 998244353;
  const int LOG = 20;
  const int MAX = 1<<LOG;
  long long W;
  long long Wrev;
  long long rev[MAX];
  long long wp[MAX];
  long long F[2][MAX];
  long long bpow ( long long base, long long exp , long long mod) {
    long long res = 1;
    for(;exp;exp>>=1,base = ( base * base ) % mod ) if ( exp & 1 ) res = ( res * base )  % mod;
    return res;
  }

  void init() {
    W = 2;
    for ( ;; ) {
      int cc = W;
      for(int t = 1;t<LOG;t++) cc = ( 1LL * cc * cc ) % mod;
      if( cc == mod - 1 ) break;
      W++;
    }
    Wrev = bpow(W,mod-2,mod);
    wp[0] = 1;
    for(int i = 1;i<MAX;i++) wp[i] = ( 1LL * wp[i-1] * W ) % mod;
    for(int mask = 1;mask < MAX;mask ++ ) {
      rev[mask] = rev[mask ^ ( mask & -mask ) ] ^ ( 1 << ( LOG - 1 - __builtin_ctz( mask ) ) ) ;
    }
  }

  void fft( vector<long long> & x ,int lev ) {
    int L = 1 << lev;
    for( int i = 0;i<L;i++ ) F[0][rev[i] >> ( LOG - lev ) ] = x[i];
    int c = 0,cc = 1;
    for(int l = 0;l<lev;l++ ) {
      int len = 1 << l;
      for(int st = 0;st < L; st += ( len << 1 ) )
        for(int i = 0;i<len;i++)
        {
          long long xx = 1LL * F[c][st + len + i] * wp[ i << (LOG - 1 - l ) ] % mod;
          F[cc][st + i] = ( xx + F[c][st + i] ) % mod;
          F[cc][st + len + i] = ( F[c][st + i] - xx + mod ) % mod;
        }
      swap(c,cc);
    }
    for(int i = 0;i<L;i++) x[i] = F[c][i];
  }

  vector<long long> mul ( vector<long long > & a,vector<long long> & b ) {
    int sz = 1,xx = 0;
    while( sz < max( a.size() , b.size() ) ) sz <<= 1,xx++;
    sz <<= 1,xx++;;
    a.resize(sz),b.resize(sz);
    vector<long long> res = vector<long long> ( sz , 0 ) ;
    fft( a ,xx), fft ( b ,xx);
    for(int i = 0;i<sz;i++) a[i] = ( a[i] * b[i] ) % mod;
    fft( a ,xx);
    long long revN = 1;
    for( int i = 0;i<xx;i++ ) {
      if( revN & 1 ) revN += mod;
      revN /= 2;
    }
    for(int i = 0;i<sz;i++) 
      res[i] = ( a[i] * revN )  % mod;
    reverse( res.begin() +1,res.end() );
    return res;
  }
};

long long bpow( long long base, long long exp ,long long mod) {
  if ( !exp ) return 1;
  return ( exp & 1 ? base : 1 ) * bpow( base * base % mod, exp >> 1 ,mod) % mod;
}

void init_fact( ) {
  fact[0] = 1;
  for(int i = 1;i<MAXN;i++) fact[i] = fact[i-1] * i %mod;
  rfact[MAXN - 1] = bpow ( fact[MAXN-1], mod - 2 ,mod);
  for(int i = MAXN - 2;i>-1;i--) rfact[i] = rfact[i+1] * ( i + 1 ) % mod;
}

long long C ( int n,int r ) {
  if ( r == n ) return 1 ;
  if ( r > n ) return 0;
  return  ( fact[n] * ( rfact[r] * rfact[n-r] % mod) % mod );
}

vector<long long> get_stirling ( int n,int st = 0 ) {
  if( n == 1 ) {
    return vector<long long> ({st,1});
  }
  vector<long long> v0 = get_stirling ( n/2,st );
  vector<long long> v1 = get_stirling ( n - n/2,st + n/2);
  vector<long long> ret = FFT::mul(v0,v1);
  return ret;
}

int main() {
  int A,B,N;cin >> N >> A >> B;
  if( A== 0 || B == 0 ) {
    cout << 0 << endl;
    return 0;
  }
  if( A + B > 1 + N ) {
    cout << 0 << endl;
    return 0;
  }
  if ( A== 1 && B == 1 ) {
    cout << ( N == 1 ? 1 : 0 ) << endl;
    return 0;
  }
  init_fact();
  FFT::init();
  vector<long long> stirling = get_stirling ( N - 1 ) ;
  long long ans = stirling[A + B - 2] * C ( A + B -2 ,A -1 ) % mod;
  cout << ans << endl;
  return 0;
}
