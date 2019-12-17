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

const int MAXN = 32;
const ll INF = 2e18+666*666*666;
const int MX = 16;
ll dp1[1<<MX],dp2[1<<MX];
ll arr[MAXN];
vector<ll> vv;

ll mul(ll a,ll b) {
//  cout << " \t" << a << " " << b << endl;
  if(a>INF/b) return INF;
  return a*b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;ll k ;cin >> n >> k ;
  for(int i = 0;i<n;i++) cin >> arr[i];
  dp1[0] = 1;
  for(int i = 1;i<(1<<min(n,MX));i++) {
    dp1[i] = mul(dp1[i^(i&-i)],arr[__builtin_ctz(i)]);
//    cout << i << " " << dp1[i] << endl;
    vv.push_back(dp1[i]);
  }
  sort(vv.begin(),vv.end());
  ll ans = upper_bound(vv.begin(),vv.end(),k) - vv.begin();
  dp2[0] = 1;
  for(int i = 1;i<(1<<max(0,n-MX));i++) {
    dp2[i] = mul(dp2[i^(i&-i)] , arr[__builtin_ctz(i)+MX]);
    ans += (dp2[i] <= k) + (upper_bound(vv.begin(),vv.end(),k/dp2[i]) - vv.begin());
  }
  cout << ans << endl;
	return 0;
}
