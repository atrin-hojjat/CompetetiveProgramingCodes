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

const int MAXN = 16;
vector<pii> eds[MAXN];
int min_dis[MAXN][MAXN];
bool mark[MAXN];
int min_ed[MAXN][MAXN];
int dp[1<<MAXN];

void dfs(int v = 0) {
  mark[v] = true;
  for(auto u : eds[v])
    if(!mark[u.F]) dfs(u.F);
}

int&min(int&x,int y) {
  return x = x>y?y:x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  memset(min_ed,0x3f,sizeof min_ed);
  memset(min_dis,0x3f,sizeof min_dis);
  int ans = 0;
  for(int i = 0;i<m;i++) {
    int x,y,z;cin >> x >> y >> z;
    x--,y--;
    min_ed[x][y] = min(min_ed[y][x] ,z);
    eds[x].pb({y,z});
    eds[y].pb({x,z});
    ans += z;
  }
  dfs(0);
  for(int i = 0;i<n;i++) 
    if(!mark[i] && eds[i].size()) {cout << -1 << endl;return 0;}
  for(int i = 0;i<n;min_dis[i][i] = 0,i++) for(int j= 0;j<n;j++) min_dis[i][j] = min_ed[i][j];
  for(int k = 0;k<n;k++)
    for(int i = 0;i<n;i++)
      for(int j = 0;j<n;j++)
        min(min_dis[i][j], min_dis[i][k] + min_dis[k][j]);
  memset(dp,0x3f,sizeof dp);
  dp[0] = 0;
  for(int mask = 0;mask<(1<<n);mask++) {
    for(int i = 0;i<n;i++) {
      if((mask>>i)&1) continue;
      if(eds[i].size()%2==0) { min(dp[mask|(1<<i)], dp[mask]); continue; }
      for(int j = 0;j<n;j++) {
        if((mask>>j)&1) continue;
        if(i==j || eds[j].size()%2==0) continue;
        min(dp[mask|(1<<i)|(1<<j)], dp[mask] + min_dis[i][j]);
      }
    }
  }
  cout << dp[(1<<n)-1] + ans << endl;
	return 0;
}
