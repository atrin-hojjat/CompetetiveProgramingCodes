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

const int MAXN = 750+6.66;
const int MOD = 1e9+7;
ll dp[MAXN][MAXN];
int tab[MAXN][MAXN];
map<int,ll> rm[MAXN];

struct BIT {
  ll bit[756];

  BIT() {
    memset(bit,0,sizeof bit);
  }

  void add(int x,ll v) {
    while(x<MAXN)
      (bit[x] += v)%=MOD,x+=x&-x;
  }

  ll get(int x) {
    ll ans = 0;
    while(x)
      (ans+=bit[x])%=MOD,x^=x&-x;
    return ans;
  }
};

struct _2DBIT {
  BIT bit[756];

  _2DBIT() {
    fill(bit,bit+MAXN,BIT());
  }

  void add(int x,int y,ll val) {
    while(x<MAXN)
      bit[x].add(y,val),x+=x&-x;
  }

  ll get(int x,int y) {
    ll ans = 0;
    while(x)
      (ans += bit[x].get(y))%=MOD,x^=x&-x;
    return ans;
  }
} S;

struct RMBIT {
  map<int,ll> m[756];

  RMBIT() {

  }

  void add(int x,int y,ll val) {
    while(x<MAXN)
      (m[x][y]+=val)%=MOD,x+=x&-x;
  }

  ll get(int x,int y) {
    ll ans = 0;
    while(x)
      (ans+=m[x][y])%=MOD,x^=x&-x;
    return ans;
  }
} R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int r,c,k;cin>> r >> c >> k;
  F0R(i,1,r) F0R(j,1,c) cin >> tab[i][j];
  dp[1][1] = 1;
  S.add(1,1,1);
  R.add(1,tab[1][1],1);
  F0R(i,2,r) {
    F0R(j,2,c) {
      dp[i][j] = (S.get(i-1,j-1)-R.get(j-1,tab[i][j])+MOD)%MOD;
//      cout << i << "," << j << " " << S.get(i-1,j-1) << " " << R.get(j-1,tab[i][j]) << endl;
      S.add(i,j,dp[i][j]);
    }
    F0R(j,2,c) 
      R.add(j,tab[i][j],dp[i][j]);
  }
//  F0R(i,1,r) {F0R(j,1,c) cout << dp[i][j] << " " ;cout << endl;}
  cout << dp[r][c] << endl;
	return 0;
}
