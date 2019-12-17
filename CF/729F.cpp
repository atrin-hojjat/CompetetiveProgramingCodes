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

const int MAXN = 4e3+6.66;
const int MAXK = 128;
int dp[MAXN][MAXK][MAXK];
int mark[MAXN][MAXK][MAXK];
int arr[MAXN];
int par[MAXN];

inline int get_sum(int l,int r) {
  return par[r] - (l>0?par[l-1] : 0);
}

void init_parsum(int n) {
  par[0] = arr[0];
  for(int i = 1;i<=n;i++) par[i] = par[i-1] + arr[i];
}

int solve(int n,int l,int r,int k) {
#define R(ll,rr) n-rr+1-ll
  if(mark[l][k][R(l,r)]) return dp[l][k][R(l,r)];
  mark[l][k][R(l,r)] = 1;
  int s1 = par[l],s2 = get_sum(r,n);
  int ans = 0;
  for(int i = 0;i<2;i++) {
    if(l+k+i >= r) break;
    int x = par[l+k+i] - s1;
    if(r-(k+i) <= l+k+i) { if(i)ans = max(ans,x);else ans = x;continue; }
    x = par[l+k+i] - s1 - get_sum(r-k-i,r-1) + solve(n,l+k+i,r-k-i,k+i);
    if(r-(k+i+1) <= l+k+i) { if(i)ans = max(ans,x);else ans = x;continue; };
    x = min(x,par[l+k+i] - s1 - get_sum(r-k-i-1,r-1) + solve(n,l+k+i,r-k-i-1,k+i+1));
    if(i)ans = max(ans,x);
    else ans = x;
  }
  return dp[l][k][R(l,r)] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  for(int i = 1;i<=n;i++) cin >> arr[i];
  init_parsum(n);
  cout << solve(n,0,n+1,1) << endl;
	return 0;
}
