#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
long long par1[MAXN];
long long arr[MAXN];
long long a [MAXN];
int D,B;

int calc ( int n ) {
  long long tmp = 0;
  int ans = 0;
  for(int i = 1;i<=n;i++) {
    if( par1[ min( 1LL * MAXN -1 , 1LL * ( D + 1 ) * i ) ] - par1[i] >= tmp + B - a[i] ) tmp += B - a[i],ans ++ ;
    else tmp -= a[i];
    if( tmp < 0 ) a[i+1] -= tmp,tmp = 0;
  }
  return n - ans;
}

int calc_r ( int n ,long long x ) {
  x = 1LL * n * B - x;
  int N = n >> 1;
  long long W = 1LL * n * B - x;
  memset(a,0,sizeof a ) ;
  for(int i = 1;i<=N;i++) {
    if( W <= 0 ) break;
    a[i] = min(arr[n - i + 1 ] , W);
    W -= a[i];
  }
  memset(par1,0,sizeof par1);
  for(int i = 1;i<=n;i++) par1[i] = min( x, par1[i-1] + arr[n - i + 1] ) ;
  for(int i = n +1 ;i<MAXN;i++) par1[i] = par1[i-1];
  return calc( N ) ;
}

int calc_l ( int n ,long long x ) {
  int N = ( n + 1 ) >> 1;
  long long W = x;
  memset(a,0,sizeof a ) ;
  for(int i = 1;i<=N;i++) {
    if( W <= 0 ) break;
    a[i] = min( W, arr[i] ) ;
    W -= a[i];
  }
  memset(par1,0,sizeof par1);
  for(int i = 1;i<MAXN;i++) par1[i] = min( x,par1[i-1] + arr[i]);
  return calc( N ) ;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n;cin >> n >> D >> B;
  for(int i = 1;i<=n;i++) cin >> arr[i] ;
  long long l = 0,r =  1LL * n * B;
  while( l < r ) {
    long long mid = ( l + r + 1) >> 1;
    if( calc_r(n,mid) - calc_l(n,mid) <= 0 ) l = mid;
    else r = mid - 1;
  }
  cout << min( max( calc_r(n,l),calc_l(n,l) ) , max( calc_r(n,l+1),calc_l(n,l+1) ) ) << endl;
  return 0;
}
