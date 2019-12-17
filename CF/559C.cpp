#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+6.66;
const long long mod = 1e9 + 7;
long long fact[MAXN];
long long ifact[MAXN];
long long ans[MAXN];
pair<int,int> points[MAXN];

long long bpow(long long base,long long exp) {
  long long res = 1;
  for( ; exp ; base = ( base * base ) % mod,exp >>=1 ) if( exp & 1 ) ( res *= base ) %=mod;
  return res;
}

void precalc() {
  fact[0] = 1;
  for(int i = 1;i<MAXN;i++) fact[i] = ( fact[i-1] * i ) % mod;
  ifact[MAXN-1] = bpow(fact[MAXN-1],mod-2);
  for(int i = MAXN-2;i>-1;i--) ifact[i] = ( ifact[i+1] * ( i + 1 ) ) % mod;
}

long long C(int n,int r) {
  if( r > n || r < 0) return 0;
  return ( fact[n] * ifact[r] ) % mod * ifact[n-r] % mod;
}

int main() {
  int H,W,n;cin >> H >> W >> n;
  precalc() ;
  for(int i = 0;i<n;i++) cin >> points[i].first >> points[i].second;
  points[n++] = {H,W};
  sort(points,points+n);
  for(int i = 0;i<n;i++) {
    ans[i] = C( points[i].first + points[i].second - 2,points[i].first - 1 );
    for(int j = 0;j<i;j++) 
      ans[i] = (ans[i] + mod 
          - ( C(points[i].first + points[i].second 
              - points[j].first - points[j].second, points[i].first - points[j].first) * ans[j] ) %mod ) %mod;
  }
  cout << ans [n-1] << endl;
  return 0;
}
