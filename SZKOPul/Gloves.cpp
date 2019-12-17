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

const int MAXN = 21;
int adj[MAXN];
int col[MAXN];
int ans[MAXN];
int dp[1<<MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> col[i];
  for(int i = 0;i<n;i++) {
    int x;cin >> x;
    for(int j = 0;j<n;j++) 
      if(col[j]==x)
        adj[j]|=1<<i;
  }
  for(int i = 1;i<(1<<n);i++) {
    dp[i] = adj[__builtin_ctz(i)] | dp[i^(i&-i)]; 
    int t = __builtin_popcount(i);
    ans[t] = max(ans[t],__builtin_popcount(((1<<n)-1)^dp[i]));
  }
  int A = 1e9+7,a = 0;
  for(int i = 1;i<n;i++)
    if(ans[i]+1<A)
      a = i,A = ans[i]+1+i;
  cout << a << endl;
  cout << A-a << endl;
	return 0;
}
