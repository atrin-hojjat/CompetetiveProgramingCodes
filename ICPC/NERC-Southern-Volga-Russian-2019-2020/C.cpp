#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Segment {
  pair<long long, int> seg[(int) (1e6 + 6.66)];
  long long laz[(int) (1e6 + 6.66)];
  const int Max = 2e5 + 16.66;

  Segment() {
    for(int i = 0; i < Max; i++) seg[i] = {-3e17l, -1}, laz[i] = 0;
    build(1, 0, Max);
  }

  void build(int id, int l, int r) {
    if(l >= r) return ;
    if(l + 1 == r) {
      seg[id] = {0ll, l};
      laz[id] = 0;
      return ;
    }
    int mid = l + (r - l) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid, r);
    set_seg(id);
  }

  void set_seg(int id) {
    seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
  }

  void shift(int id, long long x) {
    laz[id] += x;
    seg[id].first += x;
  }

  void shift_down(int id) {
    if(!laz[id]) return ;
    shift(id << 1, laz[id]);
    shift(id << 1 | 1, laz[id]);
    laz[id] = 0;
    set_seg(id);
  }

  void add(int id, int l, int r, int b, int e, long long v) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      laz[id] += v;
      seg[id].first += v;
      return ;
    }
    shift_down(id);
    int mid = l + (r - l) / 2;
    add(id << 1, l, mid, b, e, v);
    add(id << 1 | 1, mid, r, b, e, v);
    set_seg(id);
  }

  pair<long long, int> get(int id, int l, int r, int b, int e) {
    if(l >= r) return {-3e16l, -1};
    if(l >= e || r <= b) return {-3e16l, -1};
    if(l >= b && r <= e) return seg[id];
    shift_down(id);
    int mid = l + (r - l) / 2;
    return max(get(id << 1, l, mid, b, e), get(id << 1 | 1, mid, r, b, e));
  }

  void add(int l, int r, long long val) {
    add(1, 0, Max, l, r, val);
  }

  pair<long long, int> get(int l, int r) {
    return get(1, 0, Max, l, r);
  }
} se;
const int MaxN = 2e5 + 6.66;
vector<pair<int, long long>> sts[MaxN];
vector<pair<int, int>> pjs;

int main() {
  int n;
  long long k; cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int l, r;
    long long v;
    cin >> l >> r >> v;
    l--, r--;
    sts[l].push_back({r, v});
    pjs.push_back({l, r});
  }
  pair<long long, pair<int, int>> mx = {0, {-1, -1}};
  for(int i = MaxN - 1; i > -1; --i) {
    for(auto x : sts[i])
      se.add(x.first, MaxN, x.second);
    se.add(i, MaxN, -k);
    pair<long long, int> xx = se.get(i, MaxN);
    mx = max(mx, {xx.first, {i, xx.second}});
  }
  if(mx.first == 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> s;
  for(int i = 0; i < pjs.size(); i++) {
    auto [l, r] = pjs[i];
    if(l >= mx.second.first && r <= mx.second.second) s.push_back(i + 1);
  }
  cout << mx.first << " " << 1 + mx.second.first << " " << 1 + mx.second.second << " " << s.size() << endl;
  for(auto x : s) cout << x << " "; cout << endl;
  return 0;
}
