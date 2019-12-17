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
int ans[MAXN];
int hei[MAXN];
int pos[MAXN];
vii ques[MAXN];

struct Segment {
  int n;
  int*arr;

  Segment(int n,int* arr) :n(n),arr(arr) {
    seg = new node[4*n]();
    process(1,0,n);
  }

  Segment(int n) : n(n) {
    arr = new int[n]();
    seg = new node[4*n]();
    fill(arr,arr+n,0);
    process(1,0,n);
  }

  void process(int idx,int l,int r) {
    if(l>=r)return ;
    if(r-l==1) {
      seg[idx] = node(idx,l,arr);
      return ;
    }
    int mid = l+(r-l)/2;
    process(idx*2,l,mid);
    process(idx*2+1,mid,r);
    seg[idx] = node(idx,seg[idx*2],seg[idx*2+1]);
  }

  struct node{
    int idx,l,r;
    int lazy;
    int val;

    node() : idx(-1),l(-1),r(-1) {lazy= val = 0;}

    node(int idx,int l,int*arr) : idx(idx),l(l),r(l+1){
      lazy = 0;
      val = arr[l];
    }

    node(int idx,node l,node r) : idx(idx){
      if(l.idx==-1) {
        *this = r;
        return ;
      }
      if(r.idx==-1) {
        *this = l;
        return ;
      }
      this->l = l.l;
      this->r = r.r;
      val = l.val+r.val;
      lazy = 0;
    }

    void shift(int lazy) {
      this->lazy += lazy;
      val += (r-l)*lazy;
    }

    void rm_shift() {
      lazy = 0;
    }
  } *seg;

  void shift(int idx) {
    if(idx*2<4*n)
      seg[idx*2].shift(seg[idx].lazy);
    if(idx*2+1<4*n)
      seg[idx*2+1].shift(seg[idx].lazy);
    seg[idx].rm_shift();
  }

  void upd(int idx,int b,int e,int v) {
    if(seg[idx].idx==-1) return ;
    int l = seg[idx].l;
    int r = seg[idx].r;
    if(r<=b || l>=e) return ;
    if(l>=b && r<=e) {
      seg[idx].shift(v);
      return ;
    }
    shift(idx);
    upd(idx*2,b,e,v);
    upd(idx*2+1,b,e,v);
    seg[idx] = node(idx,seg[idx*2],seg[idx*2+1]);
  }

  int get(int idx,int b,int e) {
    if(seg[idx].idx==-1)return 0;
    int l = seg[idx].l;
    int r = seg[idx].r;
    if(l>=e || r<=b) return 0;
    if(l>=b && r<=e) return seg[idx].val;
    shift(idx);
    return get(idx*2,b,e)+get(idx*2+1,b,e);
  }
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,0,n) cin >> pos[i] >> hei[i];
  int q;cin >> q;
  FOR(i,0,q) {
    int x,y;cin >> x >> y;
    ques[--y].pb(mp(--x,i));
  }
  stack<pii> st;
  Segment seg(n);
  FOR(i,0,n) {
    int et = i;
    while(st.size() && st.top().F < pos[i]) {
//      cout << et << " " << st.top().S << " " << pos[i]-st.top().F<< endl;
      seg.upd(1,et-1,et,pos[i]-st.top().F),et = st.top().S,seg.upd(1,et-1,et,-(pos[i]-st.top().F)),st.pop();
    }
    while(st.size() && st.top().F <= pos[i]+hei[i]) et = st.top().S,st.pop();
    st.push(mp(pos[i]+hei[i],et));
    for(auto x : ques[i])
      ans[x.S] = seg.get(1,x.F,i+1);
  }
  FOR(i,0,q) cout << ans[i] << endl;
	return 0;
}
