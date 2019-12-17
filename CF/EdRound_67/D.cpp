#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MaxN = 3e5 + 6.66;
int a[MaxN], b[MaxN], A[MaxN];
vector<queue<int>> qs;
int seg[MaxN * 4];

void build(int id, int l, int r) {
  if(l >= r) return ;
  if(l + 1 == r) {
    seg[id] = A[l];
    return ;
  }
  int mid = l + (r - l) / 2;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid, r);
  seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

void alter(int id, int l, int r, int x, int v) {
  if(l >= r) return ;
  if(l > x || r <= x) return ;
  if(l + 1 == r) {
    seg[id] = v;
    return ;
  }
  int mid = l + (r - l) / 2;
  alter(id << 1, l, mid, x, v);
  alter(id << 1 | 1, mid, r, x, v);
  seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

int get(int id, int l, int r, int b, int e) {
  if(l >= r) return 1e9 + 7;
  if(l >= e || r <= b) return 1e9 + 7;
  if(l >= b && r <= e) return seg[id];
  int mid = l + (r - l) / 2;
  return min(get(id << 1, l, mid, b, e), get(id << 1 | 1, mid, r, b, e));
}

int main() {
  memset(seg, 63, sizeof seg);
  memset(A, 63, sizeof A);
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    qs.resize(n + 1);
    for(int i = 0; i < n; i++) qs[a[i]].push(i); 
    for(int i = 1; i <= n; i++) if(qs[i].size()) A[i] = qs[i].front(); else A[i] = 1e9 + 7;
    build(1, 0, n + 1);
    bool ok = true;
    for(int i = 0; i < n; i++) {
      if(qs[b[i]].size() == 0) {
        ok = false; break; }
      int t = qs[b[i]].front(); qs[b[i]].pop();
      int C = get(1, 0, n + 1, 1, b[i]);
      if(t > C) {
        ok = false;
        break;
      }
      if(qs[b[i]].size()) alter(1, 0, n + 1, b[i], qs[b[i]].front());
      else alter(1, 0, n + 1, b[i], 1e9 + 7);
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    for(int i = 0; i <= n; i++) {
      while(qs[i].size()) qs[i].pop(); A[i] = 1e9 + 7; }
  }
  return 0;
}
