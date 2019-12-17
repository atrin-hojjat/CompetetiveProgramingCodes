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
#define _ITFOR(it,v)        for(__typeof(v.begin()) it =v.begin();it!=v.end();++it)
#define ITFOR(it,b,e)       for(__typeof(b) it = b;it!=e;++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e5+6.66;
const int INF = 1e5+666;
int seg[MAXN*4];
int l1[MAXN*4];
int dpe[MAXN];
int dpw[MAXN];
set<int> west[MAXN];
set<int> east[MAXN];

void shift(int idx,int l,int r) {
  int mid = l+(r-l)/2;
  seg[idx*2]+=l1[idx];
  seg[idx*2+1]+=l1[idx];
  l1[idx*2] += l1[idx];
  l1[idx*2+1]+= l1[idx];
  l1[idx] = 0;
}

void upd(int idx,int l,int r,int b,int e) {
  if(l>=r || l>=e || r<=b) return ;
  if(l>=b && r<=e) {
    l1[idx]++;
    seg[idx]++;
    return ;
  }
  shift(idx,l,r);
  int mid = l+(r-l)/2;
  upd(idx*2,l,mid,b,e);
  upd(idx*2+1,mid,r,b,e);
  seg[idx] = min(seg[idx*2],seg[idx*2+1]);
}

void upd_one(int idx,int l,int r,int x,int val) {
  if(l>=r || x>=r || x<l) return; 
  if(r-l==1) {
    seg[idx] = val;
    return ;
  }
  shift(idx,l,r);
  int mid = l+(r-l)/2;
  upd_one(idx*2,l,mid,x,val);
  upd_one(idx*2+1,mid,r,x,val);
  seg[idx] = min(seg[idx*2] , seg[idx*2+1]);
}

int get_min(int idx,int l,int r,int b,int e) {
  if(l>=r || b>= r || l>=e ) return INF;
  if(b<=l && e>=r) return seg[idx];
  shift(idx,l,r);
  int mid = l+(r-l)/2;
  return min(get_min(idx*2,l,mid,b,e) , get_min(idx*2+1,mid,r,b,e));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int n,m,k,p;
	cin >> n >> m >> p >> k;
  FOR(i,0,p) {
    int x,y,z;cin >> x >> y >> z;
    if(z) 
      west[x+1].insert(y);
    else
      east[x].insert(y);
  }
  fill(seg,seg+4*MAXN,0);
  fill(l1,l1+4*MAXN,0);
  F0R(i,2,n) {
    map<int,int> ww ;
    for(auto u : west[i])
      ww[u] = get_min(1,0,m+1,u,m+1);
    upd(1,0,m+1,0,m+1);
    for(auto u : ww)
      upd_one(1,0,m+1,u.F,u.S);
    dpw[i] = get_min(1,0,m+1,0,m+1);
  }
  fill(seg,seg+4*MAXN,0);
  fill(l1,l1+4*MAXN,0);
  RF0R(i,1,n-1) {
    map<int,int> ww ;
    for(auto u : east[i])
      ww[u] = get_min(1,0,m+1,u,m+1);
    upd(1,0,m+1,0,m+1);
    for(auto u : ww)
      upd_one(1,0,m+1,u.F,u.S);
    dpe[i] = -get_min(1,0,m+1,0,m+1);
  }
  int prv = 0;
  F0R(i,1,n)
    if(dpw[i]==dpe[i] && dpe[i]==0) prv++;
  int ans = 0;
  F0R(i,1,n) {
    ans = max(ans ,(int) i-(int)(lower_bound(dpe+1,dpe+n+1,-k+dpw[i])-dpe)+1);
  }
  cout << ans-prv << endl;
  return 0;
}
