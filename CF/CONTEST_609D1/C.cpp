#ifdef Atrin
#include <iostream>
#include <vector>
#include <map>
#include <set>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

const int MaxN = 2e5 + 6.66;

struct BIT {
  long long bit[MaxN];

  BIT() { memset(bit, 0, sizeof bit); }

  void add(int i, long long j) {
    while(i < MaxN) bit[i] += j, i += i & -i;
  }

  long long get(int i) {
    long long ans = 0;
    while(i) ans += bit[i], i ^= i & -i;
    return ans;
  }
} Inv;
struct Segment {
  int count[MaxN * 4];
  int add[MaxN * 4];
  long long sum[MaxN * 4];

  Segment() {
    memset(add, 0, sizeof add);
    memset(sum, 0, sizeof sum);
    make_count(1, 0, MaxN);
  }

  void make_count(int id, int l, int r) {
    if(l >= r) return ;
    if(l + 1 == r) {
      count[id] = 1;
      return ;
    }
    int mid = l + (r - l) / 2;
    make_count(id << 1, l, mid);
    make_count(id << 1 | 1, mid, r);
    count[id] = count[id << 1] + count[id << 1 | 1];
  }

  void push(int id, int val) {
    add[id] += val;
    sum[id] += 1ll * count[id] * val;
  }

  void push_down(int id) {
    push(id << 1, add[id]);
    push(id << 1 | 1, add[id]);
    add[id] = 0;
  }
  
  void _remove(int id, int l, int r, int v) {
    if(l >= r) return ;
    if(l + 1 == r) {
      count[id] = 0;
      sum[id] = 0;
      return ;
    }
    push_down(id);
    int mid = l + (r - l) / 2;
    if(v < mid) _remove(id << 1, l, mid, v);
    else _remove(id << 1 | 1, mid, r, v);
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
    count[id] = count[id << 1] + count[id << 1 | 1];
  }

  void remove(int i) {
    _remove(1, 0, MaxN, i);
  }

  void _add(int id, int l, int r, int b, int e, int val) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      add[id] += val;
      sum[id] += 1ll * count[id] * val;
      return ;
    }
    push_down(id);
    int mid = l + (r - l) / 2;
    _add(id << 1, l, mid, b, e, val);
    _add(id << 1 | 1, mid, r, b, e, val);
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
  }

  void Add(int l, int r, int val) {
    _add(1, 0, MaxN, l, r, val);
  }

  long long get(int id, int l, int r, int b, int e) {
    if(l >= r) return 0;
    if(l >= e || r <= b) return 0;
    if(l >= b && r <= e) return sum[id];
    push_down(id);
    int mid = l + (r - l) / 2;
    return get(id << 1, l, mid, b, e) + get(id << 1 | 1, mid, r, b, e);
  }

  long long get(int l, int r) { 
    if(l == r) return 0;
    return get(1, 0, MaxN, l, r); }
} Left, Right;
int arr[MaxN], rev[MaxN];
long long ans[MaxN], parans[MaxN];

int main() {
  int n; cin >> n;
  for(int i = 1; i <= n; i++) cin >> arr[i];
  for(int j = 1; j <= n; j++) rev[arr[j]] = j;
  for(int i = n; i > 0; --i) {
    parans[arr[i]] += Inv.get(arr[i]);
    Inv.add(arr[i], 1);
  }
  for(int i = 1; i < MaxN; i++) parans[i] += parans[i - 1];
  int L = rev[1], R = rev[1];
  Left.remove(rev[1]);
  Right.remove(rev[1]);
  Left.Add(rev[1] + 1, n + 1, 1);
  Right.Add(0, rev[1], 1);
  set<int> firsthalf, secondhalf;
  firsthalf.insert(rev[1]);
  for(int i = 2; i <= n; i++) {
    L = min(L, rev[i]);
    R = max(R, rev[i]);
    Left.remove(rev[i]);
    Right.remove(rev[i]);
    Left.Add(rev[i] + 1, n + 2, 1);
    Right.Add(0, rev[i], 1);
    if(secondhalf.size() && rev[i] < *secondhalf.begin()) firsthalf.insert(rev[i]);
    else secondhalf.insert(rev[i]);
    while(firsthalf.size() > secondhalf.size()) {
      secondhalf.insert(*firsthalf.rbegin());
      firsthalf.erase(--firsthalf.end());
    }
    while(secondhalf.size() > firsthalf.size() + 1) {
      firsthalf.insert(*secondhalf.begin());
      secondhalf.erase(secondhalf.begin());
    }
    int mid = *firsthalf.rbegin();
    ans[i] = Left.get(L, mid) + Right.get(mid, R);
    mid = *secondhalf.begin();
    ans[i] = min(ans[i], Left.get(L, mid) + Right.get(mid, R));
  }
  for(int i = 1; i <= n; i++) cout << ans[i] + parans[i] << " "; cout << endl;
  return 0;
}
