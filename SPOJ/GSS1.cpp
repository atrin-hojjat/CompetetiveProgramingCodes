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

const int MAXN = 5e4+6.66;
const int LOGMAXN = 17;
const int INF = 1e6+6.66;
int RMQ[LOGMAXN][MAXN];

void init_rmq(int n) {
  RFOR(i,1,LOGMAXN)
    F0R(j,1,n)
      RMQ[i][j] = max(RMQ[i-1][j],((j+(1<<(i-1)))<=n?RMQ[i-1][j+(1<<(i-1))]:-INF));
}

int get(int l,int r) {
  int lg = log(r-l+1)/log(2);
  return max(RMQ[lg][l],RMQ[lg][r-(1<<lg)+1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  F0R(i,1,n) cin >> RMQ[0][i];
  init_rmq(n);
  int m;cin >> m;
  while(m--) {
    int x,y; cin >> x >> y;
    cout << get(x,y) << endl;
  }
	return 0;
}
