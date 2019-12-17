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

const int MAXN = 1e6+6.66;
const int LOGMAXN = 20;
const ll MOD = 1e9+7;
ll fact[MAXN+LOGMAXN];
ll saveC[MAXN+LOGMAXN][LOGMAXN];
ll _2POW[MAXN];
map<pii,ll> save;


ll POW(ll base,ll exp) {
  if(!exp) return 1;
//  if(save[mp(base,exp)] ) return save[mp(base,exp)];
  return /*save[mp(base,exp)] =*/ POW(base*base%MOD,exp>>1)*(exp&1?base:1)%MOD;
}
/*
ll get_fact(int n) {
  if(n==0) return 1;
  if(fact[n]) return fact[n];
  return fact[n] = (n*get_fact(n-1))%MOD;
}*/

ll C(int n,int r) {
  if(saveC[n][r]) return saveC[n][r];
  return saveC[n][r] = (((fact[n]*POW(fact[r],MOD-2))%MOD) *POW(fact[n-r],MOD-2))%MOD;
}

ll H(int n,int r) {
  return C(n+r-1,r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int q;cin >> q;
//  get_fact(MAXN-1);
  fact[0] = 1;
  FOR(i,1,MAXN+LOGMAXN) fact[i] = fact[i-1]*i%MOD;
  _2POW[0] = 1;
  FOR(i,1,MAXN) (_2POW[i] = _2POW[i-1]*2%MOD);
//  FOR(i,1,MAXN) FOR(j,0,LOGMAXN) C(i,j);
//  LOG;
  while(q--) {
    int x,y;cin >> x >> y;
    ll ans = 1;
    F0R(i,2,sqrt(x)) {
      if(x%i!=0)continue;
      int cnt = 0;
      while(x%i==0) x/=i,cnt++;
      (ans *= H(y,cnt))%=MOD;
    }
    if(x>1) (ans*=H(y,1))%=MOD;
    (ans*= _2POW[y-1])%=MOD;
    cout << ans << "\n";
  }
	return 0;
}
