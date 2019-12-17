#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5e5 + 6.66;
const int inf = 1e9 + 7;
struct Segment {
  pair<int, int> seg[MaxN * 4];

  Segment() {
    for(int i = 0; i < 4 * MaxN; i++)
      seg[i] = {inf, -1};
  }

  pair<int, int> get(int id, int l, int r, int b, int e) {
    if(l >= r) return {inf, -1};
    if(l >= e || b >= r) return {inf, -1};
    if(b <= l && r <= e) return seg[id];
    int mid = l + (r - l) / 2;
    return min(get(id << 1, l, mid, b, e), get(id << 1 | 1, mid, r, b, e));
  }

  pair<int, int> get(int l, int r) {
    return get(1, 0, MaxN, l, r);
  }

  void alter(int id, int l, int r, int x, int val) {
    if(l >= r) return;
    if(l > x || r <= x) return ;
    if(r - l == 1) {
      seg[id] = {val, l};
      return ;
    }
    int mid = l + (r - l) / 2;
    alter(id << 1, l, mid, x, val);
    alter(id << 1 | 1, mid, r, x, val);
    seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
  }

  void alter(int x, int val) {
    alter(1, 0, MaxN, x, val);
  }
} seg;
int last[MaxN];
vector<pair<int, int>> queries[MaxN];
int ans[MaxN];
int arr[MaxN];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  int q; scanf("%d", &q);
  for(int i = 0; i < q; i++) {
    int l, r; scanf("%d %d", &l, &r);
    l--, r--;
    queries[r].push_back({i, l});
  }
  memset(last, -1, sizeof last);
  for(int i = 0; i < n; i++) {
    if(last[arr[i]] >= 0) {
      seg.alter(last[arr[i]], inf);
    }
    seg.alter(i, last[arr[i]]);
    last[arr[i]] = i;
    for(auto x : queries[i]) {
      pair<int, int> a = seg.get(x.second, i + 1);
//      cout << i << " " << x.first << " " << x.second << " " << a.first << " " << a.second << endl;
      if(a.first < x.second) ans[x.first] = arr[a.second];
    }
  }
  for(int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
