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

const int MAXN = 71;
const int MAXP = 20;
const ll  MOD  = 1e9+7;
int cnt[MAXN];
ll dp[2][1<<MAXP];
int mask[MAXN];
ll ODD[MAXN];
ll EVEN[MAXN];
vi primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

ll POW(ll base,ll exp) {
  if(exp==0) return 1;
  return (exp&1?base*POW(base*base%MOD,exp>>1)%MOD:POW(base*base%MOD,exp>>1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,0,n) {
    int x;cin >> x;
    cnt[x]++;
  }
  FOR(i,1,MAXN) {
    int x = i;
    int m = 0;
    int t = 0;
    for(auto w : primes)
    {
      int z = 0;
      while(x%w==0) z++,x/=w;
      if(z%2)m |= (1<<t);
      t++;
    }
    mask[i] = m;
    if(cnt[i]==0)ODD[i] = 0,EVEN[i] = 1;
    else ODD[i] = EVEN[i] = POW(2,cnt[i]-1);
  }
  bool x = false;
  dp[0][0] = 1;
  FOR(i,1,MAXN) {
    FOR(m,0,1<<MAXP) {
      dp[!x][m] += dp[x][m^mask[i]]*ODD[i]%MOD;
      dp[!x][m] += dp[x][m] * EVEN[i]%MOD;
      dp[!x][m] %= MOD;
    }
    fill(dp[x],dp[x]+(1<<MAXP),0);
    x = !x;
  }
  cout << dp[x][0]-1 << endl;
	return 0;
}
