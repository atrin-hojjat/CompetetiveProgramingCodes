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

const int MAXN = 3e5+6.66;
const int LOGMAXN = 20;
int LCA[LOGMAXN][MAXN];
int lp[2];
int cnt[MAXN];
int h[MAXN];
int root[MAXN];
map<pii,int> __save__;
map<int,int> hcnt[MAXN];

int get_par(int v,int k) {
  RFOR(i,0,LOGMAXN)
    if((k>>i)&1)
      v = LCA[i][v];
  return v;
}

int lca(int u,int v) {
#define LCA_SAVE(A,B) __save__[mp(A,B)]
  if(h[v]>h[u]) swap(u,v);
  if(LCA_SAVE(u,v)) return LCA_SAVE(u,v);
  u = get_par(u,h[u]-h[v]);
  if(u==v) return u;
  RFOR(i,0,LOGMAXN)
    if(LCA[i][u] != LCA[i][v])
      u = LCA[i][u],v = LCA[i][v];
  return LCA_SAVE(u,v) = LCA[0][v];
#undef LCA_SAVE//(A,B)
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int m;cin >> m;
  lp[1] = lp[0] = 1;
  cnt[1] = 1;
  h[1] = 0;
  int cur = 0;
  int ans = 1;
  int n = 1;
  while(m--) {
    int x;cin >> x;
    LCA[0][++n] = x;
    h[n] = h[x]+1;
    if(h[n]==1)
      root[n] = n;
    else root[n] = root[x];
    hcnt[1][h[n]]++;
    hcnt[root[x]][h[n]]++;
    FOR(i,1,LOGMAXN)
      LCA[i][n] = LCA[i-1][LCA[i-1][n]];
#define DIS(a,b) h[a]+h[b] - 2*h[lca(a,b)]
    int mx = max(DIS(lp[0],n) ,DIS(lp[1],n));
//    cout << n << " " << cur << " " << lp[0] << " " << lp[1] << " " << mx << " " << lca(n,lp[1]) << " " << lca(n,lp[0]) << endl;
    if(mx==cur) {
      int chs[2] = {0,0};
      ans ++;
      FOR(i,0,2) 
        if(DIS(lp[i],n)==cur)
          ( cnt[n] = cnt[lp[!i]] ),chs[i]++;
      cnt[lp[0]] += chs[0];
      cnt[lp[1]] += chs[1];
    } else if(mx>cur){
      ans = 1+hcnt[1][w-h[n]];

    }
//    cout << lp[0] << " " << cnt[lp[0]] << " " << lp[1] << " " << cnt[lp[1]] << endl;
    cout << ans << endl;
#undef DIS//(a,b)
  }
	return 0;
}
