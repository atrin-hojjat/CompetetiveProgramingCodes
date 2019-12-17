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
map<int,int> cols[MAXN];
map<int,vi> ED[MAXN];
map<int,bool> dd[MAXN];
map<pii,int> ANS;
int I = 1;

void dfs(int v,int c) {
  dd[v][c] = true;
  cols[v][c] = I;
//  cs[v].erase(cs[v].find(c));
  for(auto u : ED[v][c])
    if(!dd[u][c]) 
      dfs(u,c);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  FOR(i,0,m) {
    int a,b,c;cin >> a >> b >> c;
    cols[a][c] = cols[b][c] = 0;
    ED[a][c].pb(b);
    ED[b][c].pb(a);
  }
  F0R(i,1,n)
    for(auto x :cols[i])
      if(!dd[i][x.F]) dfs(i,x.F),I++;
  int Q;cin >> Q;
  while(Q--) {
    int a,b;cin >> a >> b;
    if(mp(cols[a].size(),a)>mp(cols[b].size(),b))swap(a,b);
    if(ANS[{a,b}]) {cout << ANS[{a,b}]-1 << "\n";continue;}
    int ans = 0;
    for(auto x : cols[a])
      if(cols[b].count(x.F) && x.S==cols[b][x.F]) ans ++;
    cout << ans << "\n";
    ANS[{a,b}] = ans+1;
  }
	return 0;
}
