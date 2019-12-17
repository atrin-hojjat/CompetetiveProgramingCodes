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

const int MAXN = 1e5+6.66;
const int MAXM = 1e6+6.66;
const ll MOD = 1e9+7;
ll BIT[MAXM];
ll cnt[MAXM];

ll POW(ll base,ll exp) {
  ll ans = 1;
  for(;exp;exp>>=1,(base *= base)%=MOD)
    if(exp&1) (ans *= base) %=MOD;
  return ans ;
}

void add(int x,int val) {
  while(x<MAXM) 
    (BIT[x] += val)%=MOD,x+= x&-x;
}

ll query(int x) {
  ll ans = 0;
  while(x)
    (ans += BIT[x])%=MOD,x ^= x&-x;
  return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  for(int i = 0;i<n;i++) {
    int x;cin >> x;
    ll ans = 0;
    ll Q = query(x-1);
    ll QQ = (query(x) - Q + MOD)%MOD;
    (Q += QQ) %=MOD;
    (ans += ((Q+1)*x %MOD))%=MOD;
    add(x,-QQ+MOD);
//    if(cnt[i]) cout << Q << " " << ans << " " << POW(i,cnt[i])<< endl;
    add(x,ans);
  }
  cout << query(MAXM-1) << endl;
	return 0;
}
