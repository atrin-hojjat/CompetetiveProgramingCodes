#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3e5 + 6.66;

pair<int, int> operator+(pair<int, int>&a, pair<int, int>&b) {
  return {a.first + b.first, a.second + b.second};
}

struct Segment {
  struct Node {
    bool m2 = false;
    bool sw = false;
    long long lazy = 0;
    long long val = 0;
    pair<int, int> cnt;
    bool bf = false;

    Node() {
      m2 = false;
      sw = false;
      lazy = 0;
      val = 0;
      cnt = {0, 0};
    }

    Node(bool m2, bool sw, long long lazy, long long val, pair<int ,int> cnt) 
      : m2(m2), sw(sw), lazy(lazy), val(val), cnt(cnt) {}

    Node operator+(Node& b) {
      return {false, false, 0, b.val + val, cnt + b.cnt};
    }

    Node& operator+=(long long x) {
      if(x & 1)
        swap();
      lazy += x;
      val += 1ll * (cnt.first + cnt.second) * x;
      return *this;
    }

    void make_m2() {
      bf = (bf != sw);
      sw = false;
      m2 = true;
      lazy = 0;
      val = cnt.second;
    }

    void swap() {
      sw = (sw == false);
      ::swap(cnt.first, cnt.second);
    }
  } seg[MaxN * 4];

  Segment() {
    build(1, 0, MaxN);
  }

  void build(int id, int l, int r) {
    if(l >= r) return ;
    if(r - l == 1) {
      seg[id].cnt.first++;
      return ;
    }
    int mid = l + (r - l) / 2;
    build(id << 1, l, mid), build(id << 1 | 1, mid, r);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
  }

  void push_down(int id, int l, int r) {
    if(seg[id].m2) {
      if(seg[id].bf) {
        seg[id << 1].swap();
        seg[id << 1 | 1].swap();
        seg[id].bf = false;
      }
      seg[id << 1].make_m2();
      seg[id << 1 | 1].make_m2();
      seg[id].m2 = false;
    }
    if(seg[id].lazy) {
      seg[id << 1] += seg[id].lazy;
      seg[id << 1 | 1] += seg[id].lazy;
      seg[id].lazy = 0;
      seg[id].sw = false;
    }
  }

  void add(int id, int l, int r, int b, int e, int val) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      seg[id] += val;
      return ;
    }
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    add(id << 1, l, mid, b, e, val);
    add(id << 1 | 1, mid, r, b, e, val);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
  }

  void make_m2(int id, int l, int r, int b, int e) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      seg[id].make_m2();
      return ;
    }
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    make_m2(id << 1, l, mid, b, e);
    make_m2(id << 1 | 1, mid, r, b, e);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
  }

  long long get(int id, int l, int r, int b, int e) {
    if(l >= r) return 0;
    if(l >= e || r <= b) return 0;
    if(l >= b && r <= e) return seg[id].val;
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    return get(id << 1, l, mid, b, e) + get(id << 1 | 1, mid, r, b, e);
  }

  void add(int l, int r, int x) {
    add(1, 0, MaxN, l, r, x);
  }

  void make_m2(int l, int r) {
    make_m2(1, 0, MaxN, l, r);
  }

  long long get(int l, int r) {
    return get(1, 0, MaxN, l, r);
  }
} seg;

int main() {
  int n, Q; scanf("%d %d", &n, &Q);
  for(int i = 0; i < n; i++) {
    int d; scanf("%d", &d);
    seg.add(i, i + 1, d);
  }
  while(Q--) {
    int t, l, r; scanf("%d %d %d", &t, &l, &r);
    l--, r;
    if(t == 1) seg.make_m2(l, r);
    else if(t == 2) {
      int d; scanf("%d", &d);
      seg.add(l, r, d);
    } else 
      printf("%lld\n", seg.get(l, r));
  }
  return 0;
}
