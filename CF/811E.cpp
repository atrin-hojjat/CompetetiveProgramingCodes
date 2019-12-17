#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <deque>
#include <cstring>

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

const int MAXM = 1e5+6.66;
const int MAXN = 15;
int col [MAXM][MAXN];
int BIT[MAXM];
int ans[MAXM];
vector<pii> ques[MAXM];
int par[MAXM*MAXN];

void add(int x,int v) {
  while(x<MAXN)
    BIT[x]+= v,x+=x&-x;
}

int get(int x) {
  int ans = 0;
  while(x>0) ans+= BIT[x],x^=x&-x;
  return ans;
}

int get_par(int x) {
  return (par[x] ? par[x] = get_par(par[x]) : x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int n,m,q;
  cin >> n >> m >> q;
  F0R(i,1,n)
    F0R(j,1,m) cin >> col[j][i] ;
  FOR(i,0,q) {
    int x,y;
    cin >> x >> y;
    ques[y].pb(mp(z,i));
  }
  F0R(i,1,m) {
    F0R(j,1,m) {
      
    }
  }
	FOR(i,0,q)cout << ans[i] << endl;
  return 0;
}
