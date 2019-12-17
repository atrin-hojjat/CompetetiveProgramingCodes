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
#define int long long
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

const int MAXN =1e5+6.66;
vii tree[MAXN];
int sz[MAXN];
bool mark[MAXN];
int M;
int phiM;
ll P10[MAXN];
map<int,int> c[MAXN];

ll POW(ll base,int exp) {
  if(!exp) return 1;
  return POW((base*base)%M,exp>>1) * (exp&1?base:1) %M;
}

int dfs_size(int v,int p = -1) {
  if(mark[v]) return 0;
  sz[v] = 1;
  for(auto u : tree[v])
    if(u.F!=p) sz[v] += dfs_size(u.F,v);
  return sz[v];
}
 
int get_centroid(int v,int tot,int p = -1,int up = 0) {
  for(auto u : tree[v])
    if(!mark[u.F] && u.F!=p && sz[u.F] > tot/2) return get_centroid(u.F,tot,v,tot -sz[u.F]);
  return v;
}

void gen_dis(int v,int m,int p = -1,int up = 0,int cnt = 0) {
  c[m][up%=M]++;
//  cout << "\t" << v << " " << up << endl;
  for(auto u : tree[v])
    if(!mark[u.F] && u.F!=p)
      gen_dis(u.F,m,v,up+P10[cnt]*u.S%M,cnt+1);
}

ll calc_ans(int v,int m1,int m2,int p = -1,int up = 0,int cnt = 0) {
  up%=M;
  int x = ((M-up%M)*POW(P10[cnt],(M>1?phiM-1:0)))%M;
  ll ans = c[m1][x] - c[m2][x];
//  cout << "\t\t " << v << " " << x << " " << ans << " " << up << " " << endl;;
  for(auto u : tree[v])
    if(!mark[u.F] &&u.F!=p) ans += calc_ans(u.F,m1,m2,v,(up*10)%M+u.S,cnt+1);
  return ans;
}

ll solve(int v) {
  dfs_size(v);
  int w = get_centroid(v,sz[v]);
  mark[w] = true;
//  cout << w << endl;
  gen_dis(w,w);
  for(auto u : tree[w])
    if(!mark[u.F])
      gen_dis(u.F,u.F,w,u.S,1);
  ll ans = c[w][0]-1;
//  cout << ans << endl;
  for(auto u : tree[w])
    if(!mark[u.F])
      ans += calc_ans(u.F,w,u.F,w,u.S,1);
//  cout << w << " " << ans << endl;
  c[w].clear();
  for(auto u : tree[w]) c[u.F].clear();
  for(auto u : tree[w])
    if(!mark[u.F])
      ans += solve(u.F);
  return ans;
}

void calc_phi() {
  int w = M;
  vi primes;
  for(int i = 2;i<sqrt(M);i++) {
    if(w%i==0) primes.pb(i);
    while(w%i==0) w/=i;
  }
  if(w>1)primes.pb(w);
  phiM = M;
  for(auto x : primes)
    (phiM/=x)*=x-1;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n >> M;
  for(int i = 1;i<n;i++) {
    int x,y,z;cin >> x >> y >> z;
    tree[x].pb(mp(y,z));
    tree[y].pb(mp(x,z));
  }
  P10[0] = 1;
  for(int i = 1 ;i<=n;i++) P10[i] = (P10[i-1]*10)%M; 
  calc_phi();
  ll ans = solve(0);
  cout << ans << endl;
	return 0;
}
