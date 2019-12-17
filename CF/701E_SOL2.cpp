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

const int MAXN = 2e5+6.66;
int dp[MAXN];
int K ;
bool mark[MAXN];
vi tree[MAXN];
ll ans = 0;

int dfs1(int v,int p = 0) {
  dp[v] = mark[v];
  for(auto u : tree[v])
    if(u!=p)
      dp[v] += dfs1(u,v);
  return dp[v];
}

void calc_dfs(int v,int p = 0) {
  ans += min(dp[v],2*K-dp[v]);
  for(auto u : tree[v])
    if(u!=p)
      calc_dfs(u,v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n >> K;
#if 0
  TEST
#endif
  for(int i = 0;i<2*K;i++) {int x;cin >> x;mark[x] = true;}
  for(int i = 1;i<n;i++) {int x,y;cin >> x >> y;tree[x].pb(y);tree[y].pb(x);}
  dfs1(1);
  calc_dfs(1);
  cout << ans << endl;
	return 0;
}
