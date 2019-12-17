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
const int LOGMAXN = 20;
pii X[MAXN];
int RMQ[LOGMAXN][MAXN];
int par[MAXN];

int main() {
#ifdef ONLINE_JUDGE
	freopen("trapped.in", "r", stdin);
	freopen("trapped.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,0,n) cin >> X[i].S >> X[i].F;
  sort(X,X+n);
  FOR(i,0,n) 
    RMQ[0][i] = X[i].F + X[i].S;
  FOR(i,1,LOGMAXN)
    FOR(j,0,n)
      RMQ[i][j] = max(RMQ[i-1][j],(1<<(i-1))+j<n?RMQ[i-1][j+(1<<(i-1))]:0);
  int last = X[0].F;
  FOR(i,1,n) {
    auto x = lower_bound(X,X+i,mp(-X[i].S+X[i].F,0));
    if(x==X+i) continue;
    int sp = x-X;
    int p = sp;
    int now = RMQ[0][p];
    RFOR(l,0,LOGMAXN)
      if(p+(1<<l)<=i && max(RMQ[l][p],now)<X[i].F)
        now = max(now,RMQ[l][p]), p = p+(1<<l);
    par[i] -= 1;
    par[p] += 1;
    last = X[i].F;
  }
  ll sum = 0;
  ll ans = 0;
  FOR(i,0,n-1) {
    sum+= par[i];
    if(sum) ans += X[i+1].F - X[i].F;
  }
  cout << ans << endl;
	return 0;
}
