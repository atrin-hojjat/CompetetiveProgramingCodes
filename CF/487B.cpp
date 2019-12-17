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
#include <functional>

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
const int LOGMAXN = 17;
const int INF = 2e9+7;
int arr[MAXN];

template<typename CMP = function<int(int)>,typename T = int>
struct __rmq__ {
  T **RMQ;
  int n;
  CMP cmp;
  
  __rmq__(T*a,int n,CMP cmp) : n(n),cmp(cmp) {
    RMQ = new T*[LOGMAXN];
    FOR(i,0,LOGMAXN) RMQ[i] = new T[n+1];
    FOR(i,0,n) RMQ[0][i] = a[i];
    FOR(i,1,LOGMAXN)
      FOR(j,0,n)
        if(j+(1<<(i-1))<n)RMQ[i][j] = cmp(RMQ[i-1][j],RMQ[i-1][j+(1<<(i-1))]);
        else RMQ[i][j] = RMQ[i-1][j];
  }

  T R(int l,int i) { return RMQ[l][i]; }; 

  T get(int l,int r) {
    int lg = log(r-l+1)/log(2);
    return cmp(RMQ[lg][l],RMQ[lg][r-(1<<lg)+1]);
  }
};

int RMQ[LOGMAXN][MAXN];

int get(int l,int r) {
  int lg = log(r-l+1)/log(2);
  return min(RMQ[lg][l],RMQ[lg][r-(1<<lg)+1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,L,S;cin >> n >> S >> L;
  FOR(i,0,n) cin >> arr[i];
  auto _min = [](int a,int b) {return a<b?a:b;};
  auto _max = [](int a,int b) {return a>b?a:b;};
  arr[n] = -INF;
  __rmq__<decltype(_min)> rmq1(arr,1+n,_min);
  arr[n] =  INF;
  __rmq__<decltype(_max)> rmq2(arr,1+n,_max);
  FOR(i,0,LOGMAXN)F0R(j,0,n)RMQ[i][j] = INF;
  RMQ[0][n] = 0;
  RFOR(i,0,n) {
    int curmn = arr[i];
    int curmx = arr[i];
    int p = i;
    RFOR(l,0,LOGMAXN)
      if( (1<<l)+p<=n && abs(max(curmx,rmq2.R(l,p)) - min(curmn,rmq1.R(l,p))) <= S ) {
        curmx = max(curmx,rmq2.R(l,p)),curmn = min(curmn,rmq1.R(l,p)),p+=1<<l;
      }
    if(p-i<L) RMQ[0][i] = INF;
    else if(p==n) RMQ[0][i] = 1;
    else RMQ[0][i] = min(RMQ[0][i],get(i+L,p)+1);
    FOR(l,1,LOGMAXN)
      RMQ[l][i] = min( RMQ[l-1][i],RMQ[l-1][i+(1<<(l-1))]);
  }
  if(RMQ[0][0] == INF) cout << -1 << endl; 
  else cout << RMQ[0][0] << endl;
	return 0;
}
