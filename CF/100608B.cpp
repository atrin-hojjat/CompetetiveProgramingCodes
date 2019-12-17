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

const int MAXN = 64+6.66;
vi vec[MAXN];
char ans[MAXN];
ll dp[MAXN];

ll POW(ll base,ll exp) {
  if(!exp) return 1;
  if(exp<0) cout << base << " " << exp << endl;
  return POW(base*base,exp>>1) * (exp&1?base:1) ;
}

ll get_ways(int n,int x,int w) {
  return POW(2,max(0,w-x)) * POW(2,) ;
}

void solve(ll n,ll k) {
  memset(ans,0,sizeof ans);
  for(int i = 1;i<=n;i++) {
    ll a = POW(2,n-i);
    ll *dp = new ll[i]();
    cout << i << endl;
    for(int j = 1;j<=n/2;j++) {
      ll b = get_ways(n,i,j);
      for(int k : vec[j])
        b -= dp[k];
      dp[j] = b;
      a -= b;
      cout << "\t" << j << endl;
    }
    if(a> k) ans[i] = 'a';
    else k-=a;
  }
  for(int i = 1;i<=n;i++) cout << ans[i]; cout << endl;
  LOG;
}

void init() {
  for(int i = 1;i<MAXN;i++)
    for(int j = 1;j<i;j++)
      if(i%j==0) vec[i].pb(j);
}

int main() {
//	freopen("borderless.in", "rt", stdin);
//	freopen("borderless.out", "wt", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  init();
  LOG;
  while(1) {
    ll n,k;cin >> n >> k;
    if(k==n && n==0) break;
    solve(n,k);
  }
	return 0;
}
