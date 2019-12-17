#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 1.5e5 + 6.66;
const int Max = 18;
const int Sqrt = 250;
const int mod = 998244353;
int h[MaxN];
int ans[MaxN], sval[MaxN];
int dp[MaxN];
int l[MaxN], r[MaxN];
int n, inv_n;
int now;
pair<int, int> eul[Max][MaxN * 2];
int Que[MaxN];
int L = 0, R = 0;
int UPD[MaxN];
int mark[MaxN];
vector<int> tree[MaxN];
vector<pair<int, int>> ques;
int sz[MaxN];

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * ans * base % mod;
  return ans;
}

void init_dfs(int u, int par = -1, int hei = 0) {
  h[u] = hei++;
//  lca[0][u] = par;
  sz[u] = 1;
  sort(tree[u].begin(), tree[u].end());
  l[u] = now;
  for(auto v : tree[u])
    if(v != par) eul[0][now++] = {-hei, v}, init_dfs(v, u, hei), sz[u] += sz[v];
//  eul[0][now++] = {{-hei, u}, 0};
  r[u] = now;
}

void init() {
  init_dfs(1);

  inv_n = _pow(n, mod - 2);

  for(int i = 1; i < Max; i++)
  {
    for(int j = 0; j < now; j++)
      if(j + (1 << i) <= now) eul[i][j] = max(eul[i - 1][j], eul[i - 1][j + (1 << (i - 1))]);
      else eul[i][j] = eul[i - 1][j];
  }

}
/*
int get_par(int v, int h) {
  if(h <= 0) return v;
  for(; h; v = lca[__builtin_ctz(h)][v], h ^= h & -h);
  return v;
}*/

int get_lca(int u, int v) {
  if(u == v) return sz[1];

  if(l[u] >= l[v] && r[u] <= r[v]) {
    int c = r[u] - l[v];
//    int s = log(c) / log(2);
    int s = 31 - __builtin_clz(c);
//    cout << u << " " << v << "    " << s << endl;
    return sz[1] - sz[max(eul[s][l[v]], eul[s][r[u] - (1 << s)]).second];
  }
  return sz[v];
/*  int t = get_par(u, h[u] - h[v] - 1);
  if(lca[0][t] == v) return sz[1] - sz[t];
  return sz[v];*/
}

void dfs_down(int u, int val, int par = -1) {
  int sum = 0;
  ans[u] += val;
  if(ans[u] >= mod) ans[u] -= mod;
  for(auto v : tree[u])
    if(v != par) (sum += dp[v]) %= mod;
  for(auto v : tree[u]) {
    if(v == par) continue;
    dfs_down(v, 1ll * (0ll + val + sum + 1ll * (sz[1] - sz[v]) * sval[u] % mod * inv_n % mod - dp[v] + mod) % mod, u);
  }
}

void dfs_up(int u, int par = -1) {
  dp[u] = 1ll * sz[u] * sval[u] % mod * inv_n % mod;
  for(auto v : tree[u])
    if(v != par) {
      dfs_up(v, u);
      dp[u] += dp[v];
      if(dp[u] >= mod) dp[u] -= mod;
      ans[u] += dp[v];
      if(ans[u] >= mod) ans[u] -= mod;
    }
}

void relax() {
//  for(auto [u, val] : ques)
  for(int i = L; i < R; i++)  
  {
    int u = Que[i];
    int val = UPD[u];
    UPD[u] = 0;
    mark[u] = false;
    sval[u] += val;
    if(sval[u] >= mod) sval[u] -= mod;
  }
  L = R;
  for(int i = 0; i < MaxN; i++) ans[i] = sval[i];
  dfs_up(1);
  dfs_down(1, 0);
  ques.clear();
}

int calc(int v) {
  int ret = ans[v];
  for(int i = L; i < R; i++) {
    int val = UPD[Que[i]];
    int u = Que[i];
    ret += 1ll * val * get_lca(v, u) % mod * inv_n % mod;

    if(ret >= mod) ret -= mod;
  }
  return ret;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int q; cin >> n >> q;
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  init();
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int x, y; cin >> x >> y;
      UPD[x] += y;
      if(UPD[x] >= mod) UPD[x] -= mod;
      if(!mark[x]) Que[R++] = x, mark[x] = true;
    } else {
      int x; cin >> x;
      cout << calc(x) << "\n";
    }

    if(R - L > Sqrt) relax();

  }
  return 0;
}

