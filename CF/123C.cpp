#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <climits>
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

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 150;
char ans[MAXN*2];
int pr[MAXN*2];
ll dp[MAXN*2][MAXN*2];
ull C[40];
ull WW[MAXN*2];
set<pii> on;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  ll k ;cin >> k;
  FOR(i,0,m+n) pr[i] = 1e6;
  FOR(i,0,n) FOR(j,0,m) {
    int x;cin >> x;
    pr[i+j] = min(pr[i+j] ,x);
  }
  FOR(i,0,n+m-1) on.insert(mp(pr[i],i));
  for(auto w : on) {
    ans[w.S] = '(';
    memset(dp,0,sizeof dp);
    dp[0][1] = 1;
    FOR(i,1,n+m-1) {
      if(ans[i]) {
        if(ans[i] =='(') 
          FOR(j,1,n+m-1) dp[i][j] = dp[i-1][j-1];
        else
          FOR(j,0,n+m-2) dp[i][j] = dp[i-1][j+1];
        continue;
      }
      dp[i][0] = dp[i-1][1];
      FOR(j,1,n+m-1) {
        dp[i][j] = dp[i-1][j+1] + dp[i-1][j-1]; 
      }
      FOR(j,0,n+m-1) dp[i][j] = min((ll)1e18+666,dp[i][j]);
    }
//    FOR(i,0,n+m-2) {FOR(j,0,i) cout << dp[i][j] << " "; cout << endl;}
//    cout << dp[n+m-2][0] << endl;
    if(k > dp[n+m-2][0]) k -= dp[n+m-2][0],ans[w.S] = ')';
  }
  FOR(i,0,n) {FOR(j,0,m) cout << ans[i+j] ;cout << endl;}
	return 0;
}
