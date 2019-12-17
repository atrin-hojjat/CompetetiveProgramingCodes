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

const int MAXN = 3e5+6.66;
const int LOGMAXN = 20;
int n;
ll seg[MAXN*4];
ll lazy[MAXN*4];
int A[MAXN];
int ans [MAXN];
vii ques[MAXN];
int RMQ[LOGMAXN][MAXN];

void shift(int x,int l,int r) {
  int mid = l+(r-l)/2;
  if(!lazy[x]) return ;
  seg[x*2] += lazy[x] * (mid-l);
  seg[x*2+1] += lazy[x] * (r-mid);
  lazy[x*2] += lazy[x];
  lazy[x*2+1] += lazy[x];
  lazy[x] = 0;
}

void upd(int x,int l,int r,int b,int e) {
  if(l>=r) return ;
  if(b>=r || l >= e) return ;
  if(b<=l && r<=e) {
    seg[x] += r-l;
    lazy[x]++;
    return ;
  }
  shift(x,l,r);
  int mid = l+(r-l)/2;
  upd(x*2,l,mid,b,e);
  upd(x*2+1,mid,r,b,e);
}

ll query(int x,int l,int r,int b,int e) {
  if(l>=r) return 0;
  if(b>=r || l >=e ) return 0;
  if(b<=l && r<=e) return seg[x];
  shift(x,l,r);
  int mid = l+(r-l)/2;
  return query(x*2,l,mid,b,e) + query(x*2+1,mid,r,b,e);
}

void init_rmq() {
  F0R(i,1,n) RMQ[0][i] = A[i];
  FOR(i,1,LOGMAXN)
    F0R(j,1,n)
      if(j+(1<<(i-1))<=n)RMQ[i][j] = max(RMQ[i-1][j], RMQ[i-1][j+(1<<(i-1))] );
      else RMQ[i][j] = RMQ[i-1][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int m;cin >> n >> m;
  FOR(i,0,m) {
    int x,y;cin >> x >> y;
    A[max(x,y)] = max(A[max(x,y)],min(x,y));
  }
  init_rmq();
  int Q;cin >> Q;
  FOR(i,0,Q) {
    int x,y;cin >> x >> y;
    ques[y].pb(mp(x,i));
  }
  F0R(i,1,n) {
    int now = i;
    int cur = RMQ[0][i];
    RFOR(j,0,LOGMAXN)
      if(now-(1<<j) >0 && max(cur,RMQ[j][now-(1<<j)])<now-(1<<j))
        cur = max(cur,RMQ[j][now-(1<<j)]),now -=(1<<j);
    cout << i << " " << now << " " << cur << endl;
    upd(1,1,n+1,now,i+1);
    for(auto x : ques[i]) 
      ans[x.S] = query(1,1,n+1,x.F,i+1);
  }
  FOR(i,0,Q) cout << ans[i] << endl;
	return 0;
}
