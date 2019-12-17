#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+6.66;
const int LOG = 20;
const int MAX = 1<<LOG;
int cnt[10];

namespace FFT {
  const long long mod = 998244353;
  long long W;
  long long Wrev;
  long long wl[MAX];
  int rev[MAX];
  long long F[2][MAX];
  bool invert = false;

  long long bpow ( long long base,long long exp ) {
    long long ans = 1;
    for( ; exp ; exp >>= 1 ,base = ( base * base ) % mod ) if( exp & 1 ) (ans *= base) %=mod;
    return ans;
  }

  void init () {
    W = 2;
    for ( ;; ) {
      long long cc = W;
      for(int i = 1;i<LOG;i++) cc = ( cc * cc ) % mod;
      if( cc == mod -1 ) break;
      W++;
    }
    Wrev = bpow( W, mod - 2 );
    wl[0] = 1;
    for(int i = 1;i<MAX;i++) wl[i] = ( wl[i-1] * W ) %mod;
    for(int mask = 1;mask < MAX; mask ++ )
      rev[mask] = rev[mask ^ ( mask & - mask ) ] ^ ( 1<< (LOG - __builtin_ctz ( mask ) - 1 ) );
  }

  void fft ( vector<long long> & a ,int lev) {
    int L = 1 << lev;
    for( int i = 0;i<L;i++) F[0][rev[i] >> ( LOG - lev ) ] = a[i];
    int c = 0,cc = 1;
    for(int l = 0;l<lev;l++) {
      int len = 1<< l;
      for(int st = 0;st<L;st += ( len << 1 )) 
        for(int i = 0;i<len;i++) {
          long long z = F[c][i + st + len] * wl[ i << ( LOG -1 - l ) ] %mod ;
          F[cc][i + st] = ( F[c][i + st] + z ) % mod;
          F[cc][i + st + len] = ( F[c][i + st] - z + mod ) % mod;
        }
      swap( c, cc ) ;
    }
    for(int i = 0;i<L;i++) a[i] = F[c][i];
  }

  vector<long long> mul ( vector<long long> a,vector<long long> b ) {
    int sz = 1,xx = 0;
    while ( sz < max( a.size() , b.size()  ) ) sz <<= 1,xx++;
    sz <<=1,xx ++;
    a.resize( sz ) ,b. resize( sz ) ;
    vector<long long> res = vector < long long > ( sz , 0 );
    fft( a , xx),fft ( b , xx) ;
    for(int i = 0;i<sz;i++) a[i] = ( a[i] * b[i] ) % mod;
    fft( a , xx);
    long long revN = 1;
    for(int i = 0;i<xx;i++) {
      if( revN & 1 ) revN += mod;
      revN /= 2;
    }
    for(int i = 0;i<sz;i++) res[i] = ( a[i] * revN ) % mod;
    reverse(res.begin() +1,res.end()) ;
    return res;
  }
};

int main () {
  ios::sync_with_stdio(false );
  cin.tie(NULL),cout.tie(NULL);
  int n,m,k;cin >> n >> m >> k;
  string a,b;cin >> a >> b;
  FFT::init();
  int I = 0;
  vector<long long> res[ 4 ] ;
  for(char ch : {'A','T','C','G'} ) {
    vector<long long> s ( a.size() +1, 0 ),t ( b.size() , 0 );
    for(int i = 0;i<a.size();i++) 
      if( a[i] == ch ) 
        s[max( 0 , i - k ) ] +=1,s[min((int) a.size() ,i + k + 1)]-=1;
    long long sm = 0;
    for( auto &w : s ) w = ( 0<( sm += w ));
    for(int i = 0;i<b.size();i++) t[i] = ( b[b.size() -1 - i] == ch ) ,cnt[I] += t[i];
    res[I++] = FFT::mul( s, t );
  }
  int ans = 0;
  for(int i = 0;i<res[0].size();i++)
    ans += ( ( res[0][i] == cnt[0] || !cnt[0] )
        && ( res[1][i] == cnt[1] || !cnt[1] ) 
        && ( res[2][i] == cnt[2] || !cnt[2] )
        && ( res[3][i] == cnt[3] || !cnt[3] ));
  cout << ans << endl;
  return 0;
}
