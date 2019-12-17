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
int root[MAXN];
int sz[MAXN];
bool mark[MAXN];
vector<int> g[MAXN];

int get_root(int v) {
  return (root[v] ? root[v] = get_root(root[v]) : v) ;
}

int merge(int v,int u) {
  int rv = get_root(v);
  int ru = get_root(u);
  if(rv == ru) return 0;
  int ret = sz[ru];
  if(sz[rv] < sz[ru]) swap(rv,ru);
  root[ru] = rv;
  sz[rv] += sz[ru];
  return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  set<pair<int,int>,greater<pair<int,int>>> ss;
  for(int i = 0;i<n;i++) {
    int x;cin >> x;
    ss.insert({x,i+1});
  }
  while(m--) {
    int x,y;cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i<=n;i++) sz[i] = 1;
  long double ans = 0,tmp = 2.0L /(1LL * n*(n-1));
  for(auto w : ss) {
    int v = w.S;
    long double cnt = 0;
    long double aa = 0;
    mark[v] = true;
    for(auto u : g[v]) {
      if(!mark[u]) continue;
      int zz = merge(v,u);
      aa += (1+cnt)*zz;
      cnt += zz;
    }
    ans += w.F * aa * tmp;
  }
  cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
