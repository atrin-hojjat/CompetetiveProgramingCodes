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
pii pts[MAXN];
map<int,bool> EX[MAXN];
vi rows[MAXN];
vi cols[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,0,n) {
    int x,y;cin >> x >> y;
    pts[i] = {x,y};
    EX[x][y] = true;
    cols[x].pb(y);
    rows[y].pb(x);
  }
  int ans = 0;
  FOR(i,0,MAXN) sort(cols[i].begin(),cols[i].end()),sort(rows[i].begin(),rows[i].end());
  FOR(i,0,n) {
    vi::iterator be,en;
    {
      auto W1 = lower_bound(cols[pts[i].F].begin(),cols[pts[i].F].end(),pts[i].S);
      auto W2 = lower_bound(rows[pts[i].S].begin(),rows[pts[i].S].end(),pts[i].F);
      if(W1-cols[pts[i].F].begin()>W2-rows[pts[i].S].begin())
        for(auto it = rows[pts[i].S].begin();it!=W2;++it) {
          if(EX[pts[i].F].count(pts[i].S-(pts[i].F-*it)) && EX[*it].count(pts[i].S-(pts[i].F-*it))) ans ++;
        }
      else
        for(auto it = cols[pts[i].F].begin();it!=W1;++it) {
          if(EX[pts[i].F-(pts[i].S-*it)].count(pts[i].S) && EX[pts[i].F-(pts[i].S-*it)].count(*it)) ans ++;
        }
    }
  }
  cout << ans << endl;
	return 0;
}
