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

const int MAXN = 752;
const int MOD = 1e9+7;
int dp[MAXN];
int tab[MAXN][MAXN];

struct BIT {
  int *bit;
  int n;

  BIT(int n) : n(n) {
    bit = new int[n+1]();
  }

  void add(int x,int v) {
    while(x<=n)
      bit[x] = (v+bit[x]*1LL)%MOD,x+=x&-x;
  }

  int get(int x) {
    int ans = 0;
    while(x)
      ans=(ans+bit[x]*1LL)%MOD,x^=x&-x;
    return ans;
  }
}; 

struct RMBIT {
  map<int,int> *m;//[1000];

//  int **m;
  int n;

  RMBIT(int n,int k) : n(n) {
    m = new map<int,int>[n+1]();
//    F0R(i,0,n) m[i] = new int[k+1]();
  }

  void add(int x,int y,int val) {
    while(x<=n)
      m[x][y]=(m[x][y]*1LL+val*1LL)%MOD,x+=x&-x;
  }

  int get(int x,int y) {
    int ans = 0;
    while(x)
      ans=(ans*1LL+m[x][y]*1LL)%MOD,x^=x&-x;
    return ans;
  }
} ;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int r,c,k;
  cin>> r >> c >> k;
  if(r<c) {
    F0R(i,1,r) F0R(j,1,c) cin >> tab[j][i];
    swap(r,c);
  } else
  F0R(i,1,r) F0R(j,1,c) cin >> tab[i][j];
  BIT S = BIT(c);
  RMBIT R = RMBIT(c,k);
  S.add(1,1);
  R.add(1,tab[1][1],1);
  FOR(i,2,r) {
    FOR(j,2,c)
      dp[j] = (S.get(j-1)-R.get(j-1,tab[i][j])+MOD)%MOD;
    FOR(j,2,c) 
      S.add(j,dp[j]),R.add(j,tab[i][j],dp[j]);
  }
  dp[c] = (S.get(c-1)-R.get(c-1,tab[r][c])+MOD)%MOD;
  cout << dp[c] << endl;
	return 0;
}
