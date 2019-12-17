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

const int MAXN = 1e5+6.66;
const int LOGMAXN = 20;
vii tree[MAXN];
int par[MAXN];
int ans[MAXN];
pii RMQ[LOGMAXN][2*MAXN];
int st[MAXN];
int ft[MAXN];
int now;

void dfs1(int v,int h = 0,int pare = 0) {
  st[v] = now;
  RMQ[0][now++] = mp(h,v);

  for(auto u : tree[v])
    if(u.F!=pare)
      dfs1(u.F,h+1,v),RMQ[0][now++] = mp(h,v);

  ft[v] = now;
}

int dfs2(int v,int pare = 0) {
  int ret = par[v];
  for(auto u : tree[v]) 
    if(u.F!=pare)
    {
      int x = dfs2(u.F,v);
      ret += x;
      ans[u.S] += x;
    }
  return ret;
}

void init_rmq() {
  FOR(i,1,LOGMAXN)
    FOR(j,0,now) 
      if(j+(1<<(i-1))<now) RMQ[i][j] = min(RMQ[i-1][j], RMQ[i-1][j+(1<<(i-1))]);
      else RMQ[i][j] = RMQ[i-1][j];
}

int lca(int v,int u) {
  if(u==v) return u;
  int x = min(st[u],st[v]);
  int y = max(st[v],st[u]);
  int lg = log(y-x+1)/log(2);
  return min(RMQ[lg][x],RMQ[lg][y-(1<<lg)+1]).S;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,1,n) {
    int x,y;cin >> x >> y;
    tree[x].pb(mp(y,i));
    tree[y].pb(mp(x,i));
  }
  dfs1(1);
  init_rmq();
  int q;cin >> q;
  while(q--) {
    int x,y;
    cin >> x >> y;
    int w = lca(x,y);
    if(w==x)swap(x,y);
    if(w==y) par[x]++,par[y]--;
    else {
      par[w]-=2;
      par[x]++;
      par[y]++;
    }
  }
  dfs2(1);
  FOR(i,1,n) cout << ans[i] << " ";
  cout << endl;
	return 0;
}
