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

const int MAXN = 5000+6.66;
const ll MOD = 998244353;
ll fact[MAXN];

ll POW(ll base,ll exp) {
  if(!exp) return 1;
  return POW(base*base%MOD,exp>>1) * (exp&1?base:1) %MOD;
}

ll C(int n,int r) {
  return (fact[n]*POW(fact[n-r],MOD-2)%MOD)*POW(fact[r]%MOD,MOD-2)%MOD;
}

void init_fact() {
  fact[0] = 1;
  for(int i = 1;i<MAXN;i++) fact[i] = (fact[i-1]*i)%MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int a,b,c;cin >> a >> b >> c;
  init_fact();
  ll ans = 1;
  for(int tmp = 0;tmp<3;tmp++) {
    ll W = 0;
    for(int i = 0;i<=min(a,b) ;i++)
      (W += (fact[i] * C(a,i)%MOD) * C(b,i)%MOD)%=MOD;
    (ans *=W)%=MOD;
    swap(a,b);
    swap(b,c);
  }
  cout << ans%MOD << endl;
	return 0;
}
