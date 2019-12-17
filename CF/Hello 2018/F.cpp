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

const ll MOD = 998244353;
const int MAXN = 2e3+6.66;
ll dp[MAXN][MAXN];
ll dp_clique[MAXN];
ll ans[MAXN];

ll POW(ll base,ll exp) {
  if(!exp) return 1;
  return POW(base*base%MOD,exp>>1) * (exp&1?base:1) %MOD;
}

inline ll inv(ll x) { return POW(x,MOD-2); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,a,b;cin >> n >> a >> b;
  ll p = a * inv(b)%MOD;
  ll pp = (b-a) * inv(b)%MOD;
  dp[1][1] = dp[1][0] = 1;
  for(int i = 2;i<=n;i++) {
    dp[i][0] = 1;
    for(int j = 1;j<=i;j++)
      (dp[i][j] = dp[i-1][j-1] * POW(p,i-j) %MOD + dp[i-1][j] * POW(pp,j) %MOD ) %=MOD; 
  }
  dp_clique[1] = 1;
  for(int i = 2;i<=n;i++) {
    dp_clique[i] = 1;
    for(int j = 1;j<i;j++)
      (dp_clique[i] += MOD - dp_clique[j] * dp[i][j] %MOD) %=MOD;
  }
  ans[0] = ans[1] = 0;
  ans[2] = 1;
  for(int i = 3;i<=n;i++) {
    for(int j = 1;j<i;j++)
      (ans[i] += dp_clique[j] * dp[i][j]%MOD * (j*(j-1+2*(i-j))/2 + ans[i-j] + ans[j])%MOD) %=MOD;
    (ans[i] += dp_clique[i] * dp[i][i]%MOD * i*(i-1)/2)%=MOD;
    (ans[i] *= inv(MOD + 1 - dp_clique[i]))%=MOD;
  }
  cout << ans[n] << endl;
	return 0;
}
