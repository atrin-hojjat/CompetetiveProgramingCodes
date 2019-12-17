#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 6e5 + 6.66;
const int mod = 998244353;
const int Max = 6;
int fact[MaxN];
int ifact[MaxN];
int dp[Max][MaxN];
int a[MaxN];
int b[MaxN];
int c[MaxN];
int t[2][MaxN];
int ans[MaxN];


int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * base * ans % mod;
  return ans;
}

void init() {
  fact[0] = 1;
  for(int i = 1; i < MaxN; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
  ifact[MaxN - 1] = _pow(fact[MaxN - 1], mod - 2);
  for(int j = MaxN - 1; j > 0; j--) ifact[j - 1] = 1ll * ifact[j] * j % mod;
}

int C(int n, int r) {
  if(n < r || r < 0) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

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

  void fft( vector<int> & x ,int lev ) {
    int L = 1 << lev;
    for( int i = 0;i<L;i++ ) F[0][rev[i] >> ( LOG - lev ) ] = x[i];
    int c = 0,cc = 1;
    for(int l = 0;l<lev;l++ ) {
      int len = 1 << l;
      for(int st = 0;st < L; st += ( len << 1 ) )
        for(int i = 0;i<len;i++)
        {
          int xx = 1LL * F[c][st + len + i] * wp[ i << (LOG - 1 - l ) ] % mod;
          F[cc][st + i] = ( 0ll + xx + F[c][st + i] ) % mod;
          F[cc][st + len + i] = ( 0ll + F[c][st + i] - xx + mod ) % mod;
        }
      swap(c,cc);
    }
    for(int i = 0;i<L;i++) x[i] = F[c][i];
  }

  vector<int> mul ( vector<int> & a,vector<int> & b ) {
    int sz = 1,xx = 0;
    while( sz < max( a.size() , b.size() ) ) sz <<= 1,xx++;
    sz <<= 1,xx++;;
    a.resize(sz),b.resize(sz);
    vector<int> res = vector<int> ( sz , 0 ) ;
    fft( a ,xx), fft ( b ,xx);
    for(int i = 0;i<sz;i++) a[i] = 1ll * a[i] * b[i] % mod;
    fft( a ,xx);
    int revN = 1;
    for( int i = 0;i<xx;i++ ) {
      if( revN & 1 ) revN += mod;
      revN /= 2;
    }
    for(int i = 0;i<sz;i++) 
      res[i] = ( 1ll * a[i] * revN )  % mod;
    reverse( res.begin() +1,res.end() );
    return res;
  }
};

vector<int> res[Max];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, k; cin >> n >> k;

  for(int i = 0; i < n; i++) cin >> a[i];
  for(int j = 0; j < k; j++) cin >> b[j];
  for(int k = 0; k < n; k++) c[a[k]]++;
  for(int i = 1; i < MaxN; i++) {
    t[0][i] = t[0][i - 1];
    t[1][i] = t[1][i - 1];
    t[c[i] > 1][i] += (c[i] > 0);
  }
  init();
  FFT::init();
  for(int i = 0; i < k;  i++) {
    int B = t[0][b[i] - 1];
    int A = 2 * t[1][b[i] - 1];
    vector<int> first;
    vector<int> second;
    for(int i = 0; i <= A; i++)
      first.push_back(C(A, i));
    for(int j = 0, t = 1; j <= B; j++, t += t) {
      if(t >= mod) t -= mod;
      second.push_back(1ll * C(B, j) * t % mod);
    }
    res[i] = FFT::mul(first, second);
  }
  int Q; cin >> Q;
  while(Q--) {
    int x; cin >> x;
    int ans = 0;
    for(int i = 0; i < k; i++) {
      int s = x - 2 * b[i] - 2;
      s /= 2;
      if(s >= 0 && s < res[i].size()) ans = (ans + res[i][s]) % mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
