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
const ll MOD = 1e9+7.77;
vi tree[MAXN];
ll dp_up[MAXN];
ll dp_down[MAXN];
ll mul[MAXN];
int now = 0;

void dfs_up(int v) {
  dp_up[v] = 1;
  for(auto u : tree[v]) {
    dfs_up(u);
    (dp_up[v]*=dp_up[u]+1)%=MOD;
  }
}

void dfs_down(int v,ll up) {
  (dp_down[v] = dp_up[v]*up)%=MOD;
  int st = now+1;
  int et = now+=tree[v].size();
  mul[st] = up;
  F0R(i,st+1,et)
    (mul[i] = mul[i-1]*(dp_up[tree[v][i-1-st]]+1))%=MOD;
  ll cur = 1;
  RFOR(i,0,tree[v].size()) {
    dfs_down(tree[v][i],(cur*mul[st+i]+1)%MOD);
    (cur*=dp_up[tree[v][i]]+1)%=MOD;
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  F0R(i,2,n) {
    int x;cin >> x;
    tree[x].pb(i);
  }
  dfs_up(1);
  dfs_down(1,1);
  F0R(i,1,n) cout << dp_down[i] << " " ;
  cout << endl;
	return 0;
}
