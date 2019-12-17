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

const int MAXN = 5e3+6.66;
const ll INF   = 6e16L+666;
ll dp[MAXN][MAXN];
ll mouse[MAXN];
pll hole[MAXN];

ll solve(int x,int n) {
  deque<pll> prev;
  ll add = 0;
  for(int i = 0;i<MAXN;i++) dp[x][i] = INF;
  for(int i = 0;i <= n;++i,add+= llabs(hole[x].F- mouse[i])) {
    while(prev.size() && prev.front().S<i-hole[x].S) prev.pop_front();
    while(prev.size() && prev.back().F >= dp[x-1][i]-add && dp[x-1][i]!=INF) prev.pop_back();
    if(dp[x-1][i]!=INF)prev.push_back(mp(dp[x-1][i]-add,i));
    if(!prev.size()) break;
//    cout << prev.front().F << " " << prev.front().S << endl;
    dp[x][i] = min(dp[x][i],prev.front().F + add);
  }
//  F0R(i,0,n) cout << dp[x][i] << " " ; cout << endl;
  return dp[x][n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  F0R(i,1,n) cin >> mouse[i];
  F0R(i,1,m) cin >> hole[i].F >> hole[i].S;
  sort(mouse+1,mouse+n+1);
  sort(hole+1,hole+m+1);
  ll ans = INF;
  FOR(i,0,MAXN) dp[0][i] = INF;dp[0][0] = 0;
  F0R(i,1,m) ans = min(ans,solve(i,n));
  cout << (ans==INF?-1:ans) << endl;
	return 0;
}
