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
const int LOGMAXN = 16;
const int SQRTLOGMAXN = 3;
const int SQRTMAXN = 321;
const int SQ = SQRTMAXN;//SQRTLOGMAXN;
ll  sum[MAXN];
int hei[MAXN];
vi tree[MAXN];
int st[MAXN],et[MAXN];
vi timeline[MAXN];
int now;
//ll add[MAXN];
//vii ongoing;
map<int,ll> add;

void dfs(int v,int h = 0,int p = 0) {
  st[v] = ++now;
  timeline[hei[v] = h++].pb(v);
  for(auto u : tree[v])
    if(u!=p)
      dfs(u,h,v);
  et[v] = now;
}

ll relax_dfs(int v,int h = 0,int p = 0) {
  ll ans = add[h];
  for(auto u : tree[v])
    if(u!=p)
      ans += relax_dfs(u,h+1,v);
  sum[v] += ans;
  return ans;
}

void relax() {
  relax_dfs(1);
  add.clear();
//  ongoing.clear();
//  memset(add,0,sizeof add);
}

void query() {
  int v;cin >> v;
  ll ans = sum[v];
//  for(auto x : ongoing) {
  for(auto x : add) {
    if(hei[v]>x.F) continue;
    int cnt = upper_bound(timeline[x.F].begin(),timeline[x.F].end(),v,[](int x,int y){return et[x]<et[y];}) 
      - lower_bound(timeline[x.F].begin(),timeline[x.F].end(),v,[](int x,int y){return st[x]<st[y];});
    ans += cnt*x.S;
  }
  cout << ans << endl;
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
  dfs(1);
  FOR(i,0,m) {
    int x;cin >> x;
    if(x==1) {
      int y;cin >> x >> y;
      add[x]+=y;
//      ongoing.pb(mp(x,y));
    } else query();
    if(m%SQ==0) relax();
  }
	return 0;
}
