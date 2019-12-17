#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
const int Max = 1<<18;
const long long inf = 3e15 + 6.66;
int arr[MaxN];
struct Bit {
  long long bit[Max];

  Bit() {
    memset(bit, 0, sizeof bit);
  }

  void add(int x, int y) {
    while(x < Max)
      bit[x] += y, x += x & -x;
  }

  long long get(int x) {
    long long ans = 0;
    for(; x; x ^= x & -x) ans += bit[x];
    return ans;
  }
} bit;
struct Segment {
  int n, h;
  pair<long long, int> mn[MaxN * 2];
  long long laz[MaxN];

  Segment() {
    memset(laz, 0, sizeof laz);
  }

  void build(int nn, int*arr) {
    n = nn;
    long long par_sum = 0;
    for(int i = 0; i < MaxN * 2; i++) mn[i] = {inf, -1};
    for(int i = 0; i < nn; i++)
    {
      mn[n + i] = {par_sum - arr[i], i};
      par_sum += arr[i];
    }
    for(int i = n - 1; i > 0; --i)
      mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
    h = sizeof(int) * 8 - __builtin_clz(n);
  }

  void apply(int pos, int val) {
    mn[pos].first += val;
    if(pos < n) laz[pos] += val;
  }

  void push_down(int l) {
    for(int s = h; s > 0; --s)
    {
      int now = l >> s;
      if(laz[now] != 0) {
        apply(now << 1, laz[now]);
        apply(now << 1 | 1, laz[now]);
        laz[now] = 0;
      }
    }
  }

  void build_up(int pos) {
    for(; pos > 1;) 
    {
      pos >>= 1;
      mn[pos] = min(mn[pos << 1], mn[pos << 1 | 1]);
      mn[pos].first += laz[pos];
    }
  }

  void alter_single(int x, int val) {
    x += n;
    push_down(x);
    apply(x, val);
    for(; x > 1; x >>= 1) mn[x >> 1] = min(mn[x], mn[x ^ 1]);
  }

  void alter(int l, int r, int val) {
    l += n, r += n;
    int l0 = l, r0 = r;
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) apply(l++, val);
      if(r & 1) apply(--r, val);
    }
    build_up(l0);
    build_up(r0 - 1);
  }

  pair<long long, int> get(int l, int r) {
    l += n, r += n;
    push_down(l), push_down(r - 1);
    pair<long long, int> ans = {inf, -1};
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) ans = min(ans, mn[l++]);
      if(r & 1) ans = min(ans, mn[--r]);
    }
    return ans;
  }

  void change(int x, int dif_val) {
    alter_single(x, -dif_val);
    if(x + 1 < n) alter(x + 1, n, dif_val);
  }
} seg;

int backtrack(int l, int r) {
  if(l >= r) return -1;
  pair<long long, int> cc = seg.get(l, r);
  if(cc.first < 0) {
    int w = -1;
    if(cc.second - l < r - cc.second - 1){
      if(~(w = backtrack(l, cc.second))) return w;
      return backtrack(cc.second + 1, r);
    } else {
      if(~(w = backtrack(cc.second + 1, r))) return w;
      return backtrack(l, cc.second);
    }
  } else if(cc.first == 0) return cc.second;
  else return -1;
}

int main() {
  srand(time(0));
  int n, q; scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  seg.build(n, &arr[0]);
  while(q--) {
    int i, j; scanf("%d %d", &i, &j);
    i--;
    seg.change(i, j - arr[i]);
    arr[i] = j;
    int ans = backtrack(0, n);
    if(ans > -1) ans++;
    printf("%d\n", ans);
  }
  return 0;
}
