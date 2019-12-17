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
ll arr[MAXN];

struct Int {
  ll _2,_5;

  Int() {
    _2 = _5 = 0;
  }

  Int(int x) {
    _2 = _5 = 0;
    if(!x) return ;
    while(x%2==0) _2++,x/=2;
    while(x%5==0) _5++,x/=5;
  }

/*  Int(int st,int sz) {

    _2 = get_sum(st+sz-1,2)-get_sum(st-1,2);
    _5 = get_sum(st+sz-1,5)-get_sum(st-1,5);
  }*/

  ll get_sum(int X,ll div) {
    ll ret = 0;
    ll w = div;
    while(X>=div)ret+=X/div,div=(div*w);
    return ret;
  }

  void operator*=(Int x) {
    _2 += x._2;
    _5 += x._5;
  }

  Int operator/ (Int x) {
    Int w = Int();
    w._2 = _2-x._2;
    w._5 = _5-x._5;
    return w;
  }

  Int operator*(Int x) {
    Int w = *this;
    w *= x;
    return w;
  }
  
  Int operator^(int x) {
    Int w = Int();
    w._2 = _2*x;
    w._5 = _5*x;
    return w;
  }

  ll tot() {
    return min(_2,_5);
  }

  operator bool() {
    return _2!=0 || _5!=0;
  }
} par[MAXN];

struct segment {
  int idx,l,r;
  Int now;
  Int X;
  bool sh;
  int Yst;

  segment() {
    idx = l = r = -1;
    now = Int();
    X = Int();
    Yst = 0;
    sh = false;
  }

  segment(int idx,int l) :idx(idx),l(l),r(l+1) {
    now = Int(arr[l]);
    X = Int();
    Yst = 0;
    sh = false;
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
    now = s1.now * s2.now;
    X = Int();
    Yst = 0;
    sh = false;
  }


  void shift(Int rX,int st) {
    if(st) {
      Yst = st;
      //now = Int(st,r-l);
      now = par[st+r-l-1] / par[st-1];
      X = Int();
      sh = true;
    }
    if(rX) {
      now *= rX^(r-l);
      X *= rX;
      sh = true;
    }
  }
  
  void upd(segment s1,segment s2) {
    now = s1.now * s2.now;
  }

  void rem_shift() {
    X = Int();
    Yst = 0;
    sh = false;
  }
} seg[4*MAXN];

void shift(int idx) {
  if(!seg[idx].sh) return ;
  int l = seg[idx].l,r = seg[idx].r;
  int mid = l+(r-l)/2;
  seg[idx*2].shift(seg[idx].X,seg[idx].Yst);
  seg[idx*2+1].shift(seg[idx].X,(seg[idx].Yst?seg[idx].Yst+mid-l:0));
//  seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1]);
  seg[idx].rem_shift();
}

int intersection(int x,int y,int a,int b) {
  if(a>=y||x>=b) return 0;
  return min(y,b) - max(x,a);
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

void updX(int idx,int b,int e,Int X) {
  if(seg[idx].idx==-1) return ;
  int l = seg[idx].l;
  int r = seg[idx].r;
  if(l>=e || r<=b) return ;
  if(l>=b && r<=e) {
    seg[idx].shift(X,0);
    return ;
  }
  shift(idx);
  updX(idx*2,b,e,X);
  updX(idx*2+1,b,e,X);
  seg[idx].upd(seg[idx*2],seg[idx*2+1]);
}

void updY(int idx,int b,int e,Int Y,int st) {
  if(seg[idx].idx==-1) return ;
  int l = seg[idx].l;
  int r = seg[idx].r;
  if(l>=e || r<=b) return ;
  if(l>=b && r<=e) {
    seg[idx].shift(Y,st);
    return ;
  }
  int mid = l+(r-l)/2;
  shift(idx);
  updY(idx*2,b,e,Y,st);
  updY(idx*2+1,b,e,Y,st+intersection(l,mid,b,e));
  seg[idx].upd(seg[idx*2],seg[idx*2+1]);
}

segment get(int idx,int b,int e) {
  if(seg[idx].idx == -1) return segment();
  int l = seg[idx].l;
  int r = seg[idx].r;
  if(l>=e || r<=b) return segment();
  if(l>=b && r<=e) return seg[idx];
  shift(idx);
  return segment(idx,get(idx*2,b,e), get(idx*2+1,b,e));
}

void traverse(int idx) {
  if(seg[idx].idx==-1) return;
  cout << idx << " "<< seg[idx].l << " " << seg[idx].r << " " << seg[idx].now.tot() << " " 
    << seg[idx].now._2 << " " << seg[idx].now._5 << "\n";
  if(seg[idx].r -seg[idx].l ==1 ) return ;
  shift(idx);
  traverse(idx*2);
  traverse(idx*2+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int T;cin >> T;
  FOR(i,1,MAXN) 
    par[i] = par[i-1] * Int(i);
  while(T--) {
    int n,m;cin >> n >> m;
    FOR(i,0,n) cin >> arr[i];
    process(1,0,n);
    ll ans = 0;
    while(m--) {
      ll x,y,z,w;
      cin >> x;
      switch(x) {
        case 1:
          cin >> y >> z >> w;
          updX(1,y-1,z,Int(w));
          break;
        case 2:
          cin >> y >> z >> w;
          updY(1,y-1,z,Int(w),1);
          break;
        case 3:
          cin >> y >> z;
//          cout << get(1,y-1,z).now._2 << " " << get(1,y-1,z).now._5 << endl;
          ans+= get(1,y-1,z).now.tot();
          break;
      }
//      cout << "---------" << endl;
//      traverse(1) ;
//      cout << "---------" << endl;
    }
    cout << ans << endl;
//    traverse(1);
  }
	return 0;
}
