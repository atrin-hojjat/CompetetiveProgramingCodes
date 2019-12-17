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
vi tree[MAXN];
int arr[MAXN];
int dp1[MAXN];
int dp2[MAXN];
int sz[MAXN];
pii s[MAXN][2];
int n;

int init_dfs(int v,int p = 0) {
  sz[v] = 1;
  for(auto u : tree[v])
    if(u!=p)
      sz[v]+=init_dfs(u,v);
  return sz[v];
}

inline void insert(int v,pii x) {
  FOR(i,0,2)
    if(x>s[v][i])
      swap(s[v][i],x);
}

void dfs_up(int v,int m,int p = 0) {
  dp1[v] = (arr[v]>=m);;
  for(auto u : tree[v]) {
    if(u==p)continue;
    dfs_up(u,m,v);
    if(dp1[v]&&dp1[u]==sz[u]) dp1[v]+= sz[u];
    else if(dp1[v])insert(v,mp(dp2[u],u));
  }
  if(dp1[v])dp2[v] = dp1[v] + s[v][0].F;
}

void dfs_down(int v,int m,int up = 0,int p = 0) {
  if(arr[v] < m) {
//    cout << "\t\t" << v << endl;
    for(auto u : tree[v])
      if(u!=p)
        dfs_down(u,m,0,v);
    return ;
  }
//  cout << v << " " << s[v][0].F << "," << s[v][0].S << " " << s[v][1].F << "," << s[v][1].S << endl;
//  cout << "\t"<< v << " " << up << " " << p << endl;
  if(up == n-sz[v]) dp1[v] += up;
  else insert(v,mp(up,p));
  dp2[v] = dp1[v]+s[v][0].F;
//  cout << v << " " << s[v][0].F << "," << s[v][0].S << " " << s[v][1].F << "," << s[v][1].S << endl;
  for(auto u : tree[v])
    if(u!=p)
      dfs_down(u,m,dp2[v] - (sz[u]==dp1[u]?dp1[u]:(u==s[v][0].S?s[v][0].F-s[v][1].F:0)),v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int k;cin >> n >> k;
  F0R(i,1,n) cin >> arr[i];
  FOR(i,1,n) {
    int x,y;cin >> x >> y;
    tree[x].pb(y);
    tree[y].pb(x);
  }
  init_dfs(1);
  int l = 1,r = 1e6+1;
  while(l<r) {
    memset(dp1,0,sizeof dp1);
    memset(dp2,0,sizeof dp2);
    FOR(i,0,MAXN) s[i][1] = s[i][0] = mp(0,0);
    int mid = l+(r-l+1)/2;
    dfs_up(1,mid);
    dfs_down(1,mid);
    bool x = false;
    F0R(i,1,n) x|=dp2[i]>=k;
//    cout << mid << endl;
//    F0R(i,1,n) cout << dp1[i] << " " ;cout << endl;
//    F0R(i,1,n) cout << dp2[i] << " " ;cout << endl;
    if(x) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
	return 0;
}
