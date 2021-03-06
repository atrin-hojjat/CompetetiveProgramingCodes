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

const int MAXN = 1e5+ 6.66;
const int LOGMAXN = 20;
const int SQRT = 333.666;
pii rmq[LOGMAXN][2*MAXN];
int h[MAXN];
int ans[MAXN];
vi ongoing;
int st[MAXN],et[MAXN];
int now;
vi tree[MAXN];

void dfs(int v,int hei=0,int par = 0) {
  h[v] = hei;
  ans[v] = h[v];
  rmq[0][st[v] = ++now] = mp(h[v],v);

  for(auto u : tree[v])
    if(u!=par)
      dfs(u,hei+1,v),rmq[0][++now] = mp(h[v],v);
  et[v] = now;
}

void init_rmq() {
  FOR(i,1,LOGMAXN)
    F0R(j,1,now)
      if((1<<(i-1))+j<=now)
        rmq[i][j] = min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
      else rmq[i][j] = rmq[i-1][j];
}

int lca(int u,int v) {
  if(u==v) return u;
  if(st[v]<st[u]) swap(u,v);
  int lg = log(st[v]-st[u]+1)/log(2);
  return min(rmq[lg][st[u]],rmq[lg][st[v]-(1<<lg)+1]).S;
}

void query() {
  int x,v; cin >> x >> v;
  if(x-1) {
    int A = ans[v];
    for(auto u : ongoing) 
      A = min(A,h[u]+h[v]-2*h[lca(u,v)]);
    cout << A << endl;
  } else ongoing.pb(v);
}

void relax() {
  queue<pii> q;
  for(auto u : ongoing)
    q.push(mp(u,0));
  bool*mark = new bool[MAXN]();
  while(q.size()) {
    pii x = q.front();q.pop();
    ans[x.F] = min(ans[x.F],x.S);
    for(auto u : tree[x.F])
      if(!mark[u])
        mark[u] = true,q.push(mp(u,x.S+1));
  }
  ongoing.clear();
  delete[] mark;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  for(int i = 1;i<n;i++) {
    int x,y;cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  dfs(1);
  init_rmq();
  FOR(i,0,m) {
    query();
    if(i%SQRT==0) relax();
  }
	return 0;
}
