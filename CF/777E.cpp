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
int b[MAXN];
int a[MAXN];
int h[MAXN];
int dp[MAXN];
map<int,int> cmp;

struct BIT {
  int MXN = 2e5+6.66;
  ll bit[200006];
  
  BIT() {
    memset(bit,0,sizeof bit);
  }

  void add(int x,ll val) {
    if(x==0) return ;
    while(x<MXN)
      bit[x] = max(bit[x],val),x+=x&-x;
  }

  ll get(int x) {
    ll ans = 0;
    while(x)
      ans = max(ans,bit[x]),x^=x&-x;
    return ans;
  }
} S;

void compress(int n) {
  F0R(i,1,n) cmp[b[i]] = 0;
  F0R(i,1,n) cmp[a[i]] = 0;
  int I = 0;
  for(auto&x : cmp)
    x.S = ++I;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  vi v;
  F0R(i,1,n) {
    cin >> b[i] >> a[i] >> h[i];
    v.pb(i);
  }
  compress(n);
  sort(v.begin(),v.end(),[](int x,int y) { return (a[x]==a[y]?b[x]>b[y]:a[x]>a[y]);});
  for(auto i : v) {
    ll e = S.get(cmp[a[i]]-1);
    S.add(cmp[b[i]],e+h[i]);
  }
  cout << S.get(S.MXN-1) << endl;
	return 0;
}
