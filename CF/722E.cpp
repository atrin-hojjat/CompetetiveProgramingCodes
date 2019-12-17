#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <deque>

#define mp                  make_pair
#define F                   first
#define S                   second
#define pb                  push_back
#define FOR(i,j,n)          for(int i=j;i<n;i++)
#define F0R(i,j,n)          for(int i=j;i<=n;i++)
#define RFOR(i,j,n)         for(int i=n-1;i>=j;i--)
#define RF0R(i,j,n)         for(int i=n;i>=j;i--)
#define FOREACH(x,v)        for(auto x:v)
#define ITFOR(it,v)         for(__typeof(v.begin()) it =v.begin();it!=v.end();++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " <<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 2e3+6.66;
const int MAXV = 3e5+6.66;
const int MAXL = 22;
const ll  MOD  = 1e9+7;
pii arr[MAXN];
ll dp[MAXN][MAXL];
ll fact[MAXV];
ll _paths[MAXN][MAXN];
map<int,int> _C_save[MAXV];
int n,m;
bool ADD;

void init_fact() {
  fact[0] = 1;
  FOR(i,1,MAXV)fact[i] = fact[i-1]*i%MOD;
}

ll POW(ll base,ll exp) {
  if(!exp) return 1;
  return POW(base*base%MOD,exp>>1) * (exp&1 ? base : 1) %MOD;
}

ll C(int n,int r) {
  if(_C_save[n][r]) return _C_save[n][r];
  return _C_save[n][r] = fact[n] * POW(fact[r]*fact[n-r]%MOD,MOD-2)%MOD;
}

ll __paths__(pii x,pii y) {
  if(x.F > y.F || x.S > y.S) return 0;
  return C(- (x.F+x.S) + (y.S+y.F),y.F-x.F);
}

void init_paths(int k) {
  for(int i = 0;i<k;i++)
    for(int j = i;j<k;j++) _paths[i][j] = __paths__(arr[j],arr[i]);
  for(int i = 0;i<k;i++) _paths[i][k] = __paths__(arr[i],{n,m});
}

ll paths(int i,int j) { return _paths[min(i,j)][max(j,i)]; }

void calc(int k,int K) {
  pii x = arr[k];
  ll par = 0;
//  cout << k << " : " ;
  for(int l = 0;l<MAXL;(par += dp[k][l])%=MOD,l++) {
    dp[k][l] = paths(k,K);
    for(int i = 0;l!=MAXL-1 && i<k;i++) (dp[k][l] += MOD - (dp[i][l] * paths(i,k))%MOD)%=MOD;
    (dp[k][l] += MOD - par)%=MOD;
//    cout << dp[k][l] << " " ;
  }
//  cout << endl;
}

ll solve(ll *d,int val) {
  ll ans = 0;
  if(!ADD) val = (val+1)/2;
  for(int l = 0;l<MAXL;val=(val+1)/2,l++)
    (ans += d[l] * val) %=MOD;
  return ans ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int k,s;cin >> n >> m >> k >> s;
  FOR(i,0,k) cin >> arr[i].F >> arr[i].S;
  init_fact();
  sort(arr,arr+k,[](pii x,pii y) {return x.F+x.S > y.F + y.S;});
  if(arr[k-1]!=mp(1,1)) ADD = 1,arr[k] = mp(1,1),k++;
  init_paths(k);
  FOR(i,0,k) calc(i,k);
//  cout << solve(dp[k-1],s) << endl;
  ll ans = solve(dp[k-1],s) * POW(__paths__({1,1},{n,m}),MOD-2) %MOD;
  cout << ans << endl;
	return 0;
}
