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
const int LOGMAXN = 18+.666;
int RMQ[LOGMAXN][MAXN];
map<int,ll> ans;

int gcd(int x,int y) {
  return (y==0?x:gcd(y,x%y));
}

void init(int n) {
  FOR(i,1,LOGMAXN)
    FOR(j,0,n)
      if(j+(1<<i) <= n)
        RMQ[i][j] = gcd(RMQ[i-1][j],RMQ[i-1][j+(1<<(i-1))]);
}

void process(int n) {
  FOR(i,0,n) {
    int cur = RMQ[0][i],p = i;
    while(cur>1 && p<n) {
      int pp = 1+p;
      RFOR(l,0,LOGMAXN) 
        if((1<<l)+pp<n && RMQ[l][pp]%cur == 0) 
          pp = pp+(1<<l);
      ans[cur] += pp-p;
      p = pp;
      cur = gcd(RMQ[0][p],cur);
    }
    ans[1] += n-p;
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,0,n) cin >> RMQ[0][i];
  RMQ[0][n] = 1;
  init(n);
  process(n);
  int m;cin >> m;
  while(m--) {
    int x;cin >> x;
    cout << ans[x] << endl;
  }
	return 0;
}
