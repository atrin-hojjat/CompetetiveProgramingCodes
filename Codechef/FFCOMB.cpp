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

const int MAXN = 20;
int price[MAXN];
int dp[1<<MAXN];
int dd[1<<MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int T;cin >> T;
  while(T--) {
    memset(dp,0x3f,sizeof dp);
    memset(dd,0x3f,sizeof dd);
    int n,m;cin >> n >> m;
    for(int i = 0;i<n;i++) cin >> dd[1<<i];
    while(m--) {
      int p,c;cin >> p >> c;
      int mask = 0;
      while(c--) {
        int x;cin >> x;x--;
        mask |= 1<<x;
      }
      dd[mask] = min(dd[mask],p);
    }
    dp[0] = 0;
    for(int mask = 1;mask<(1<<n);mask++) {
      for(int m = mask;m>0;m = (m-1)&mask)
        dd[m] = min(dd[m],dd[mask]);
    }
    for(int mask = 1;mask<(1<<n);mask++) {
      for(int m = mask;m>0;m = (m-1)&mask)
        dp[mask] = min(dp[mask],dp[mask^m] + dd[m]);
    }
    cout << dp[(1<<n)-1] << endl;
  }
	return 0;
}
