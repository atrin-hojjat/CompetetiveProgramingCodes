#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
struct Segment {
  struct Node {
    int mn = 1e9 + 10;
    int cnt = 0;
    int lazy = 0;

    Node() {
      mn = 1e9 + 10;
      cnt = 0;
      lazy = 0;
    }

    Node(int mn, int cnt, int lazy) : mn(mn), cnt(cnt), lazy(lazy) {}

    void operator +=(int x) {
      lazy += x;
      mn += x;
    }

    Node operator+(Node B) {
      Node ret = Node();
      if(B.mn < mn) ret = B;
      else if(mn < B.mn) ret = *this;
      else ret = {mn, cnt + B.cnt, 0};
      ret.lazy = 0;
      return ret;
    }
  } seg[MaxN * 4];

  Segment() {
    build(1, 0, MaxN);
  }

  void build(int id, int l, int r) {
    if(l >= r) return ;
    if(r - l == 1) {
      seg[id] = {0, 1, 0};
      return;
    }
    int mid = l + (r - l) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid, r);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
  }

  void add(int id, int l, int r, int b, int e, int val) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      seg[id] += val;
      return;
    }
    int mid = l + (r - l) / 2;
    add(id << 1, l, mid, b, e, val);
    add(id << 1 | 1, mid, r, b, e, val);
    int lz = seg[id].lazy;
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
    seg[id] += lz;
  }

  Node get(int id, int l, int r, int b, int e) {
    if(l >= r) return Node();
    if(l >= e || r <= b) return Node();
    if(l >= b && r <= e) return seg[id];
    int mid = l + (r - l) / 2;
    Node ret = get(id << 1, l, mid, b, e) + get(id << 1 | 1, mid, r, b, e);
    ret += seg[id].lazy;
    return ret;
  }

  void add(int l, int r, int val) {
    add(1, 0, MaxN, l, r, val);
  }

  int get(int l, int r) {
    Node ret = get(1, 0, MaxN, l, r);
    if(ret.mn == 0) return ret.cnt;
    else return 0;
  }
} seg;
int st[MaxN], et[MaxN];
vector<int> tree[MaxN];
vector<int> ques[MaxN];
int ans[MaxN];
int now = 0;

void dfs1(int v = 1, int p = 0) {
  st[v] = now++;
  for(auto u : tree[v]) 
    if(u != p) dfs1(u, v);
  et[v] = now;
}

void dfs2(int v = 1, int p = 0) {
  if(ques[v].size() > 0) 
    seg.add(st[v], et[v], 1);
  for(auto x : ques[v])
    seg.add(st[x], et[x], 1);
  ans[v] = MaxN - seg.get(0, MaxN);
  if(seg.get(st[v], st[v] + 1) == 0) ans[v]--;
  for(auto u : tree[v])
    if(u != p) dfs2(u, v);
  for(auto x : ques[v])
    seg.add(st[x], et[x], -1);
  if(ques[v].size() > 0) 
    seg.add(st[v], et[v], -1);
}

int main() {
  int n, Q; scanf("%d %d", &n, &Q);
  for(int i = 1; i < n; i++) {
    int x, y; scanf("%d %d", &x, &y);
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  for(int i = 0; i < Q; i++) {
    int x, y; scanf("%d %d", &x, &y);
    ques[x].push_back(y);
    ques[y].push_back(x);
  }
  dfs1();
  dfs2();
  for(int i = 1; i <= n; i++)
    printf("%d%c", ans[i], " \n"[n == i]);
  return 0;
}
