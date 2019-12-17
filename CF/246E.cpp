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
typedef pair<pii,int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e5+6.66;
vi tree[MAXN];
vi timeline[MAXN];
string name[MAXN];
int st[MAXN],et[MAXN];
int ans[MAXN];
vii ques[MAXN];
int h[MAXN];
int now;

void dfs(int v = 0,int p = 0,int hei = 0) {
  h[v] = hei++;
  st[v] = now++;
  timeline[h[v]].pb(v);
  for(auto u : tree[v])
    if(u!=p)
      dfs(u,v,hei);
  et[v] = now;
}

struct BIT {
  int *bit;
  int n;

  BIT(int n) : n(n) {
    bit = new int[2+n]();
  }

  void add(int x,int val) {
    while(x<=n)
      bit[x] += val,x+=x&-x;
  }

  int get(int x) {
    int ans = 0;
    while(x)
      ans += bit[x],x^=x&-x;
    return ans;
  }

  void del() {
    delete[] bit;
  }
};

void process_queries() {
  FOR(I,1,MAXN) {
    if(timeline[I].size()==0) break;
    sort(ques[I].begin(),ques[I].end(),[](pii x,pii y) { return et[x.F] < et[y.F] ; });
    BIT s(timeline[I].size()+1);
    map<string,int> last;
    auto it = ques[I].begin();
    int i = 1;
    for(auto x : timeline[I]) {
      while(it!=ques[I].end() && et[it->F]<st[x])
        ans[it->S] = s.get(timeline[I].size()) - s.get(
          lower_bound(timeline[I].begin(),timeline[I].end(),it->F,[](int x,int y){return st[x]<st[y];})-timeline[I].begin()),it++;
      if(last[name[x]])
        s.add(last[name[x]],-1);
      s.add(i,1);
      last[name[x]] = i;
      i++;
    }
    while(it!=ques[I].end())
      ans[it->S] = s.get(timeline[I].size()) - s.get(
        lower_bound(timeline[I].begin(),timeline[I].end(),it->F,[](int x,int y){return st[x]<st[y];})-timeline[I].begin()),it++;
//    cout << s.get(timeline[I].size()) << endl;
    s.del();
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  F0R(i,1,n) {
    int x;
    cin >> name[i] >> x;
    tree[x].pb(i);
  }
  dfs();
  int m;cin >> m;
  F0R(i,1,m) {
    int v,k;cin >> v >> k;
    if(h[v]+k >= MAXN) ans[i] = 0;
    else ques[h[v]+k].pb(mp(v,i));
  }
  process_queries();
  F0R(i,1,m) cout << ans[i] << endl;
	return 0;
}
