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

const int MAXN = 2e5+6.66;
const int LOGMAXN = 20;
const int INF = 1e9+7;
int RMQa[LOGMAXN][MAXN];
int RMQb[LOGMAXN][MAXN];

void init(int n) {
  RMQa[0][n] = -(RMQb[0][n] = INF);
  FOR(i,1,LOGMAXN)
    FOR(j,0,n) {
      RMQa[i][j] = min(RMQa[i-1][j],(j+(1<<(i-1))<=n?RMQa[i-1][j+(1<<(i-1))]: INF));
      RMQb[i][j] = max(RMQb[i-1][j],(j+(1<<(i-1))<=n?RMQb[i-1][j+(1<<(i-1))]:-INF));
    }
}

void solve(int n) {
  ll ans = 0;
  FOR(i,0,n) {
    int curA = RMQa[0][i];
    int curB = RMQb[0][i];
    int pos = i;
    if(curA==curB) ans++;
    RFOR(l,0,LOGMAXN)
      if( pos+(1<<l)<n && min(curA,RMQa[l][pos]) > max(curB,RMQb[l][pos]) ) 
          curA = min(curA,RMQa[l][pos]),curB = max(curB,RMQb[l][pos]),pos += 1<<l;
    if(pos==i) pos++;
    int pos1 = pos;
    curA = min(curA,RMQa[0][pos1]),curB = max(curB,RMQb[0][pos1]);
    if(curA != curB) continue;
    RFOR(l,0,LOGMAXN)
      if( pos1+(1<<l)<=n && min(curA,RMQa[l][pos1]) == max(curB,RMQb[l][pos1]) )
         pos1 += 1<<l;
    ans += pos1-pos;
  }
  cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(j,0,n) cin >> RMQb[0][j];
  FOR(i,0,n) cin >> RMQa[0][i];
  init(n);
  solve(n);
	return 0;
}
