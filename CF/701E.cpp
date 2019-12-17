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
bool mark[MAXN];
vi tree[MAXN];
int sz[MAXN];
int K;

int init_dfs(int v,int p = 0) {
  sz[v] = mark[v];
  for(auto u : tree[v])
    if(u!=p)
      sz[v] += init_dfs(u,v);
  return sz[v];
}

int get_centroid(int v,int up = 0,int p = 0) {
  if(up>K) return -1;
  bool ok = true;
  for(auto u : tree[v])
    if(u!=p && sz[u]>K) {ok =false;break;}
  if(ok)return v;
  for(auto u : tree[v])
    if(u!=p)
    {
      int ww = get_centroid(u,up+sz[v]-sz[u],v);
      if(~ww)
        return ww;
    }
  return -1;
}

ll get_sum(int v,int h = 0,int p = 0) {
  ll ans = 0;
  if(mark[v]) ans += h;
  for(auto u : tree[v])
    if(u!=p)
      ans += get_sum(u,h+1,v);
  return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n >> K;
  FOR(i,0,2*K) {
    int w;cin >> w;
    mark[w] = true;
  }
  FOR(i,1,n) {
    int x,y;cin >> x >> y;
    tree[x].pb(y);
    tree[y].pb(x);
  }
  init_dfs(1);
  int zz = get_centroid(1);
  cout << get_sum(zz,0,0) << endl;
	return 0;
}
