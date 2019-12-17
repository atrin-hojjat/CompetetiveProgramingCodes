#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
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

const int MAXN = 20;
long double dp[1<<MAXN][MAXN];
long double tab[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++) 
      cin >> tab[i][j];
  for(int i = 0;i<n;i++) dp[1<<i][i] = 1;
  for(int mask = 1;mask<(1<<n);mask++)
    for(int i = 0;__builtin_popcount(mask)>1 && i<n;i++)
      if((mask>>i)&1) {
        long double xx = 0;
        for(int j = 0;j<n;j++)
          if(i!=j && (mask>>j)&1)
            xx += dp[mask^(1<<i)][j] * tab[i][j];
        cout << i << " " << mask << " " << xx << endl;
        for(int j = 0;j<n;j++)
          if(i!=j && (mask>>j)&1)
            dp[mask][i] = max(dp[mask][i],dp[mask^(1<<j)][i] * tab[i][j]);
        dp[mask][i] = max(dp[mask][i],xx);
      }
  cout << fixed << setprecision(8) << dp[(1<<n)-1][0] << endl;
	return 0;
}
