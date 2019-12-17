#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MaxN = 2e5 + 6.66;

struct Segment {
  long long seg[(int) (2e5 + 6.66) * 4];
  long long laz[(int) (2e5 + 6.66) * 4];
  int upd[(int) (2e5 + 6.66) * 4];

  Segment() {
    memset(seg, 0, sizeof seg);
    memset(laz, 0, sizeof laz);
    memset(upd, 0, sizeof upd);
  }

  void push(int id, int l, int r, int x) {
    seg[id] = 1ll * (r - l) * x;
    laz[id] = x;
    upd[id] = true;
  }

  void push_down(int id, int l, int r) {
    if(!upd[id]) return ;
    int mid = l + (r - l) / 2;
    push(id << 1, l, mid, laz[id]);
    push(id << 1 | 1, mid, r, laz[id]);
    upd[id] = 0;
    laz[id] = 0;
  }

  void inc(int id, int l, int r, int x, int val) {
    if(l >= r) return ;
    if(l > x || r <= x) return;
    if(l + 1 == r) {
      seg[id] += val;
      return;
    }
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    inc(id << 1, l, mid, x, val);
    inc(id << 1 | 1, mid, r, x, val);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
  }

  void set(int id, int l, int r, int b, int e, long long x) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      push(id, l, r, x);
      return ;
    }
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    set(id << 1, l, mid, b, e, x);
    set(id << 1 | 1, mid, r, b, e, x);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
  }

  int get(int id, int l, int r, int x) {
    if(l >= r) return -1;
    if(l > x || r <= x) return -1;
    if(l + 1 == r) return seg[id];
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    if(x < mid) return get(id << 1, l, mid, x);
    return get(id << 1 | 1, mid, r, x);
  }

  pair<int, int> binary(int id, int l, int r, int b, int e, int x) {
    if(l >= r) return {-1, x};
    if(l >= e || r <= b) return {-1, x};
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    if(l >= b && r <= e) {
      if(seg[id] <= x) return {r, x - seg[id]};
      if(l + 1 == r) return {l, x};
      if(seg[id << 1] > x) return binary(id << 1, l, mid, b, e, x);
      else return binary(id << 1 | 1, mid, r, b, e, x - seg[id << 1]);
    }
    auto T = binary(id << 1, l, mid, b, e, x);
    int t = T.first;
    int s = T.second;
    if(t == mid || t < 0) return binary(id << 1 | 1, mid, r, b, e, s);
    return T;
  }

  int get(int i) {
    return get(1, 0, MaxN, i);
  }

  void add(int i, int j) {
    auto X = binary(1, 0, MaxN, i, MaxN, j);
    set(1, 0, MaxN, i, X.first, 0);
    if(X.first < MaxN) inc(1, 0, MaxN, X.first, -X.second);
  }
} seg;
int A[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, q; cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> A[i];
    seg.inc(1, 0, MaxN, i, A[i]);
  }
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int a, b; cin >> a >> b;
      a--;
      seg.add(a, b);
    } else {
      int x; cin >> x;
      x--;
      cout << A[x] - seg.get(x) << endl;
    }
  }
  return 0;
}
