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
vi ed[MAXN];
vi rev[MAXN];
queue<int> Q[2];
int cnt[MAXN];
bool mark[MAXN];
bool leaf[MAXN];
bool co[MAXN];

void dfs(int v,int p = -1) {
  if(mark[v]) return ;
  mark[v] = true;
  if(ed[v].size()==0) leaf[v] = true;
  for(auto u : ed[v])
    if(u!=p) 
      dfs(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  FOR(i,0,n) cin >> co[i];
  FOR(i,0,m) {
    int x,y;cin >> x >> y;
    ed[x].pb(y);
    rev[y].pb(x);
  }
 //dfs(0);
  FOR(i,0,n) if(!ed[i].size()) Q[co[i]].push(i);
  int ans = 0;
  while(Q[0].size() || Q[1].size()) {
    bool cop = 0;
    for(int i = 0;i<2 ;i++)
      while(Q[i].size()) {
        cop = i;
        int v = Q[i].front();Q[i].pop();
//        mark[v] = true;
        for(auto x : rev[v]) {
          cnt[x] ++;
          if(cnt[x] == ed[x].size())
            Q[co[x]].push(x);
        }
//        if(i) cout << v << " " ;
      }
//    cout << endl;
    ans += cop;
  }
  cout << ans << endl;
	return 0;
}
