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
ll arr[MAXN];
ll ft[MAXN],st[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  ll s,f,t;cin >> s >> f >> t;
  int n;cin >> n;
  ll mn = 1e12+6.66;
  ll ans = 0;
  ft[0] = s;
  F0R(i,1,n) cin >> arr[i];
  ll now = s;
  F0R(i,1,n) st[i] = max(now,arr[i]),ft[i] = st[i]+t,now = ft[i];
//  FOR(i,0,n) cout << st[i] << " " << ft[i] << " " << arr[i] << endl;
  if(n>0 && ft[n]<f) ans = ft[n],mn = 0;
  F0R(i,1,n) if( ft[i] >=f) {n = i;break;};
  F0R(i,1,n) {
    if(arr[i] > 0 && mn> (st[i]==arr[i] && ft[i-1] < st[i]?arr[i]-1 : st[i])-arr[i]+1 )
      ans = arr[i]-1,mn = (st[i]==arr[i] && ft[i-1] < st[i]?arr[i]-1 : st[i])-arr[i]+1;
  }
  cout << (n==0?s:ans) << endl;
	return 0;
}
