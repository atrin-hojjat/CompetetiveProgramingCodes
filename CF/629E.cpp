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
#include <iomanip>
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
vi tree[MAXN];
ll dp[MAXN];
ll dp2[MAXN];
int sz[MAXN];
int h[MAXN];
int LCA[LOGMAXN][MAXN];
int n;

int dfs_size(int v,int p = 0,int hei = 0) {
  LCA[0][v] = p;
  h[v] = hei++;
  sz[v] = 1;
  for(auto u : tree[v])
    if(u!=p) sz[v] += dfs_size(u,v,hei);
  return sz[v];
}

ll dfs_up(int v,int p = 0) {
  ll dis = 0;
  for(auto u : tree[v]) 
    if(u!=p)
      dis += dfs_up(u,v);
  return (dp[v] = dis) + sz[v];
}

void dfs_down(int v,int p = 0,ll up = 0) {
  dp2[v] = up;
  for(auto u : tree[v]) 
    if(u!=p)
      dfs_down(u,v,up + n-2*sz[u] + dp[v]-dp[u]);
}

void init_LCA() {
  FOR(i,1,LOGMAXN)
    F0R(j,1,n)
      LCA[i][j] = LCA[i-1][LCA[i-1][j]];
}

int get_par(int v,int k) {
  RFOR(i,0,LOGMAXN)
    if((k>>i)&1) v = LCA[i][v];
  return v;
}

int lca(int v,int u) {
  if(h[v]>h[u]) swap(u,v);
  u = get_par(u,h[u]-h[v]);
  if(u==v) return v;
  RFOR(i,0,LOGMAXN)
    if(LCA[i][v] != LCA[i][u])
      v = LCA[i][v],u = LCA[i][u];
  return LCA[0][v];
}

int get_dis(int v,int u) {
  int w = lca(u,v);
  return h[v] + h[u] - 2*h[w];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int m;cin >> n >> m;
  FOR(i,1,n) {
    int x,y;cin >> x >> y;
    tree[x].pb(y);
    tree[y].pb(x);
  }
  dfs_size(1);
  dfs_up(1);
  dfs_down(1);
  init_LCA();
  cout << fixed << setprecision(7) ;
  while(m--) {
    int x,y;cin >> x >> y;
    int w = lca(x,y);
    if(w==y) swap(x,y);
    if(w==x) {
      int nei;
      int neigh = sz[nei = get_par(y,h[y]-h[x]-1)];
      long double ex = 1.0L *(dp2[nei]-n+sz[nei])/(n-neigh) + 1.0L*dp[y]/sz[y];
//      cout <<ex << endl;
      cout << ex + get_dis(x,y) +1 << endl;
      continue;
    }
    long double z =1.0L*dp[x]/sz[x] + 1.0L*dp[y]/sz[y];
    cout << z + get_dis(x,y) + 1 << endl;
  }
	return 0;
}
