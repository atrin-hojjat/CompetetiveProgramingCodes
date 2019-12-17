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
typedef pair<int,ll> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e5+6.66;
vii tree[MAXN];
vl dis[MAXN];
map<int,ll> mn_dis[MAXN];
map<int,vl> dd[MAXN];
int sz[MAXN];
int par[MAXN];
int PP[MAXN];
bool mark[MAXN];

int size_dfs(int v,int p = 0) {
  if(mark[v]) return 0;
  sz[v] = 1;
  for(auto u : tree[v])
    if(u.F!=p)
      sz[v] += size_dfs(u.F,v);
  return sz[v];
}

int get_centriod(int v,int tot,int p = 0) {
  for(auto u : tree[v])
    if(!mark[u.F] && u.F!=p && sz[u.F]>tot) return get_centriod(u.F,tot,v);
  return v;
}

void init_dis(int v,int c,ll up = 0,int p = 0) {
  dis[c] .pb(up);
  mn_dis[c][v] = up;
  for(auto u : tree[v])
    if(!mark[u.F] && u.F != p)
      init_dis(u.F,c,up+u.S,v);
}

void cc_dis(int v,int r,int c,ll up = 0,int p = 0 ) {
  dd[c][r].pb(up);
  for(auto u : tree[v])
    if(!mark[u.F] && u.F != p)
      cc_dis(u.F,r,c,up+u.S,v);
}

void decompose(int v,int p = -1) {
  size_dfs(v);
  int cent = get_centriod(v,sz[v]/2);
//  dfs_size(cent);
  mark[cent] = true;
  PP[cent] = v;
  par[cent] = p;
  init_dis(cent,cent);
  for(auto u : tree[cent])
    if(!mark[u.F])
      cc_dis(u.F,u.F,cent,u.S,cent);
  sort(dis[cent].begin(),dis[cent].end());
  for(auto u : tree[cent])
    if(!mark[u.F])
      sort(dd[cent][u.F].begin(),dd[cent][u.F].end());
  for(auto u : tree[cent])
    if(!mark[u.F])
      decompose(u.F,cent);
}

int solve(int v,int u,ll l,int ch = -1) {
  if(!~v) return 0;
  ll d = l - mn_dis[v][u];
  int ans = upper_bound(dis[v].begin(),dis[v].end(),d) - dis[v].begin();
  if(~ch) ans -= upper_bound(dd[v][PP[ch]].begin(),dd[v][PP[ch]].end(),d) - dd[v][PP[ch]].begin();
//  cout << ans << endl;
  return ans + solve(par[v],u,l,v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,q;cin >> n >> q;
  FOR(i,1,n) {
    int x,y;ll z; cin >> x >> y >> z;
    tree[x].pb({y,z});
    tree[y].pb({x,z});
  }
  decompose(1);
  while(q--) {
    int x;ll d;
    cin >> x >> d;
    cout << solve(x,x,d) << endl;
  }
	return 0;
}
