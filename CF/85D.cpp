#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
map<int,int> cmp;

enum QType {
  add = 0,del = 1,sum = 2,undefined = 4
};

struct Query {
  QType t;
  int v = -1;
  Query() { t = undefined,v = -1 ; }
  Query(QType t,int val) : t(t),v(val) {};
} qs[MAXN];

struct Node {
  int id;
  int l;int r;
  long long val[5];
  int laz;
  int p;

  Node() { id = l = r = -1, p = 2,memset(val,0,sizeof val),laz = 0; }

  Node(int id,int l,int v) : id(id),l(l) {
    r = l+1;
    laz = 0;
    memset(val,0,sizeof val);
    this->val[0] = v;
  }

  Node(int id,Node&l,Node&r) : id(id) {
    if(!~l.id) {
      *this = r;
      this->id = id;
      return ;
    }
    if(!~r.id) {
      *this = l;
      this->id = id;
      return ;
    }
    this->l = l.l;
    this->r = r.r;
    for(int i = 0;i<5;i++) val[i] = l.val[i] + r.val[i];
    laz = 0;
  }

  void shift(int x) {
    (laz += x)%=5;
  }

  long long get(int w) { return val[ ( w - laz + 5) % 5 ] ; }

} seg[MAXN*4];

void shift(int id) {
  if(!~seg[id<<1].id || !~seg[id<<1|1].id ) return ;
  seg[id<<1].shift(seg[id].laz);
  seg[id<<1|1].shift(seg[id].laz);
  seg[id].laz = 0;
  for(int i = 0;i< 5;i++) seg[id].val[i] = seg[id<<1].get(i) + seg[id<<1|1].get(i) ;
}

void build(int id,int l,int r) {
  if(l>=r) return ;
  if(r - l == 1) {
    seg[id] = Node(id,l,0);
    return ;
  }
  int mid = ( l + r ) /2;
  build(id<<1,l,mid);
  build(id<<1|1,mid,r);
  seg[id] = Node(id,seg[id<<1],seg[id<<1|1]);
}

void alter(int id,int b,int val) {
  if(seg[id].id == -1) return ;
  int l = seg[id].l;
  int r = seg[id].r;
  if( l > b || r <= b) return ;
  if( r - l == 1 ) {
    seg[id].val[0] += val;
    return ;
  }
  shift(id);
  int mid = (l+r)/2;
  if( b < mid) {
    alter(id<<1,b,val);
    seg[id<<1|1].shift(1);
    for(int i = 0;i<5;i++) seg[id].val[i] = seg[id<<1].get(i) + seg[id<<1|1].get(i);
  } else {
    alter(id<<1|1,b,val);
    for(int i = 0;i<5;i++) seg[id].val[i] = seg[id<<1].get(i) + seg[id<<1|1].get(i);
  }
}

void alter2(int id,int b,int val) {
  if(seg[id].id == -1) return ;
  int l = seg[id].l;
  int r = seg[id].r;
  if( l > b || r <= b ) return ;
  if( r - l == 1) {
    seg[id].val[0] -= val;
    return ;
  }
  shift(id) ;
  int mid = (l+r)/2;
  if( b < mid ) {
    alter2(id<<1,b,val);
    seg[id<<1|1].shift(4);
    for(int i = 0;i<5;i++) seg[id].val[i] = seg[id<<1].get(i) + seg[id<<1|1].get(i);
  } else {
    alter2(id<<1|1,b,val);
    for(int i = 0;i<5;i++) seg[id].val[i] = seg[id<<1].get(i) + seg[id<<1|1].get(i);
  }
}

long long get() { return seg[1].get(2); };

istream& operator>>(istream&w,Query&q) {
  string str;int z;
  w >> str;
  switch(str[0]) {
    case 'a':
      cin >> z;
      q = Query(add,z);
      break;
    case 'd':
      cin >> z;
      q = Query(del,z);
      break;
    case 's':
      q = Query(sum,-1);
      break;
    default:
      q = Query(undefined,-1);
  }
  return w;
}

int compress(int n) {
  for(int i = 0;i<n;i++) if(~qs[i].v) cmp[qs[i].v] = 0;
  int I = 0;
  for(auto&k : cmp) k.second = I++;
  return I;
}

void traverse(int i) {
  if(!~seg[i].id) return ;
  cout << seg[i].l << " " << seg[i].r << " " << seg[i].laz << "\n\t";
  for(int j = 0;j<5;j++) cout << seg[i].val[j] << " " ;;
  cout << endl;
  traverse(i<<1);
  traverse(i<<1|1);
}

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> qs[i];
  int N = compress(n);
  build(1,0,N);
  for(int i = 0;i<n;i++) {
//    traverse(1);
    switch(qs[i].t) {
      case add:
        alter(1,cmp[qs[i].v],qs[i].v);
        break;
      case del:
        alter2(1,cmp[qs[i].v],qs[i].v);
        break;
      case sum:
        cout << get() << endl;
        break;
    }
  }
  return 0;
}
