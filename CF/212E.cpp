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

const int MAXN = 5e3+6.66;
bool ans[MAXN];
vector<int> tree[MAXN];
int sz[MAXN];
bool tmp[MAXN];
int n;

int init_sz(int v = 1,int p = 0) {
  sz[v] = 1;
  for(auto u : tree[v])
    if(u!=p)
      sz[v] += init_sz(u,v);
  return sz[v];
}

void solve(int v = 1,int p = 0) {
  fill(tmp,tmp+MAXN,false);
  tmp[0] = true;
  for(auto u : tree[v]) {
    int ss = sz[u];
    if(u==p) ss = n - sz[v];
    for(int i = n-ss-1;i>=0;--i)
      tmp[i+ss]|= tmp[i];
  }
  for(int i = 0;i<=n;i++)
    ans[i] |= tmp[i];
  for(auto u : tree[v])
    if(u!=p)
      solve(u,v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i = 1;i<n;i++) {
    int x,y;cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  init_sz();
  solve();
  int A = 0;
  for(int i = 1;i<n-1;i++) A += ans[i];
  cout << A << endl;
  for(int i = 1;i<n-1;i++)
    if(ans[i])
      cout << i << " " << n-i-1 << endl;
	return 0;
}
