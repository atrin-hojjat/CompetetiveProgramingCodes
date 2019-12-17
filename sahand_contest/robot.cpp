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

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef pair<pair<ll,ll>,ll> plll;
typedef vector<pair<pair<ll,ll>,ll>> vlll;

const int MAXN = 5e5+6.66;
const int ST = 5e5+1;
const int MX   = 5e5;
const ll  INF  = 1e15+6.66;
set<int> pos[MAXN*2];
vlll T[MAXN*2];
map<ll,ll> root;
map<ll,ll> A;
map<ll,bool> mark;

inline ll convert(plll w,int z) {
  if(w.F.S==INF) w.F.S = MAXN*2-1;
  if(w.F.F==-INF) w.F.F = 0;
  return 4LL*MAXN*MAXN*z + 2LL*w.F.F*MAXN + w.F.S;
}

ll get_root (ll x) {
  return (root[x] ? root[x] = get_root(root[x]) : x);
}

void merge(ll u,ll v) {
  ll rv = get_root(v);
  ll ru = get_root(u);
  if(rv==ru) return;
  root[ru] = rv;
//  cout << A[rv] << " " << A[ru] << " " ;
  if(A[rv]==-INF || A[ru] == -INF) A[rv] = -INF;
  else A[rv] = A[rv] + A[ru];
//  cout << u << " " << v << " " << A[rv] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  string str;cin >> str;
  int x = ST,y = ST;
  pos[x].insert(y);
/*  map<pii,bool> MP;
  MP[mp(x,y)] = true;
  int mnx = x,mxx = x,mny = y,mxy = y;*/
  for(auto c : str) {
    switch(c) {
      case 'U':
        y++;
        break;
      case 'D':
        y--;
        break;
      case 'L':
        x--;
        break;
      case 'R':
        x++;
        break;
    }
    /*
    MP[mp(x,y)] = true;
    mnx = min(mnx,x);
    mny = min(mny,y);
    mxx = max(mxx,x);
    mxy = max(mxy,y);
    */pos[x].insert(y);
  }
//  F0R(i,mnx,mxx) { F0R(j,mny,mxy) cout << (MP[mp(i,j)] ? "#" : ".");cout <<endl;}
//  cout << __LINE__ << endl;
  FOR(i,0,MAXN*2) {
    T[i].pb(mp(mp(-INF,(pos[i].size()?*pos[i].begin():INF)),-INF));
    if(!pos[i].size()) continue;
    auto las = --pos[i].end();
    for(auto it = pos[i].begin();it!=pos[i].end();++it) {
      if(it!=las) {
        auto x = it;
        x++;
        if(*x!=1+*it) {
          T[i].pb(mp(mp(*it,*x),*x-*it-1));
        }
      } else T[i].pb(mp(mp(*it,INF),-INF));
    }
    sort(T[i].begin(),T[i].end());
  }
  FOR(i,0,MAXN*2) for(auto w : T[i]) A[convert(w,i)] = w.S;
  FOR(i,0,MAXN*2-1) {
    auto X = T[i+1].begin();
    auto W = T[i+1].end();W--;
    for(auto x : T[i]) {
      while(X!=T[i+1].end() && X->F.S <= 1+x.F.F) X++;
      while(X!=T[i+1].end() && X->F.F+1 <  x.F.S) {
        if((x.F.F!=-INF && x.F.S!=INF)||(X->F.F!=-INF && X->F.S!=INF))
          merge(convert(x,i),convert(*X,i+1));
        if(X!=W)X++;
        else break;
      }
      if(X!=T[i+1].begin())X--;
    }
  }
  ll ans = 0;
  FOR(i,0,2*MAXN) {
    for(auto x : T[i]) {
      if(mark[get_root(convert(x,i))])continue;
      mark[get_root(convert(x,i))] = true;
      ans = max(ans,A[get_root(convert(x,i))]);
    }
  }
  cout << ans << endl;
	return 0;
}
