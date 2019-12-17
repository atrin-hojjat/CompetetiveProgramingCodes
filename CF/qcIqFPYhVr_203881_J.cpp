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
int sz[MAXN];
bool mark[MAXN];

int dfs_size(int v,int p = 0) {
  if(mark[v]) return 0;
  sz[v] = 1;
  for(auto u : tree[v])
    if(p!=u)
      sz[v] += dfs_size(u,v);
  return sz[v];
}

int get_centriod(int v,int tot,int p = 0,int up = 0) {
  if(up>tot/2) return -1;
  int ok = v;
  for(auto u : tree[v])
    if(!mark[u] && u!=p && sz[u]>tot/2) ok = get_centriod(u,tot,v,up+sz[v]-sz[u]);
  return ok;
}

void solve(int v) {
  dfs_size(v);
  int w = get_centriod(v,sz[v]);
  mark[w] = true;
  cout << w << endl;
  int stat;cin >> stat;
  if(!stat) return ;
  solve(stat);
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
  solve(1);
	return 0;
}
