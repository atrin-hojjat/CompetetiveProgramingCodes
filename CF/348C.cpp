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

const int MAXN = 1e5+6.66;
const int SQ = 333;
map<int,bool> S[MAXN];
map<int,int> intersection[MAXN];
set<int> ON;
ll ongoing[MAXN];
ll sum[MAXN];
ll arr[MAXN];

int get_intersection(int a,int b) {
  if(a==b) return S[a].size();
  if(mp(S[a].size(),a) >  mp(S[b].size(),b)) swap(a,b);
  if(intersection[a][b]) return intersection[a][b];
  int ans = 0;
  for(auto x : S[a])
    if( S[b].count(x.F) )
      ans++;
  return intersection[a][b] = ans;
}

void relax(int m) {
  for(auto i : ON)
    for(auto w : S[i])
      arr[w.F] += ongoing[i];
  F0R(i,1,m) {
    sum[i] = 0;
    for(auto x : S[i]) {
      sum[i] += arr[x.F];
    }
  }
  memset(ongoing,0,sizeof ongoing);
  ON.clear();
}

void query() {
  int x;cin >> x;
  ll ans = sum[x];
  for(auto w : ON)
    ans += get_intersection(w,x) * ongoing[w];
  cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m,q;cin >> n >> m >> q;
  F0R(i,1,n) cin >> arr[i];
  F0R(i,1,m) {
    int x;cin >> x;
    FOR(j,0,x) {
      int w;cin >> w;
      S[i][w] = true;
    }
  }
  relax(m);
  FOR(i,0,q){
    char ch;cin >> ch;
    if( ch == '?') query();
    else {
      ll a,b;cin >> a >> b;
      ongoing[a] += b;
      ON.insert(b);
    }
    if(i%SQ==SQ-1) relax(m);
  }
	return 0;
}
