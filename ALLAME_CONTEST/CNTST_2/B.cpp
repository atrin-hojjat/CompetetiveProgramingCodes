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

const int MAXN = 506;
const ll  MOD  = 1e9+7;
int dp[2][MAXN][MAXN];
char tab[MAXN][MAXN];

int main() {
	freopen("palpath.in", "r", stdin);
	freopen("palpath.out", "w", stdout);
  int n;cin >> n;
  F0R(i,1,n)F0R(j,1,n) cin >> tab[i][j];
  bool w = false;
  dp[w][1][1] = 1;
  F0R(i,2,n) {
    F0R(j,1,i)
      F0R(k,1,i) {
        dp[!w][j][k] = 1LL*(tab[i-j+1][j]==tab[n-i+k][n-k+1])*1LL*(dp[w][j][k]*1LL + 
            dp[w][j-1][k]*1LL + dp[w][j][k-1]*1LL + dp[w][j-1][k-1]*1LL)%MOD;
      }
    w = !w;
  }
  ll ans = 0;
  F0R(i,1,n) ans = (ans+ dp[w][i][n-i+1])%MOD;
  cout << ans << endl;
	return 0;
}
