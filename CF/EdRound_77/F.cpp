#include <vector>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

const int MaxN = (1 << 17);
const int mod = 1e9 + 7;

struct Segment {
  int seg[(1 << 18)];
  int laz[1 << 18];

  Segment() {
    memset(seg, 0, sizeof seg);
    memset(laz, 0, sizeof laz);
  }
  inline void push(int id, int l, int r, int val) {
    (laz[id] += val);
    if(laz[id] > mod) laz[id] -= mod;
    seg[id] = (seg[id] + 1ll * (r - l) * val % mod) % mod;
  }

  inline void push_down(int id, int l, int r) {
    int mid = l + (r - l) / 2;
    push(id << 1, l, mid, laz[id]);
    push(id << 1 | 1, mid, r, laz[id]);
    laz[id] = 0;
  }

  void add(int id, int l, int r, int b, int e, int x) {
    if(l >= r) return ;
    if(l >= e || r <= b) return ;
    if(l >= b && r <= e) {
      push(id, l, r, x);
      return ;
    }
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    add(id << 1, l, mid, b, e, x);
    add(id << 1 | 1, mid, r, b, e, x);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
    if(seg[id] >= mod) seg[id] -= mod;
  }

  int get(int id, int l, int r, int b, int e) {
    if(l >= r) return 0;
    if(l >= e || r <= b) return 0;
    if(l >= b && r <= e) return seg[id];
    push_down(id, l, r);
    int mid = l + (r - l) / 2;
    return (get(id << 1, l, mid, b, e) + get(id << 1 | 1, mid, r, b, e)) % mod;
  }

  void add(int l, int r, int x) {
    add(1, 0, MaxN, l, r, x);
  }

  int get(int l, int r) {
    return get(1, 0, MaxN, l, r);
  }
} seg, seg1;

int h[MaxN];
int l[MaxN], r[MaxN];
int sz[MaxN];
int mark[MaxN];
int tmp[MaxN];
vector<int> tree[MaxN];
int Ans = 0;

int _pow(int base, int exp) {
  if(tmp[base]) return tmp[base];
  int ans = 1;
  int B = base;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * ans * base % mod;
  return tmp[B] = ans;
}

void init_dfs(int v, int hei = 0, int p = -1) {
  h[v] = hei;
  sz[v] = 1;
  for(auto x : tree[v])
    if(!mark[x] && x != p) init_dfs(x, hei + 1, v), sz[v] += sz[x];
}

int get_centriod(int v, int tot2, int p) {
  for(auto x : tree[v])
    if(!mark[x] && x != p && sz[x] > tot2) return get_centriod(x, tot2, v);
  return v;
}

void calc_dfs(int v, int p = -1) {
  Ans += 1ll * (1ll * seg1.get(l[v], r[v]) * h[v] % mod +seg.get(l[v], r[v])) * _pow(r[v] - l[v], mod - 2) % mod;
  if(Ans > mod) Ans -= mod;
  for(auto x : tree[v])
    if(!mark[x] && x != p) calc_dfs(x, v);
}

void add_dfs(int v, int rem = 1, int p = -1) {
  int T = 1ll * (mod + rem) * _pow(r[v] - l[v], mod - 2) % mod;
  seg.add(l[v], r[v], 1ll * T * h[v] % mod);
  seg1.add(l[v], r[v], T);
  for(auto x : tree[v])
    if(!mark[x] && x != p) add_dfs(x, rem, v);
}

void decompose(int root) {
  root = get_centriod(root, sz[root] / 2, -1);
  init_dfs(root);
  for(auto x : tree[root]) {
    if(mark[x]) continue;
    calc_dfs(x, root);
    add_dfs(x, 1, root);
  }
  Ans += 1ll * seg.get(l[root], r[root]) * _pow(r[root] - l[root], mod - 2) % mod;
  if(Ans > mod) Ans -= mod;
  for(auto x : tree[root])
    if(!mark[x]) add_dfs(x, -1, root);
  mark[root] = true;
  for(auto x : tree[root])
    if(!mark[x]) decompose(x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  for(int i = 1; i <= n; i++) r[i]++;
  int t = 1;
  for(int i = 1; i <= n; i++)
    t = 1ll * t * (r[i] - l[i]) % mod;
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  init_dfs(1); decompose(1);
  cout << 1ll * Ans * t % mod << endl;
  return 0;
}
