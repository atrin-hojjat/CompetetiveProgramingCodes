#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const int inf  = 1e9 + 7;
const int MAX = 2 * MAXN;
const int H = sizeof(int) * 8 - __builtin_clz(MAXN);
int luckies[64];
int arr[MAXN];
int val[MAXN];

struct Node {
  int mn;
  int pos;
  int cnt;
  int laz;

  Node() { cnt = 0,pos = -1,mn = inf,laz = 0; };
  Node(int a,int b,int c) : mn(a),cnt(b),pos(c) {laz = 0;}

  void Min(Node x) {
    if(!~x.pos) return;
    if( mn < x.mn) return ;
    if( mn == x.mn ) { cnt += x.cnt; return ; }
    putin(x);
  }

  void putin(Node x) {
    mn = x.mn,pos = x.pos,cnt = x.cnt;
  }

  void add(int d) { if(~pos) mn += d,laz += d; }
} nodes[MAX];

void upd(int x) {
  if(x > MAXN) return ;
  nodes[x].putin(nodes[x<<1]);
  nodes[x].Min(nodes[x<<1|1]);
  nodes[x].mn += nodes[x].laz;
//  cout << x << " " << nodes[x].mn << " " << nodes[x].cnt << " " << nodes[x].pos << endl;
}

void build(int l,int r) {
  int k = 2;
  for( l += MAXN, r += MAXN-1; l > 1; k<<=1 ) {
    l >>= 1,r >>= 1;
//    cout << l << " " << r << "\n" ;
    for(int i = r;i >=l;--i) upd(i);
  }
}

void push(int l) {
  l+= MAXN;
  for(int s = H; s > 0; --s ) {
    int i = l >> s;
    if(nodes[i].laz != 0) {
      nodes[i << 1] .add( nodes[i].laz );
      nodes[i << 1|1] .add( nodes[i].laz );
      nodes[i].laz = 0;
    }
  }
}

Node get(int l,int r) {
  push(l),push(r-1);
  Node ans = {inf,0,-1};
  for(l += MAXN,r +=MAXN; l<r ; l >>= 1,r >>= 1) {
    if(l & 1) ans.Min(nodes[l++]);
    if(r & 1) ans.Min(nodes[--r]);
  }
  return ans;
}

void add_seg(int l,int r,int d) {
  int rr = r,ll = l;
  for(l += MAXN,r += MAXN; l < r; l >>=1, r >>= 1) {
    if( l & 1 ) nodes[l++].add(-d);
    if( r & 1 ) nodes[--r].add(-d);
  }
  build(ll,ll+1),build(rr-1,rr);
}

int main() {
  ios :: sync_with_stdio(false);
  cin.tie(NULL),cin.tie(NULL);
  int n,m; cin >> n >> m;
  for(int i = 0;i<n;i++) cin >> arr[i];
  {
    int I = 0;
    for(int i = 1;i<6;i++)
      for(int j = 0;j<(1<<i);j++,I++) 
        for(int k = 0,x = 1;k<i;k++,x *= 10) luckies[I] += x * ( (j>>k)&1 ? 7 : 4 );
  }
  for(int i = 0;i<n;i++) {
    int pos = 1 + i + MAXN;
    nodes[pos] = Node(*lower_bound(luckies,luckies+62,arr[i]) - arr[i],1,i+1);
    val[i+1] = lower_bound(luckies,luckies+62,arr[i]) -luckies ;
  }
  build(1,n+1);
  while(m--) {
    string t;int x;int y;
    cin >> t >> x >> y;
    if(t[0] == 'a') {
      int z ;cin >> z;
      add_seg(x,y+1,z);
      Node tmp;
      while( (tmp = get(x,y+1)).mn < 0 ) {
        int i = tmp.pos;
//        cout << i << " ";
        push(i);
//        cout << nodes[i + MAXN].mn << " " << luckies[val[i]] << " " << luckies[val[i] + 1]<< "  --  ";
        nodes[i + MAXN].mn += -luckies[val[i]] + luckies[++val[i]];
        build(i,i+1);
      }
//      cout << endl;
    } else {
      Node tmp = get(x,y+1);
      if( tmp.mn > 0 ) cout << 0 << endl;
      else cout << tmp.cnt << endl;
    }
  }
  return 0;
}
