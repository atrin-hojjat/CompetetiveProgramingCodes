#include <bits/stdc++.h>
using namespace std;

// Fractional Cascading
const int MaxN = 1e5 + 6.66;
struct Segment {
  int N;
  struct NodeEls {
    int val;
    int l = 0;
    int r = 0;

    NodeEls() {
    }

    NodeEls(int val, int l, int r) : val(val), l(l), r(r) {}

    bool operator<(const NodeEls&x) const {
      return val < x.val;
    }
  };
  struct Node {
    vector<NodeEls> els;

    Node() { }

    Node(int x) { els.reserve(1); els.push_back({x, -1, -1}); }

    Node operator+(Node&x) {
      Node ans;
      ans.merge(this->els, x.els);
      return ans;
    }

    void merge(vector<NodeEls>&l, vector<NodeEls>&r) {
      int a = 0, b = 0;
      els.clear();
      els.reserve(l.size() + r.size());
      while(a < l.size() || b < r.size()) {
        if(b == r.size() || (a < l.size() && l[a] < r[b])) {
          els.push_back(NodeEls(l[a].val, a, b));
          a++;
        } else {
          els.push_back(NodeEls(r[b].val, a, b));
          b++;
        }
      }
    }

    NodeEls operator[](int x) {
      if(x >= els.size()) return {(int) -2e9 - 7, MaxN, MaxN};
      return els[x];
    }
  } *seg;
  
  Segment(int N, int*arr) : N(N) {
    seg = new Node[N * 4];
    build(1, 0, N, arr);
  }

  void build(int id, int l, int r, int*arr) {
    if(l >= r) return ;
    if(r - l == 1) {
      seg[id] = arr[l];
      return;
    }
    int mid = l + (r - l) / 2;
    build(id << 1, l, mid, arr);
    build(id << 1 | 1, mid, r, arr);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
  }

  int Query(int id, int l, int r, int b, int e, int val, int pos = -1) {
    if(pos == -1) {
      pos = lower_bound(seg[id].els.begin(), seg[id].els.end(), NodeEls(val, 0, 0)) - seg[id].els.begin();
    }
    if(l >= e || r <= b) return 0;
    if(l >= b && r <= e)
      return min(pos, (int) seg[id].els.size()) + (val == seg[id][pos].val);
    int mid = l + (r - l) / 2;
    return Query(id << 1, l, mid, b, e, val, seg[id][pos].l)
      + Query(id << 1 | 1, mid, r, b, e, val, seg[id][pos].r);
  }

  int Query(int l, int r, int x) {
    return Query(1, 0, N, l, r, x);
  }
};
int arr[MaxN];

int main() {
  int n, Q; scanf("%d %d", &n, &Q);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  Segment seg(n, arr);
  for(; Q--; ) {
    int L, R, k; scanf("%d %d %d", &L, &R, &k);
    L--;
    int l = -1e9 - 7, r = 1e9 + 7;
    while(l < r) {
      int mid = l + (r - l) / 2;
      int ans = seg.Query(L, R, mid);
      if(ans < k) l = mid + 1;
      else r = mid;
    }
    printf("%d\n", l);
  }
  return 0;
}
