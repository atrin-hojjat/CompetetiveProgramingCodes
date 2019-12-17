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

const int MAXN = 1e6+6.66;
vi tree[MAXN];
int s[MAXN];
int t[MAXN];
int tot;
bool mm[MAXN];
map<int,int> ex;
map<int,int> st[MAXN];
int root[MAXN];
int ROOT;
vi ans;

int dfs_sum(int v) {
  s[v] = t[v];
  for(auto u : tree[v])
    s[v] += dfs_sum(u);
  return s[v];
}

int get_root(int v) {
  return (root[v]? root[v] = get_root(root[v]) : v);
}

void merge(int v,int u) {
  u = get_root(u);
  v = get_root(v);
  if(u==v) return;
  if(st[u].size() > st[v].size()) swap(u,v);
  root[u] = v;
  for(auto w : st[u])
    st[v][w.F] += w.S;
}

void calc(int v) {
  if(ans.size()) return ;
  st[v][s[v]] ++;
  for(auto u : tree[v])
    calc(u),merge(v,u);
  if(s[v]==tot/3)
    if(ex[s[v]] - st[v][s[v]])ans.pb(v);;
  if(ans.size()) mm[v] = true;
}

int get_second(int v,int no) {
  if(v != ROOT &&!mm[v] && s[v] == tot/3) return v;
  else if (v!=ROOT && mm [v] && s[v] == tot*2/3) return v;
  int WW = -1;
  for(auto u : tree[v])
    if(u!=no)
      if(~(WW=get_second(u,no)))return WW;
  return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  int r;
  F0R(i,1,n) {
    int x,y;cin >> x >>y;
    if(!x) r = i;
    tree[x].pb(i);
    t[i] = y;
  }
  dfs_sum(r);
  tot = s[r];
  ROOT = r;
  if(tot%3) goto NOO;
  calc(r);
  if(ans.size()) {
    int ZZ = get_second(r,ans[0]);
    if(~ZZ) {
      cout << ans[0] << " " << ZZ << endl;
      return 0;
    }
  }
NOO:
  cout << -1 << endl;
	return 0;
}
