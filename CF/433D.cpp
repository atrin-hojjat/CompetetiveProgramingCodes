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

const int MAXN = 1e3+6.66;
int U[MAXN][MAXN];
int D[MAXN][MAXN];
int L[MAXN][MAXN];
int R[MAXN][MAXN];
bool arr[MAXN][MAXN];
int tmp[MAXN],pos[MAXN];
struct DSU {
  int r[MAXN];

  void init(int n) {
    F0R(i,0,n+1) r[i] = i;
  }

  int get(int v) {
    return (r[v]==v ? v : r[v] = get(r[v]));
  }

  void merge(int v,int u) {
    r[get(v)] = get(u);
  }
} le,ri;

int calc(int n,int x) {
  F0R(i,1,n) pos[i] = i;
  sort(pos+1,pos+n+1,[](int x,int y) { return tmp[x]>tmp[y];});
  le.init(n),ri.init(n);
  int ans = 0;
  F0R(i,1,n) {
    int l = le.get(pos[i]-1)+1;
    int r = ri.get(pos[i]+1)-1;
    if(l<=x && x<=r) ans = max(ans,(r-l+1)*tmp[pos[i]]);
    le.merge(pos[i],pos[i]-1);
    ri.merge(pos[i],pos[i]+1);
  }
  return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m,q;cin >> n >> m >> q;
  F0R(i,1,n)F0R(j,1,m) cin >> arr[i][j];
  F0R(i,1,n)F0R(j,1,m)
    if(arr[i][j]) {
      U[i][j] = U[i-1][j]+1;
      L[i][j] = L[i][j-1]+1;
    } else U[i][j] = L[i][j] = 0;
  RF0R(i,1,n)RF0R(j,1,m)
    if(arr[i][j]) {
      D[i][j] = D[i+1][j]+1;
      R[i][j] = R[i][j+1]+1;
    } else D[i][j] = R[i][j] = 0;
  while(q--) {
    int x,y,z;
    cin >> x >> y >> z;
    if(x==1) {
      arr[y][z] ^= 1;
      F0R(i,y,n)
        if(arr[i][z]) U[i][z] = U[i-1][z]+1;
        else U[i][z] = 0;
      F0R(i,z,m)
        if(arr[y][i]) L[y][i] = L[y][i-1]+1;
        else L[y][i] = 0;
      RF0R(i,1,y)
        if(arr[i][z]) D[i][z] = D[i+1][z]+1;
        else D[i][z] = 0;
      RF0R(i,1,z)
        if(arr[y][i]) R[y][i] = R[y][i+1]+1;
        else R[y][i] = 0;
    } else {
      int ans = 0;
      F0R(i,1,m) tmp[i] = U[y][i];
      ans = max(ans,calc(m,z));
      F0R(i,1,m) tmp[i] = D[y][i];
      ans = max(ans,calc(m,z));
      F0R(i,1,n) tmp[i] = L[i][z];
      ans = max(ans,calc(n,y));
      F0R(i,1,n) tmp[i] = R[i][z];
      ans = max(ans,calc(n,y));
      cout << ans << endl;
    }
  }
	return 0;
}
