#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5e5 + 6.66;
struct Segment {
  int seg[2][MaxN * 4];
  int lazy[MaxN * 4];

  Segment() {
    memset(seg, 0, sizeof seg);
    memset(lazy, 0, sizeof lazy);
  }

  void shift(int id, int l, int r) {
    lazy[id] = !lazy[id];
    swap(seg[1][id], seg[0][id]);
  }

  void push_down(int id, int l, int r) {
    if(lazy[id] == 0) return ;
    int mid = l + (r - l) / 2;
    shift(id << 1, l, mid);
    shift(id << 1 | 1, mid, r);
    lazy[id] = 0;
  }

  void alter(int id, int l, int r, int b, int e) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      shift(id, l, r);
      return ;
    }
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    alter(id << 1, l, mid, b, e);
    alter(id << 1 | 1, mid, r, b, e);
    seg[0][id] = seg[0][id << 1] + seg[0][id << 1 | 1];
    seg[1][id] = seg[1][id << 1] + seg[1][id << 1 | 1];
  }

  void add(int id, int l, int r, int x, int val) {
    if(l >= r) return ;
    if(l > x || r <= x) return ;
    if(r - l == 1) {
      seg[lazy[id]][id] += val;
      return ;
    }
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    if(mid > x) add(id << 1, l, mid, x, val);
    else add(id << 1 | 1, mid, r, x, val);
    seg[0][id] = seg[0][id << 1] + seg[0][id << 1 | 1];
    seg[1][id] = seg[1][id << 1] + seg[1][id << 1 | 1];
  }

  int get(int id, int l, int r, int b, int e) {
    if(l >= r) return 0;
    if(l >= e || r <= b) return 0;
    if(l >= b && r <= e) return seg[0][id];
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    return get(id << 1, l, mid, b, e) + get(id << 1 | 1, mid, r, b, e);
  }

  void alter(int l, int r = MaxN) {
    alter(1, 0, MaxN, l, r);
  }

  void add(int x, int val) {
    add(1, 0, MaxN, x, val);
  }

  int get(int l = 0, int r = MaxN) {
    return get(1, 0, MaxN, l, r);
  }
} seg[2];
pair<int, int> ques[MaxN];

int main() {
  int w, h, q; cin >> w >> h >> q;
  vector<int> poses[2];
  poses[0].push_back(w);
  poses[0].push_back(0);
  poses[1].push_back(h);
  poses[1].push_back(0);
  for(int i = 0; i < q; i++) {
    char ch; int p;
    cin >> ch >> p;
    ques[i] = {ch == 'H', p};
    poses[ch == 'H'].push_back(p);
  }
  sort(poses[0].begin(), poses[0].end());
  sort(poses[1].begin(), poses[1].end());
  seg[0].add(0, w);
  seg[1].add(0, h);
  set<pair<int, int>> se[2];
  se[0].insert({w, poses[0].size()});
  se[0].insert({0, 0});
  se[1].insert({h, poses[1].size()});
  se[1].insert({0, 0});
  for(int i = 0; i < q; i++) {
    int v = ques[i].first;
    int p = ques[i].second;
    int sp = lower_bound(poses[v].begin(), poses[v].end(), p) - poses[v].begin();
    auto x = se[v].lower_bound({p, sp});
    int val = x->first - p;
    x--;
    seg[v].add(x->second, -val);
    seg[v].add(sp, val);
    se[v].insert(x, {p, sp});
    seg[v].alter(sp);
    {
      int a1 = seg[0].get();
      int a2 = w - a1;
      int b1 = seg[1].get();
      int b2 = h - b1;
      long long ans = 1ll * max(a2, a1) * max(b2, b1) + 1ll * min(a1, a2) * min(b1, b2);
      cout << ans << endl;
    }
  }
  return 0;
}
