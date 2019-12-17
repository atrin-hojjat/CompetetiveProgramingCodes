#ifdef Atrin
  #include <iostream>
  #include <vector>
  #include <math.h>
#else
  #include <bits/stdc++.h>
#endif
using namespace std;

namespace FFT {
  const long long mod = 998244353;
  const int LOG = 22;
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

vector<long long> bpow(vector<long long>&x, int exp) {
  vector<long long> ans = {1};
  for(; exp; exp >>= 1, x = FFT::mul(x, x))
    if(exp & 1) ans = FFT::mul(ans, x);
  return ans;
}

int main() {
  int n; cin >> n;
  FFT::init();
  int t = ceil(log(n));
  cout << t << endl;
  vector<long long> st = {1, 1};
  for(auto x : bpow(st, 1 << t))
    cout << x << " "; cout << endl;
  cout << bpow(st, 1 << t)[n] << endl;
  return 0;
}

