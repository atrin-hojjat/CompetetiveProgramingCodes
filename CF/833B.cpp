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

const int MAXN = 3.5e4+6.66;
const int MAXK  = 50+6.66;
int a[MAXN];
int dp[MAXN][MAXK];
int BIT[MAXN];

void add(int x,int val) {
  while(x&&x<MAXN) 
    BIT[x] += val,x += x&-x;
}

int get(int x) {
  int ans = 0;
  while(x)
    ans += BIT[x],x^=x&-x;
  return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,k;cin >> n >> k;
  F0R(i,1,n) cin >> a[i];
  map<int,int> last;
  F0R(i,1,n) {
    add(last[a[i]],-1),add(i,1);
    last[a[i]] = i;
    dp[i][1] = get(i);
    F0R(j,2,k) {
      int l = 1,r = i;
      while(l<r) {
        int m1 = l+(r-l)/3;
        int m2 = r-(r-l)/3;
        if(m1>m2) swap(m1,m2);
        int val = get(i)-get(m1-1);
        int val2 = get(i)-get(m2-1);
        if(dp[m1-1][j-1]) {
          val += dp[m1-1][j-1];
          val2+= dp[m2-1][j-1];
          if(val>=val2)r = m2-1;
          else l = m1+1;
        } else l = m1+1;
        cout << "\t" << l << " " << r << endl;
      }
      if(l!=r)
        if(dp[l-1][j-1])
          if(dp[l-1][j-1]-get(l-1) >= dp[l][j-1]-get(l))
            r = l;
      if(dp[r-1][j-1])dp[i][j] = get(i)-get(r-1) + dp[r-1][j-1];
      cout << i << " " << j << " " << l << " " << r << " " << dp[i][j] << endl;
    }
  }
  cout << dp[n][k] << endl;
	return 0;
}
