#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
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

const int MAXN = 1e5+6.66;
const int LOGMAXN = 20;
vii tree[MAXN];
double dp_up[MAXN];
double dp_down[MAXN];
double sum[MAXN];
double LCA_up[LOGMAXN][MAXN];
double LCA_down[LOGMAXN][MAXN];
int LCA[LOGMAXN][MAXN];
int h[MAXN];

double dfs_down(int v,int p = 0,int hei = 0) {
  LCA[0][v] = p;
  h[v] = hei;
  double T = 1.0/tree[v].size();
  for(auto u : tree[v])
    if(u.F == p)
      dp_up[v] += u.S;
    else {
      double x = dfs_down(u.F,v,hei+1);
      sum[v] += x;
      dp_up[v] += (u.S + x);
    }
  return dp_up[v];
}

void dfs_up(int v,int p = 0,double wp = 0,double up = 0) {
  for(auto u : tree[v])
    if(u.F != p) {
      dp_down[u.F] = up + dp_up[v] - dp_up[u.F];
      dfs_up(u.F,v,u.S,dp_down[u.F]);
    }
}

void init_lca(int n) {
  F0R(i,1,n)
    LCA_up[0][i] = dp_up[i],LCA_down[0][i] = dp_down[i];
  FOR(i,1,LOGMAXN)
    F0R(j,1,n)
    {
      LCA[i][j] = LCA[i-1][LCA[i-1][j]];
      LCA_up[i][j] = LCA_up[i-1][j] + LCA_up[i-1][LCA[i-1][j]];
      LCA_down[i][j] = LCA_down[i-1][j] + LCA_down[i-1][LCA[i-1][j]];
    }
}

int get_par(int v,int k) {
  for(int i = 0;i<LOGMAXN;i++,k>>=1)
    if(k&1)
      v = LCA[i][v];
  return v;
}

int lca(int v,int u) {
  if(h[v] > h[u]) swap(u,v);
  u = get_par(u,h[u]-h[v]);

  if(u==v) return v;

  FOR(i,0,LOGMAXN)
    if(LCA[i][u] != LCA[i][v])
      u = LCA[i][u],v = LCA[i][v];

  return LCA[0][u];
}
#define GET_SUM_FUNC(x) \
double get_sum_##x(int v,int k) { \
  double ans = 0; \
  for(int i=0;i<LOGMAXN;i++,k>>=1) \
    if(k&1) \
      ans += LCA_##x[i][v],v = LCA[i][v];\
  return ans;\
}
GET_SUM_FUNC(up);
GET_SUM_FUNC(down);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,q;cin >> n >> q;
  FOR(i,1,n) {
    int x,y,z;cin >> x >> y >> z;
    tree[x].pb({y,z});
    tree[y].pb({x,z});
  }
  dfs_down(1);
  dfs_up(1);
  init_lca(n);
//  F0R(i,1,n) cout << dp_up[i] << " " << dp_down[i] << endl;
  while(q--) {
    int x,y;cin >> x >> y;
    int w = lca(x,y);
    cout << fixed << setprecision(8) << get_sum_up(x,h[x]-h[w]) + get_sum_down(y,h[y]-h[w]) << endl;;
  }
	return 0;
}
