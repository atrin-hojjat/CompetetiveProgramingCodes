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
vi tree[MAXN];
pii RMQ[LOGMAXN][MAXN*2];
int eulerian[MAXN*2];
int st[MAXN];
int ft[MAXN];
int h[MAXN];
int now;

void dfs(int v,int hei = 0,int p = 0) {
  h[v] = hei;
  RMQ[0][++now] = mp(hei,v);
  st[v] = now;

  for(auto x : tree[v])
    if(x!=p) 
      dfs(x,hei+1,v),RMQ[0][++now] = mp(hei,v);
  ft[v] = now;
}

void init_rmq(int n) {
  FOR(i,1,LOGMAXN)
    FOR(j,1,2*n)
      if((1<<i)+j<=2*n) RMQ[i][j] = min(RMQ[i-1][j],RMQ[i-1][j+(1<<(i-1))]);
      else RMQ[i][j] = RMQ[i-1][j];
}

int lca(int v,int u) {
  int x = min(st[v],st[u]);
  int y = max(st[v],st[u]);
  if(x==y) return v;
  int lg = log(y-x+1)/log(2);
  return min(RMQ[lg][x],RMQ[lg][y-(1<<lg)+1]).S;
}

pii lcap(int v,int u) {
  int x = min(st[v],st[u]);
  int y = max(st[v],st[u]);
  if(x==y) return mp(h[v],v);
  int lg = log(y-x+1)/log(2);
  return min(RMQ[lg][x],RMQ[lg][y-(1<<lg)+1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,q;cin >> n >> q;
  F0R(i,2,n) {
    int x;cin >> x; 
    tree[x].pb(i);
  }
  dfs(1);
  init_rmq(n);
  while(q--) {
    int a[3];cin >> a[0] >> a[1] >> a[2];
    int ans = 0;
#define A(x)  a[(x+i)%3]
    for(int i = 0;i<3;i++) {
      int x = lca(A(1),A(2));
      int w = lca(A(0),x);
      if(w==x) {
        pii z = max(lcap(A(0),A(1)) ,lcap(A(0),A(2))); 
        ans = max(ans,-z.F+h[A(0)]+1);
      } else
        ans = max(ans,-2*h[w]+h[x]+h[A(0)]+1);
    }
#undef A//(x)
    cout << ans << endl;
  }
	return 0;
}
