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
vi tree[MAXN];
bool mark[MAXN];
char ans[MAXN];
int sz[MAXN];

int init_dfs(int v,int p = 0) {
  sz[v] = 1;
  for(auto u : tree[v])
    if(u != p && !mark[u]) sz[v] += init_dfs(u,v);
  return sz[v];
}

int get_dfs(int v,int tot,int us = 0,int p = 0) {
  if(us > tot/2) return -1;
  bool ok = true;
  for(auto u : tree[v])
    if(!mark[u] && u!=p && sz[u] > tot/2) {ok = false;break;}
  if(ok) return v;
  for(auto u : tree[v])
    if(!mark[u] && u!=p)
    {
      int zz = get_dfs(u,tot,us+sz[v]-sz[u],v);
      if(~zz) return zz;
    }
  return -1;
}

void decompose(int x,char ch) {
  init_dfs(x);
  int w = get_dfs(x,sz[x]);
  ans[w] = ch;
  mark[w] = true;
  for(auto ww : tree[w])
    if(!mark[ww])
      decompose(ww,ch+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,1,n) {
    int x,y;cin >> x >> y;
    tree[x].pb(y);
    tree[y].pb(x);
  }
  decompose(1,'A');
  F0R(i,1,n) cout << ans[i] << " ";
  cout <<endl;
	return 0;
}
