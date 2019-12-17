#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3e5 + 6.66;
struct Segment {
  int mn[MaxN * 4];
  int cnt[MaxN * 4];
  int lazy[MaxN * 4];

  Segment() {
    memset(mn, 0, sizeof mn);
    memset(cnt, 0, sizeof cnt);
    memset(lazy, 0, sizeof lazy);
    build(1, 0, MaxN);
  }

  void shift(int id, int l, int r, int val) {
    mn[id] += val;
    lazy[id] += val;
  }

  void push_down(int id, int l, int r) {
    int mid = l + (r - l) /2 ;
    if(lazy[id] == 0) return ;
    shift(id << 1, l, mid, lazy[id]);
    shift(id << 1 | 1, mid, r, lazy[id]);
    lazy[id] = 0;
  }

  void build(int id, int l, int r) {
    if(r - l == 1) {
      mn[id] = 0;
      cnt[id] = 1;
      return ;
    }
    int mid = l + (r - l) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid, r);
    mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
    if(mn[id << 1] == mn[id << 1 | 1]) {
      cnt[id] = cnt[id << 1] + cnt[id << 1 | 1];
    } else if(mn[id << 1] < mn[id << 1 | 1])
      cnt[id] = cnt[id << 1];
    else cnt[id] = cnt[id << 1 | 1];
  }

  void add(int id, int l, int r, int b, int e, int val) {
    if(l >= r) return ;
    if(l >= e || r <= b) return;
    if(l >= b && r <= e) 
    {
      shift(id, l, r, val);
      return ;
    }
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    add(id << 1, l, mid, b, e, val);
    add(id << 1 | 1, mid, r, b, e, val);
    mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
    if(mn[id << 1] == mn[id << 1 | 1]) {
      cnt[id] = cnt[id << 1] + cnt[id << 1 | 1];
    } else if(mn[id << 1] < mn[id << 1 | 1])
      cnt[id] = cnt[id << 1];
    else cnt[id] = cnt[id << 1 | 1];
  }

  int get(int id, int l, int r, int b, int e) {
    if(l >= r) return 0;
    if(l >= e || r <= b) return 0;
    if(l >= b && r <= e) return mn[id] == 0 ? cnt[id] : 0;
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    return get(id << 1, l, mid, b, e) + get(id << 1 | 1, mid, r, b, e);
  }

  int get(int l, int r) {
    return get(1, 0, MaxN, l, r);
  }

  void add(int l, int r, int val) {
    add(1, 0, MaxN, l, r, val);
  }
} seg;
int arr[MaxN];

int main() {
  int n; scanf("%d", &n);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    int a, b; scanf("%d %d", &a, &b);
    a--, b--;
    arr[a] = b;
  }
  stack<pair<int, int>> mn, mx;
  for(int i = n - 1; i > -1; --i) {
    pair<int, int> now = {arr[i], i + 1};
    int l = i + 1;
    while(mn.size() && mn.top() > now) {
      pair<int, int> c = mn.top();
      seg.add(l, c.second, - now.first + c.first);
      l = c.second;
      mn.pop();
    }
    mn.push({arr[i], l});
    l = i + 1;
    while(mx.size() && mx.top() < now) {
      pair<int, int> c = mx.top();
      seg.add(l, c.second, now.first - c.first);
      l = c.second;
      mx.pop();
    }
    mx.push({arr[i], l});
    seg.add(i + 1, n, -1);
    ans += seg.get(i, n);
  }
  printf("%lld\n", ans);
  return 0;
}
