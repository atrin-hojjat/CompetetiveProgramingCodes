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

const ll MOD = 1e9+7;

ll POW(ll base,ll exp) {
  if(exp==0) return 1;
  return (exp&1?base:1)*POW(base*base%MOD,exp>>1)%MOD;
}

int cnt(ll x) {
  int ans = 0;
  F0R(i,2,sqrt(x)) {
    while(x%i==0)x/=i,ans++;
  }
  return ans + (x>1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  ll x,y;cin >> x >> y;
  if(y%x!=0) {
    cout << 0 << endl;
    return 0;
  }
  if(x==y) {
    cout << 1 << endl;
    return 0;
  }
  y/=x;
  int w = cnt(y);
//  cout << w << endl;
  ll ans = 0;
  F0R(i,1,sqrt(y)) {
    if(y%i) continue;
    if(y/i==i) {
//      int X = cnt(i);
//      cout << X<< " " << w-X << " " << POW(2,i-1) << " " << POW(2,y/i-1) << endl;
      ans = (ans + MOD + ((w-cnt(i))%2==0?1:-1)*POW(2,i-1)) %MOD;
    } else {
      int X = cnt(i);
//      cout << X<< " " << w-X << " " << POW(2,i-1) << " " << POW(2,y/i-1) << endl;
      ans = (ans + 2LL*MOD + ((w-X)%2==0?1:-1)*POW(2,i-1) + (X%2==0?1:-1)*POW(2,y/i-1))%MOD;
    }
  }
  cout << ans << endl;
	return 0;
}
