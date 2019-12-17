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

const int MAXN = 3e5+6.66;
const ll  MOD = 1e9+9.99;
ll fib[MAXN];
ll arr[MAXN];

void calc_fib() {
  fib[1] = 1;
  FOR(i,2,MAXN) fib[i] = (fib[i-1] + fib[i-2])%MOD;
}

ll get_fib(int i,ll k1,ll k2) {
  return (i==1?k1:(fib[i-1]*k2%MOD + fib[i-2]*k1%MOD)%MOD);
}

struct segment {
  int idx,l,r;
  ll sum;
  ll k1,k2;
  
  segment() {
    idx = l = r = -1;
    sum = k1 = k2 = 0;
  }

  segment(int idx,int l) : idx(idx),l(l),r(l+1) {
    sum = arr[l];
    k1 = k2 = 0;
  }

  segment(int idx,segment s1,segment s2) : idx(idx) {
    if(s1.idx == -1) {
      *this = s2;
      return ;
    }
    if(s2.idx == -1) {
      *this = s1;
      return ;
    }
    l = s1.l;
    r = s2.r;
    sum = (s1.sum+s2.sum)%MOD;
    k1 = k2  = 0;
  }

  void shift(ll tk1,ll tk2) {
    sum = (sum + (get_fib(r-l+2,tk1,tk2)-tk2+MOD)%MOD) %MOD;
    k1 = (k1+tk1)%MOD;
    k2 = (k2+tk2)%MOD;
  }

  void rm_shift() {
    k1 = k2 = 0;
  }
} seg[MAXN*4];

void shift(int idx) {
  ll k1 = seg[idx].k1;
  ll k2 = seg[idx].k2;
  if(k1==0 && k2==0) return ;
  int l = seg[idx].l;
  int r = seg[idx].r;
  int mid = l+(r-l)/2;
  seg[idx*2].shift(k1,k2);
  seg[idx*2+1].shift(get_fib(mid-l+1,k1,k2),get_fib(mid-l+2,k1,k2));
  seg[idx].rm_shift();
}

int intersection(int x,int y,int a,int b) {
  if(a>=y||x>=b) return 0;
  return min(b,y) - max(x,a);
}

void process(int idx,int l,int r) {
  if(l>=r) return ;
  if(r-l==1) {
    seg[idx] = segment(idx,l);
    return ;
  }
  int mid = l+(r-l)/2;
  process(idx*2,l,mid);
  process(idx*2+1,mid,r);
  seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1]);
}

void upd(int idx,int b,int e,int st) {
  if(seg[idx].idx == -1 ) return ;
  int l = seg[idx].l;
  int r = seg[idx].r;
  if(l>=e || r<=b) return ;
  if(l>=b && r<=e) {
    seg[idx].shift(fib[st],fib[st+1]);
    return;
  }
  int mid = l+(r-l)/2;
  shift(idx);
  upd(idx*2,b,e,st);
  upd(idx*2+1,b,e,st+intersection(l,mid,b,e));
  seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1]);
}

ll get(int idx,int b,int e) {
  if(seg[idx].idx==-1) return 0;
  int l = seg[idx].l;
  int r = seg[idx].r;
  if(l>=e || r<=b) return 0;
  if(l>=b && r<=e) return seg[idx].sum;
  shift(idx);
  return (get(idx*2,b,e)+get(idx*2+1,b,e) )%MOD;
}

void traverse(int idx) {
  if(seg[idx].idx == -1) return ;
  cout << seg[idx].sum << " " << seg[idx].l << " " << seg[idx].r << endl;
  if(seg[idx].r-seg[idx].l==1) return ;
  shift(idx);
  traverse(idx*2);
  traverse(idx*2+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  calc_fib();
  FOR(i,0,n) cin >> arr[i];
  process(1,0,n);
  while(m--) {
    int x,y,z;
    cin >> x >> y >> z;
    if(x==2)
      cout << get(1,y-1,z) << endl;
    else
      upd(1,y-1,z,1);
  }
	return 0;
}
