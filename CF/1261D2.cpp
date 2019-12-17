#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

const int mod = 998244353;
const int MaxN = 2e5 + 6.66;
int fact[MaxN];
int arr[MaxN];
int ifact[MaxN];

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

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * ans * base % mod;
  return ans;
}

void init() {
  fact[0] = 1;
  for(int i = 1; i < MaxN; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
  ifact[MaxN - 1] = _pow(fact[MaxN - 1], mod - 2);
  for(int i = MaxN - 1; i > 0; i--) ifact[i - 1] = 1ll * i * ifact[i] % mod;
}

vector<long long> calc(int n) {
  vector<long long> v;
  for(int i = 0; i <= n; i++) v.push_back(ifact[i]);
  vector<long long> c = v;
  return FFT::mul(v, c);
}

int main() {
  init();
  FFT::init();
  int n, k; cin >> n >> k;
  int N = 0;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < n; i++) {
    if(arr[i] != arr[(i + 1) % n]) N++;
  }
  vector<long long> res = calc(N);
  int rest = 1ll * fact[N] * _pow(k, n - N) % mod;
  int ans = 0;
  for(int i = 0; i <= N; i++) {
    int r = 1ll * ifact[N - i] * _pow(k - 2, N - i) % mod;
    int x = 0;
    if(i % 2 == 0) {
      x = 1ll * ifact[i / 2] * ifact[i / 2] % mod;
    }
    int t = (res[i] - x + mod) % mod;
    if(t % 2) t += mod;
    t /= 2;
    ans += 1ll * t * r % mod;
    if(ans > mod) ans -= mod;
  }
  ans = 1ll * ans * rest % mod;
  cout << ans << endl;
  return 0;
}
