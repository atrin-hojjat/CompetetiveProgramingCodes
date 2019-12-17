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

const int MAXN = 5e5+6.66;
vi tree[MAXN];
int _full[MAXN*2];
int _emp[MAXN*2];
int st[MAXN],et[MAXN];
int now = 0;

void dfs(int v,int p = 0) {
  st[v] = ++now;
  for(auto u : tree[v])
    if(u!=p)
      dfs(u,v);
  et[v] = now;
}

void fill_with_water(int l,int r) {
  for(l+=MAXN,r+=MAXN;l<r;l>>=1,r>>=1) {
    if(l&1) _full[l++] = now;
    if(r&1) _full[--r] = now;
  }
}

int get_last_fill(int p) {
  int ret = 0;
  for(p+=MAXN;p>0;p>>=1) ret = max(ret,_full[p]);
  return ret;
}

void empty(int p) {
  for(p+=MAXN;p>1;p>>=1) _emp[p] = now;
}

int get_last_empty(int l,int r) {
  int ret = 0;
  for(l+=MAXN,r+=MAXN;l<r;l>>=1,r>>=1) {
    if(l&1) ret = max(ret,_emp[l++]);
    if(r&1) ret = max(ret,_emp[--r]);
  }
  return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,1,n) {
    int x,y;
    cin >> x >> y;
    tree[x].pb(y);
    tree[y].pb(x);
  }
  dfs(1);
  int m;cin >> m;
  now = 1;
  while(m--) {
    int x,y;cin >> x >> y;
    switch(x) {
      case 1:
        fill_with_water(st[y],et[y]+1);
        break;
      case 2:
        empty(st[y]);
        break;
      case 3:
        cout << (get_last_fill(st[y]) > get_last_empty(st[y],et[y]+1)) << endl;
        break;
    }
    now ++;
  }
	return 0;
}
