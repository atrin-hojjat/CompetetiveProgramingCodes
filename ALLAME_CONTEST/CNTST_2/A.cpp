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

const int MAXN = 20+2.66;
const int MAXC = 1e3+6.66;
ll dp[1<< MAXN];
vl st[MAXN];
int du[MAXN];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,c,L;
  cin >> n >> L;
  FOR(i,0,n) {
    cin >> du[i] >> c;
    while(c--) {
      int x;cin >> x;
      st[i].insert(st[i].begin(),-x);
    }
  }
  FOR(i,1,1<<n) {
    FOR(j,0,n) {
      if(((i>>j)&1)==0)continue;
      auto x = lower_bound(st[j].begin(),st[j].end(),-dp[i^(1<<j)]);
//      cout << dp[i] << " " << i << " " << *x << " " << -*x+du[i]<< endl;
      if(x == st[j].end()) continue;
      dp[i] = max(dp[i],-*x + du[j]);
    }
  }
  int ans = 1000;
  FOR(i,1,1<<n)
    if(dp[i] >=L)
      ans = min(ans,__builtin_popcount(i));
  if(ans==1000) cout << -1 << endl;
  else cout << ans << endl;
	return 0;
}
