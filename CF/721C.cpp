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
const int inf = 1e9+7;
vii dag[MAXN];
vi rev_dag[MAXN];
pii dp[MAXN][MAXN];
int deg[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m,t;cin >> n >> m >> t;
  FOR(i,0,m) {
    int x,y,z;cin >> x >> y >> z;
    dag[x].pb(mp(y,z));
    rev_dag[y].pb(x);
  }
  FOR(i,0,MAXN)FOR(j,0,MAXN) dp[i][j] = mp(inf,inf);
  dp[1][1] = mp(0,-1);
  F0R(i,1,n) deg[i] = rev_dag[i].size();
  set<pii> s;
  FOR(i,1,n) s.insert(mp(deg[i],i));
  while(s.size() && s.begin()->S!=1) s.erase(s.begin());
  while(true) {
    int x = s.begin()->S;
    if(x==n) break;
    s.erase(s.begin());
    for(auto u : dag[x]) {s.erase(mp(deg[u.F],u.F));s.insert(mp(--deg[u.F],u.F));}
    for(auto u : dag[x])
      FOR(i,1,MAXN)
        dp[u.F][i] = min(dp[u.F][i],mp(dp[x][i-1].F+u.S,x));
  }
  int ans = 0;
  int prev = -1;
  FOR(i,0,MAXN)if(dp[n][i].F<=t) ans = i,prev = dp[n][i].S;
  cout << ans << endl;
  stack<int> st;st.push(n);
  while(~prev) st.push(prev),prev = dp[prev][--ans].S;
  while(st.size()) cout << st.top() << " " ,st.pop();
  cout << endl;
	return 0;
}
