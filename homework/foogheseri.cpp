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
ll seg[MAXN*2];
int st[MAXN];
int et[MAXN];
int T[MAXN];
int C[MAXN];
ll ans[MAXN];
int now;

void dfs(int v,int p = 0) {
  st[v] = ++now;
  for(auto u : tree[v])
    if(p!=u)
      dfs(u,v);
  et[v] = 1+now;
}

ll get(int l,int r) {
  ll ans = 0;
  for(l+=MAXN,r+=MAXN;l<r;l>>=1,r>>=1){
    if(l&1) ans+=seg[l++];
    if(r&1) ans+=seg[--r];
  }
  return ans;
}

void add(int x,ll val) {
  for(seg[x+=MAXN] = val;x>1;x>>=1)seg[x>>1] = seg[x] + seg[x^1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  int r;
  F0R(i,1,n) {
    int p;cin >> p >> C[i] >> T[i];
    if(~p)tree[p].pb(i);
    else r = i;
  }
  dfs(r);
  auto cmp = [](int x,int y) {return C[x]<C[y];};
  multiset<int,decltype(cmp)> S(cmp);
  vi V;
  F0R(i,1,n) S.insert(i);
  int prv = -1;
  for(auto x : S) {
//    cout << C[x] << " " ;
    if(C[x]!=prv) 
    {
      for(auto s : V)
        add(st[s],T[s]);
      V.clear();
      prv = C[x];
    }
    ans[x] = get(st[x],et[x]);
    V.pb(x);
//    add(st[x],T[x]);
  }
  F0R(i,1,n) cout << ans [i] << endl;
	return 0;
}
