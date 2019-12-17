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
typedef pair<pii,int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 50+6.66;
const ll MOD  = 1e9+7;
int deg[MAXN];
ll dp[MAXN][MAXN][MAXN];
ll ans[MAXN][MAXN];
int deg2[MAXN][MAXN];

void initDP1() {
  dp[0][0][0] = 1;
  for(ll k = 0;k<MAXN;k++) for(ll j = 0;j<MAXN;j++) for(ll i = 0;i<MAXN;i++) {
    if(i+j==0) continue;
    if(!j) (dp[i][j][k] = (k>0?dp[i-1][j][k-1]*k%MOD:0LL) + (i>1?(i-1) * dp[i-2][j][k]:0)%MOD )%=MOD;
    else 
      (dp[i][j][k] = (k>1?1LL*dp[i][j-1][k-2]*k*(k-1)/2%MOD :0LL) + (k>0&&j>1&&i<MAXN-1 ? 1LL*(j-1)*dp[i+1][j-2][k-1]*k%MOD :0)
        + (k>0&&i>0?1LL*i*dp[i-1][j-1][k-1]*k%MOD :0) + (j>2 ? 1LL*(j-1)*(j-2)/2 *dp[i+2][j-3][k]%MOD :0)
        + (i>1?1LL*i*(i-1)/2 *dp[i-2][j-1][k]%MOD :0) + (j>1&&i? 1LL*i*(j-1)* dp[i][j-2][k]%MOD:0))%=MOD;
//    cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl; ;
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  initDP1();
  int n;cin >> n;
  for(int i = 1;i<=n;i++) cin >> deg[i];
  for(int i = 1;i<=n;i++)
    for(int j = i;j<=n;j++)
      deg2[i][j] = deg2[i][j-1] + (deg[j]==2);
  ans[n+1][n] = 1;
  for(int j = n;j>1;j--)
    for(int i = j;i<=n;i++) 
      for(int k = 0;k<=min(n-i,deg2[j][i] + 2*(i-j+1-deg2[j][i]));k++) 
        (ans[j][i] += dp[deg2[j][i]][i-j+1-deg2[j][i]][k]%MOD * ans[i+1][i+k] %MOD)%=MOD;
  ans[1][1] = ans[2][1+deg[1]];
  cout << ans[1][1] << endl;
	return 0;
}
