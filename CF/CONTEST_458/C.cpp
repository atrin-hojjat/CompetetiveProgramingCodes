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

const int MAXN = 1000+6;
const ll  MOD  = 1e9+7;
ll fact[MAXN*2];
ll dp[MAXN];

ll POW(ll base,ll exp) {
  if(!exp) return 1;
  return (POW(base*base%MOD,exp>>1) * (exp&1?base:1)) %MOD;
}

ll C(int n,int r) {
  return (fact[n] * POW(fact[r],MOD-2) %MOD * POW(fact[n-r],MOD-2) )%MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  string n;cin >> n;
  int k;cin >> k;
  dp[1] = 0;
  for(int i = 2;i<MAXN;i++) {
    dp[i] = dp[__builtin_popcount(i)]+1 ;
  }
  fact[0] = 1;
  for(int i = 1;i<2*MAXN;i++) (fact[i] = i*fact[i-1])%=MOD;
  int sz = n.size();
  ll ans = (k==0);
  for(int i = 1;i<MAXN;i++) {
    if(i<=sz && dp[i] == k-1) {
//      cout << i << endl;
      (ans += C(sz,i)-(i==1))%=MOD;
    }
  }
//  cout << ans << endl;
  int prv_1 = 0;
  for(auto x : n) {
    sz--;
    if(x=='0') {
//      cout << sz << " " << prv_1 << endl;
      for(int i = prv_1+1;i<MAXN;i++) {
        if(i<=sz+prv_1+1 && dp[i] == k-1) {
//          cout << i << endl;
          (ans += MOD-C(sz,i-prv_1-1)-(i==1))%=MOD;
        }
      }
    } else prv_1 ++;
  }
  cout << ans << endl;
	return 0;
}
