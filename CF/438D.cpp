#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const int inf = 1e9 + 7;
long long seg[MAXN * 4];
int mx[ MAXN * 4 ];
int mn[ MAXN * 4 ];
int laz[ MAXN * 4 ];
int arr[MAXN];

void single_shift(int id,int l,int r,int val) {
  laz[id] = val;
  mn[id] = mx[id] = val;
  seg[id] = 1LL * ( r - l ) * val;
}

void shift(int id,int l,int r) {
  if( !~laz[id] ) return ;
  int mid = ( l + r ) >> 1;
  single_shift(id<<1,l,mid,laz[id]);
  single_shift(id<<1|1,mid,r,laz[id]);
  laz[id] = -1;
}

void upd_self(int id) {
  mx[id] = max(mx[id<<1],mx[id<<1|1]);
  mn[id] = min(mn[id<<1],mn[id<<1|1]);
  seg[id] = seg[id<<1] + seg[id<<1|1];
}

void build(int id,int l,int r) {
  laz[id] = -1;
  if( l >= r ) {
    mn[id] = inf;
    mx[id] = -inf;
    return ;
  }
  if( r - l == 1 ) {
    mn[id] = seg[id] = mx[id] = arr[l] ;
    return ;
  }
  int mid = ( l + r ) >> 1;
  build(id<<1,l,mid);
  build(id<<1|1,mid,r);
  upd_self(id);
}

long long get(int id,int l,int r,int b,int e) {
  if( l >= r ) return 0;
  if( l >= e || r <= b ) return 0;
  if( l >= b && r <= e ) return seg[id];
  shift(id,l,r);
  int mid = ( l + r ) >> 1;
  return get( id<<1, l,mid,b,e) + get(id<<1|1,mid,r,b,e);
}

void alter(int id,int l,int r,int x,int val) {
  if( x < l || x >= r ) return ;
  if( r - l == 1 ) {
    seg[id] = mn[id] = mx[id] = val;
    return ;
  }
  shift(id,l,r);
  int mid = ( l + r ) >> 1;
  alter(id<<1,l,mid,x,val),alter(id<<1|1,mid,r,x,val);
  upd_self(id);
}

void modular(int id,int l,int r,int b,int e,int mod) {
  if( l >= r ) return ;
  if( l >= e || r <= b || mx [id] < mod ) return ;
  if( l >= b && r <= e && mx [id] == mn[id] ) {
    mn[id] = (mx[id]%=mod);
    seg[id] = 1LL * ( r - l ) * mn[id];
    laz[id] = mn[id];
    return ;
  }
  shift(id,l,r);
  int mid = ( l + r ) >> 1;
  modular(id<<1,l,mid,b,e,mod);
  modular(id<<1|1,mid,r,b,e,mod);
  upd_self(id);
}

void traverse(int id,int l,int r) {
  if( l >= r ) return ;
  printf("%d %d %d %d %d\n" ,l,r,seg[id],mn[id],mx[id]);
  if( r - l == 1 ) return ;
  int mid = ( l + r ) >> 1;
  traverse(id<<1,l,mid);
  traverse(id<<1|1,mid,r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,m;scanf("%d %d",&n,&m);
  for(int i = 0;i<n;i++) scanf("%d",arr + i);
  build(1,0,n);
  while(m--) {
    int T;scanf("%d",&T);
    int l,r; scanf("%d %d",&l,&r);
    if( T == 1 ) printf("%lld\n",get(1,0,n,--l,r));
    else if ( T == 2 ) {
      int D;scanf("%d",&D);
      modular(1,0,n,--l,r,D);
    } else alter(1,0,n,--l,r);
//    traverse(1,0,n);
//    printf("------------------------\n");
  }
  return 0;
}
