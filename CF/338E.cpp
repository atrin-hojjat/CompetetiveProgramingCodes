#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1.5e5 + 6.66;
const int inf = 1e9+7;
int seg[MAXN*4],laz[MAXN*4];
int a[MAXN],b[MAXN];
int n,m,h;

void shift(int id,int val) {
  seg[id] += val;
  laz[id] += val;
}

void shift(int id) {
  shift(id<<1,laz[id]);
  shift(id<<1|1,laz[id]);
  laz[id] = 0;
}

void build(int id,int l,int r) {
  if(l>=r) return;
  if(r - l == 1) {
    seg[id] = -l-1;
    return ;
  }
  int mid = l + (r-l)/2;
  build(id<<1,l,mid);
  build(id<<1|1,mid,r);
  seg[id] = min(seg[id<<1],seg[id<<1|1]);
}

void alter(int id,int l,int r,int b,int e,int val) {
  if(l>=r) return ;
  if( l >= e || r <= b) return ;
  if( l >= b && r <= e) {
    seg[id] += val;
    laz[id] += val;
    return ;
  }
  shift(id);
  int mid = (l+r)>>1;
  alter(id<<1,l,mid,b,e,val);
  alter(id<<1|1,mid,r,b,e,val);
  seg[id] = min(seg[id<<1],seg[id<<1|1]);
}

int get(int id,int l,int r,int b,int e) {
  if(l>=r) return inf;
  if( l >= e || r <= b ) return inf;
  if( l >= b && r <= e ) return seg[id];
  shift(id);
  int mid = (l+r)>>1;
  return min(get(id<<1,l,mid,b,e),get(id<<1|1,mid,r,b,e));
}

void rem(int val) {
  int f = h - a[val];
  int pos = lower_bound(b,b+m,f) - b;
  if(pos<m) alter(1,0,m,pos,m,-1);
}

void add(int val) {
  int f = h - a[val];
  int pos = lower_bound(b,b+m,f) - b;
  if(pos<m) alter(1,0,m,pos,m,1);
}

int get_min() {
  return get(1,0,m,0,m);
}

int main() {
  cin >> n >> m >> h;
  for(int i = 0;i<m;i++) cin >> b[i];
  for(int i = 0;i<n;i++) cin >> a[i];
  sort(b,b + m);
  build(1,0,m);
  int ans = 0;
  for(int i = 0;i<n;i++) {
    if(i >= m) rem(i-m);
    add(i);
    if(get_min() >= 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
