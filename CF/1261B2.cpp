#include <iostream>
#include <set>
#include <map>
using namespace std;

const int MaxN = 2e5 + 6.66;
struct Query {
  int k;
  int pos;
  int i;

  bool operator<(const Query &a) const { return k == a.k ? i < a.i : k < a.k; }
} queries[MaxN];
pair<int, int> arr[MaxN];
int ans[MaxN];

struct Segment {
  int seg[(int) (2e5 + 6.66) * 4];
  int cnt[(int) (2e5 + 6.66) * 4];

  Segment() {
    memset(seg, 0, sizeof seg);
    memset(cnt, 0, sizeof cnt);
  }

  void set(int id, int l, int r, int x, int v) {
    if(l >= r) return ;
    if(l > x || r <= x) return ;
    if(l + 1 == r) {
      seg[id] = v;
      cnt[id] = v > 0;
      return ;
    }
    int mid = l + (r - l) / 2;
    set(id << 1, l, mid, x, v);
    set(id << 1 | 1, mid, r, x, v);
    cnt[id] = cnt[id << 1] + cnt[id << 1 | 1];
  }

  int get(int id, int l, int r, int x) {
    if(l >= r) return -1;
    if(x > cnt[id]) return -1;
    if(l + 1 == r) return seg[id];
    int mid = l + (r - l) / 2;
    if(cnt[id << 1] >= x) return get(id << 1, l, mid, x);
    return get(id << 1 | 1, mid, r, x - cnt[id << 1]);
  }

  void set(int x, int v) {
    set(1, 0, MaxN, x, v);
  }

  int get(int x) {
    return get(1, 0, MaxN, x);
  }
} seg;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = -i;
  }
  sort(arr, arr + n);
  reverse(arr, arr + n);
  int m; cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> queries[i].k >> queries[i].pos;
    queries[i].i = i;
  }
  sort(queries, queries + m);
  int I = 0;
  for(int i = 0; i < n; i++) {
    seg.set(-arr[i].second, arr[i].first);
    while(I < m & queries[I].k == i + 1) 
    {
      ans[queries[I].i] = seg.get(queries[I].pos), I++;
    }
  }
  for(int i = 0; i < m; i++) cout << ans[i] << endl;
  return 0;
}
