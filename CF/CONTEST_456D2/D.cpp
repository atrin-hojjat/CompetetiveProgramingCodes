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
#include <iomanip>

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
typedef pair<ll,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 2e5+6.66;
map<int,bool> vis[MAXN];
map<int,bool> add[MAXN];

inline ll length(int n,int r,int x) {
  return min(n-r,x) - max(0,x-r+1) +1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m,r,k;cin >> n >> m >> r >> k;
  priority_queue<piii> q;
  q.push({1LL*length(n,r,n/2)*length(m,r,m/2),{n/2,m/2}});
  int cnt = 0;
  long double ans = 0;
  while(cnt<k && q.size()) {
    int x = q.top().S.F;
    int y = q.top().S.S;
    ll W = q.top().F;
    q.pop();
    if(vis[x][y] ) continue;
    cnt++;
    ans += W;
//    cout << x << " " << y << " " << W << endl;
    vis[x][y] = true;
#define check(x,y)  x<n && y<m && x >-1 && y> -1 && !add[x][y] && !vis[x][y]
    if(check(x-1,y)) add[x-1][y] = true,q.push({1LL*length(n,r,x-1)*length(m,r,y),{x-1,y}});
    if(check(x+1,y)) add[x+1][y] = true,q.push({1LL*length(n,r,x+1)*length(m,r,y),{x+1,y}});
    if(check(x,y-1)) add[x][y-1] = true,q.push({1LL*length(n,r,x)*length(m,r,y-1),{x,y-1}});
    if(check(x,y+1)) add[x][y+1] = true,q.push({1LL*length(n,r,x)*length(m,r,y+1),{x,y+1}});
#undef check
  }
//  cout << ans << endl;
  ans /= 1LL * (n-r+1)*(m-r+1);
  cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
