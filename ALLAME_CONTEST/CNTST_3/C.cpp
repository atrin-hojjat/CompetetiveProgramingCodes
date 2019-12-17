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

const int MAXD = 34;
const int MAXN = 1e5+6.66;
int W[MAXD];
int C[MAXN];
map<int,int> cnt;
map<int,int> CS[MAXN];

void devide(int n) {
  FOR(i,0,n) {
    int now = 0;
    auto x = cnt.rbegin();
    while(x!=cnt.rend()) {
      int ZZ = (C[i]-now)/x->F;
      CS[i][x->F]= ZZ;
      now += ZZ*x->F;
      x++;
    }
  }
}

int single_devide(int x) {
  auto w = cnt.begin();
  int ans = 0;
  int now = 0;
//  cout << x << "\t";
  while(w!=cnt.end()) {
    int ZZ = min((x-now)/w->F,w->S);
    ans += ZZ;
    w->S-= ZZ;
    now += ZZ*w->F;
//    cout << ans << "," << w->F << "," << w->S << " ";
    w++;
  }
//  cout << ans << endl;
  return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  FOR(i,0,n) cin >> C[i];
  FOR(i,0,m) {
    int x;cin >> x;
    cnt[x]++;
  }
  int I = 0;
  int ans = 0;
  for(auto x : cnt) W[++I] = x.F;
  sort(C,C+n);
  devide(n);
  FOR(i,0,MAXD) { 
    if(W[i] == 0) continue;
    FOR(j,0,n) {
      int w = CS[j][W[i]];
      while(w--)ans+= single_devide(W[i]);
    }
  }
  cout << ans << endl;
	return 0;
}
