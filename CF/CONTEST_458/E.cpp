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

const int MAXN = 2e5+6.66;
const int LOGMAXN = 20;
const int MAXL = (1<<LOGMAXN) + 6.66;
vector<int> tree[MAXN];
int CNT[MAXL],CNT2[MAXL];
char C[MAXN];
int sz[MAXN];
ll ANS[MAXN];
bool mark[MAXN];

struct Letter {
  bool cnt['t'-'a'+1];
  
  Letter() { memset(cnt,0,sizeof cnt); }

  void operator+=(char ch) {
    cnt[ch-'a'] ^=1;
  }

  Letter operator+(Letter y) {
    Letter w = Letter();
    for(int i = 0;i<='t'-'a';i++)
      w[i] = cnt[i]^y[i];
    return w;
  }

  bool& operator[](int x) {return cnt[x];}

  bool operator<(Letter y) const{
    for(int i = 0;i<='t'-'a';i++)
      if(!cnt[i] && y[i]) return true;
      else if(!y[i] && cnt[i]) return false;
    return false;
  }

  int operator() () {
    int W = 0;
    for(int i = 0;i<='t'-'a';i++)W|=(cnt[i]<<i);
    return W;
  }
} let[MAXN];
vector<Letter> vW[MAXN];

int sz_dfs(int v,int p = 0) {
  if(mark[v]) { return sz[v] = 0;}
  sz[v] = 1;
  for(auto u : tree[v])
    if(u!=p) sz[v] += sz_dfs(u,v);
  return sz[v];
}

int get_cent(int v,int p,int T) {
  for(auto u : tree[v])
    if(u!=p && !mark[u] && sz[u] > T) return get_cent(u,v,T);
  return v;
}

void dis_from_cent(int v,int p,vector<Letter>&X,Letter w) {
  if(mark[v]) return;
  w += C[v];
  X.push_back(w);
  for(auto u : tree[v])
    if(u!=p)
      dis_from_cent(u,v,X,w);
}

void dis_calc(int v,int p,int ww,Letter w) {
  if(mark[v]) return ;
  w+=C[v];
  vW[ww] .push_back(w);
  for(auto u : tree[v])
    if(u!=p) dis_calc(u,v,ww,w);
}

inline int eq_range(vector<Letter>::iterator b,vector<Letter>::iterator e,Letter w) {
//  pair<vector<Letter>::iterator,vector<Letter>::iterator> zz = equal_range(b,e,w);
//  cout << zz.S -b << " " << zz.F -b << endl;
//  return zz.S - zz.F;
  return 
}

int EQ(Letter v,vector<Letter>&z) {
  int ans = eq_range(z.begin(),z.end(),v);
  for(int i = 0;i<='t'-'a';i++) {
    v += 'a'+i;
    ans += eq_range(z.begin(),z.end(),v);
    v += 'a'+i;
  }
  return ans;
}

int ans_calc(int v,int p,int ww,vector<Letter>&XX,Letter w) {
  if(mark[v]) return 0;
  w += C[v];
  ll ans = EQ(w,XX) - EQ(w,vW[ww]);
  for(auto u : tree[v]) 
    if(u!=p)
      ans += ans_calc(u,v,ww,XX,w);
  ANS[v] += ans;
  return ans;
}

void decompose(int v) {
  sz_dfs(v);
  int cent = get_cent(v,0,sz[v]/2);
  v = cent;
//  cout << cent << endl;
  vector<Letter> XX;
  dis_from_cent(cent,cent,XX,Letter());
  sort(XX.begin(),XX.end());
//  for(auto w : XX) {
//    for(int i = 0;i<='t'-'a';i++) cout << w[i];
//    cout << endl;
//  }
  Letter temp = Letter();temp += C[cent];
  mark[cent] = true;
  for(auto ww : tree[cent]) {
    if(mark[ww]) continue;
    vW[ww].clear();
    dis_calc(ww,cent,ww,temp);
    sort(vW[ww].begin(),vW[ww].end());
  }
  ll ans = 0;
  for(auto ww : tree[cent]) {
    if(mark[ww]) continue;
    ans += ans_calc(ww,cent,ww,XX,Letter());
  }
  ans += EQ(Letter(),XX)+1;
  ANS[cent] += ans/2;
  for(auto ww : tree[cent])
    if(!mark[ww])
      decompose(ww);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  for(int i = 1;i<n;i++) {
    int x,y;cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  string str;cin>> str;
  int I = 1;for(auto ch : str) C[I++] = ch;
  decompose(1);
  for(int i = 1;i<=n;i++) cout << ANS[i] << " " ;cout << endl;
	return 0;
}
