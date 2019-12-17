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
const int INF  = 1e9+6.66;
int mx_hel[MAXN];
int st_hel[MAXN];
int reg[MAXN];
vii up[MAXN];
int damage,bounty,increase;
multiset<pii> secs;
unsigned long long ans = 0ULL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  cin >> bounty >> increase >> damage;
  FOR(i,0,n) {
    cin >> mx_hel[i] >> st_hel[i] >> reg[i];
    if(mx_hel[i]<=damage) { cout << -1 << endl; return 0;}
  }
  FOR(i,0,m) {
    int t,x,h;
    cin >> t >> x >> h;
    x--;
    up[x].pb({t,h});
  }
  FOR(i,0,n) {
    if(up[i].size()) sort(up[i].begin(),up[i].end());
    int S1 = 0,E1;
    if(reg[i])
      E1 = min((up[i].size()?up[i].begin()->F-1:INF),(damage-st_hel[i])/reg[i]+1);
    else E1 = (up[i].size()?up[i].begin()->F-1:INF);
    if(E1>S1) {secs.insert({S1,-1}),secs.insert({E1,S1});}
    vector<pii>::iterator nx ;
    if(up[i].size()) nx = up[i].begin();
    for(auto x : up[i]) {
      if(nx!=up[i].end()) nx++;
      if(x.S>damage) continue;
      if(reg[i]==0) {
        if(x.S<=damage) {cout <<-1 << endl;continue;}
        secs.insert({x.F,-1});
        if(nx!=up[i].end()) secs.insert({nx->F-1,x.F});
        continue;
      }
      E1 = min((nx==up[i].end()?INF:nx->F),x.F + (damage-x.S)/reg[i]+1);
//      cout << i << " " << x.F << " " << x.S << endl;
      secs.insert({x.F,-1}),secs.insert({E1,x.F});
    }
  }
  int cnt = 0;
  for(auto x : secs) {
//    cout << x.F << endl;
    if(x.S==-1) {cnt++;continue;}
    ans = max(ans,1ULL* cnt*(1ULL*x.F*increase+bounty));
    cnt --;
  }
  cout << ans << endl;
	return 0;
}
