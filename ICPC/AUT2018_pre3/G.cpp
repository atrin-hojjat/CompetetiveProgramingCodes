#include <iostream>
#include <iomanip>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int Mxx = 1 << 20;
const int Max = 1 << 18;
const int inf = 1e9 + 7;

struct Segment {
  int mx[Mxx];
  int laz[Mxx];

  Segment() {
    clear();
  }
  void clear() {
    memset(mx, 0, sizeof mx);
    memset(laz, 0, sizeof laz);
  }
    
  void push(int id, int v) {
      laz[id] += v;
      mx[id] += v;
  }
  
  void push_down(int id) {
    if(!laz[id]) return ;
    push(id << 1, laz[id]);
    push(id << 1 | 1, laz[id]);
    laz[id] = 0;
  }

  void add(int id, int l, int r, int b, int e, int v) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      push(id, v);
      return ;
    }
    push_down(id);
    int mid = l + (r - l) / 2;
    add(id << 1, l, mid, b, e, v);
    add(id << 1 | 1, mid, r, b, e, v);
    mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
  }

  int get(int id, int l, int r, int b, int e) {
    if(l >= r) return -30000;
    if(l >= e || r <= b) return -30000;
    if(l >= b && r <= e) return mx[id];
    push_down(id);
    int mid = l + (r - l) / 2;
    return max(get(id << 1, l, mid, b, e), get(id << 1 | 1, mid, r, b, e));
  }
} seg;

vector<int> tree[3][MaxN];
int root[MaxN];
int l[MaxN], r[MaxN], par[MaxN];
int bpar[MaxN];
int arr[MaxN];
int now = 0;

void dfs(int v, int p, int rot, int type = 0) {
  if(type) par[v] = p;
  root[v] = rot;
  l[v] = now++;
  for(auto x : tree[1][v])
    if(x != p && !root[x]) dfs(x, v, rot, 1);
  r[v] = now;
  for(auto x : tree[2][v])
    if(x != p && !root[x]) dfs(x, v, rot);
  bpar[v] = now;
}

int main() {
  int cnt = 0, n, m, q;
  double Z = log(2);
  while(~scanf("%d%d%d", &n, &m, &q)) {
    for(int i = 1; i <= n ;i++) scanf("%d", arr + i);
    for(int i = 1; i <= n; i++) arr[i] = __builtin_ctz(arr[i]);
    for(int i = 0; i < m; i++) {
      int x, y, z;
      scanf("%d%d%d", &z, &y, &x);

      tree[z][x].push_back(y);
      tree[z][y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
      if(!root[i]) dfs(i, i, i);
    
    for(int i = 1; i <= n; i++)
    {
      seg.add(1, 0, Max, l[i] + 1, r[i], arr[i]);
      if(par[i]) seg.add(1, 0, Max, l[i], bpar[i], -arr[i]);
    }
    printf("Case #%d:\n", ++cnt);
    while(q--) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      c = __builtin_ctz(c);
      if(a == 1) {
        seg.add(1, 0, Max, l[b] + 1, r[b], -arr[b] + c);
        if(par[b]) seg.add(1, 0, Max, l[b], bpar[b], arr[b] - c);
        arr[b] = c;
      } else {
        int t = seg.get(1, 0, Max, l[b], l[b] + 1);
        int y = seg.get(1, 0, Max, l[root[b]], bpar[root[b]]);
        double z = c - t + y;
        printf("%.3f\n", Z * z);
      }
    }
    for(int i = 1; i < 3; i++)
      for(int j = 0; j <= n; j++) tree[i][j].clear();
    memset(par, 0, sizeof par);
    memset(root, 0, sizeof root);
    seg.clear();
    now = 0;
  }
  return 0;
}
