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
const int MAXV = 1e6+6.66;
const int MAXL = 8;
int cnt[MAXV];
int arr[MAXN];
struct Node {
  ll val[8];
  int id = -1,l,r;
  int sh_ = 0;

  Node() {
    id = l = r = -1;
    sh_ = 0;
    memset(val,0,sizeof val);
  }

  Node(int x,int id,int l,int r) : id(id),l(l),r(r) {
    for(int i = 0;i<MAXL;i++)
      val[i] = x,(x = cnt[x]);
  }

  Node(int id,Node left,Node right) {
    if(!~left.id) {
      *this = right;
      this->id = id;
      return;
    }
    if(!~right.id) {
      *this = left;
      this->id = id;
      return ;
    }
    this-> id = id;
    l = left.l;
    r = right.r;
    for(int i = 0;i<MAXL;i++)
      val[i] = right.val[i] + left.val[i];
  }

  void shift(int x) {
    sh_ += x;
    for(int i = 0;i<MAXL;i++)
      val[i] = val[min(MAXL-1,i+x)];
  }

  void rm_shift() {
    sh_ = 0;
  }

} seg[MAXN*4];

void shift_to_children(int i) {
  if(!seg[i].sh_) return; 
  seg[i<<1] .shift(seg[i].sh_);
  seg[i<<1|1].shift(seg[i].sh_);
  seg[i].rm_shift();
}

void build(int id,int l,int r) {
  if(l>=r) return ;
  if(r-l==1) {
    seg[id] = Node(arr[l],id,l,r);
    return;
  }
  int mid = (l+r)>>1;
  build(id<<1,l,mid);
  build(id<<1|1,mid,r);
  seg[id] = Node(id,seg[id<<1],seg[id<<1|1]);
}

void update(int i,int b,int e) {
  if(seg[i].id==-1) return ;
  int l = seg[i].l;
  int r = seg[i].r;
  if(l>=e || r<=b) return; 
  if(l>=b && r<=e) {
    seg[i].shift(1);
//    cout << " 1 "<< l << " " << r << " " << b << " " << e << " " << seg[i].val[0] << endl;
    return;
  }
  shift_to_children(i);
  update(i<<1,b,e);
  update(i<<1|1,b,e);
  seg[i] = Node(i,seg[i<<1],seg[i<<1|1]);
//  cout << l << " " << r << " " << b << " " << e << " " << seg[i].val[0] << endl;
}

ll get(int i,int b,int e) {
  if(seg[i].id==-1) return 0;
  int l = seg[i].l;
  int r = seg[i].r;
  if(l>=e || r<=b) return 0;
  if(l>=b && r<=e) return seg[i].val[0];
  shift_to_children(i);
  return 1LL* get(i<<1,b,e) + get(i<<1|1,b,e);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  for(int i = 1;i<MAXV;i++) 
    for(int j = i;j<MAXV;j+=i)
      cnt[j] ++;
  for(int i = 0;i<n;i++) cin >> arr[i];
  build(1,0,n);
  while(m--) {
    int a,b,c;cin >> a >> b >> c;
    if(a&1) {
      update(1,b-1,c);
    } else {
      cout << get(1,b-1,c) << "\n";
    }
  }
	return 0;
}
