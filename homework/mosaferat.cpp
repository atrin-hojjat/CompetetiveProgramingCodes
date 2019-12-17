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
const int LOGMAXN = 20;
vi tree[MAXN];
vi g[MAXN];
pii RMQ[LOGMAXN][2*MAXN];
int st[MAXN],et[MAXN];
int dp1[MAXN];
int now;
set<int> ans;

void rmq_dfs(int v = 1,int h = 0,int p = 0) {
  st[v] = ++now;
  RMQ[0][now] = mp(h,v);
  dp1[v] = 0;

  for(auto u : tree[v])
    if(u!=p)
      rmq_dfs(u,h+1,v),RMQ[0][++now] = mp(h,v);
  et[v] = now;
}

void init_rmq() {
  rmq_dfs();
  FOR(i,1,LOGMAXN)
    F0R(j,1,now)
      if(j+(1<<i)<=now) RMQ[i][j] = min(RMQ[i-1][j],RMQ[i-1][j+(1<<(i-1))]);
      else RMQ[i][j] = RMQ[i-1][j];
}

int lca(int u,int v) {
  if(u==v) return v;
  if(st[v]>st[u])swap(u,v);
  int lg = log(st[u]-st[v]+1)/log(2);
  return min(RMQ[lg][st[v]],RMQ[lg][st[u]-(1<<lg)+1]).S;
}

int lca_s(int u,int v) {
  pii cur = RMQ[0][st[u]];
  int pos = st[u];
  RFOR(i,0,LOGMAXN)
    if(pos+(1<<i)<=now && min(cur,RMQ[i][pos]).F>RMQ[0][st[v]].F)
      cur = min(cur,RMQ[i][pos]),pos += 1<<i;
//  cout << cur.S << endl;
  return cur.S;
}

int dfs_up(int v = 1,int p = 0) {
  int tmp;
  int ans = 0;
  for(auto u : g[v])
    if((tmp=lca(u,v))!=v && tmp!=u)
      ans ++,dp1[v] += 2;
    else if(tmp == v) dp1[lca_s(u,v)]--;
    else dp1[v]++;
  for(auto u : tree[v])
    if(u!=p)
      ans += dfs_up(u,v);
  return ans;
}

void dfs_down(int val,int v = 1,int p = 0) {
  val -= dp1[v];
//  cout << v << " " << val << endl;
  if(val == 0) ans.insert(v);
  for(auto u : tree[v])
    if(u!=p)
      dfs_down(val,u,v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  FOR(i,1,n) {
    int x,y;cin >> x >> y;
    tree[x].pb(y);
    tree[y].pb(x);
  }
  FOR(i,0,m-n+1) {
    int x,y;cin >> x >> y;
    g[x].pb(y);
    g[y].pb(x);
  }
  init_rmq();
//  F0R(i,1,now) cout << RMQ[0][i].S << " " ;cout << endl;
  dfs_down(dfs_up());
  if(ans.size()) 
    for(auto x : ans)
      cout << x << " " ;
  else cout << -1 ;
  cout << endl;
	return 0;
}
