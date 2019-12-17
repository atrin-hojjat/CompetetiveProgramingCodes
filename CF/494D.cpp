#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const int LOGMAXN = 20;
const long long mod = 1e9 + 7;
vector<pair<int,long long>> tree[MAXN];
int par[MAXN];
long long upedge[MAXN];
int sz[MAXN];
int h[MAXN];
int lca[LOGMAXN][MAXN];
long long sum[LOGMAXN][MAXN];
long long down[MAXN];
long long down2[MAXN];
long long up[MAXN];
long long up2[MAXN];
long long tot[MAXN];

void lca_init_dfs(int v = 1, int p = 0, int hei = 0, int wei = 0) {
  par[v] = p;
  h[v] = hei;
  upedge[v] = wei;
  for(auto x : tree[v])
    if(x.first != p)
      lca_init_dfs(x.first, v, hei + 1, x.second);
}

void init_lca(int n) {
  lca_init_dfs();
  for(int i = 1; i <= n; i++)
    lca[0][i] = par[i],sum[0][i] = upedge[i];
  for(int i = 1; i < LOGMAXN; i++)
    for(int j = 1; j <= n; j++)
      lca[i][j] = lca[i - 1][lca[i - 1][j]],
      sum[i][j] = sum[i - 1][j] + sum[i - 1][lca[i - 1][j]];
}

int get_par(int v,int x) {
  for(; x; x ^= x & -x)
    v = lca[__builtin_ctz(x)][v];
  return v;
}

bool is_anc(int v, int u) {
  if(h[v] > h[u]) return false;
  return get_par(u, h[u] - h[v]) == v;
}

int get_lca(int v, int u) {
  if(h[v] > h[u]) swap(u,v);
  u = get_par(u, h[u] - h[v]);
  if(u == v) return v;
  for(int i = LOGMAXN - 1; i > -1; i--)
    if((1 << i) <= h[v] && lca[i][v] != lca[i][u])
      u = lca[i][u], v = lca[i][v];
  return lca[0][u];
}

long long get_path_par(int v, int p) {
  long long ans = 0;
  for(int i = LOGMAXN - 1; i > -1; i--)
    if(h[v] - (1 << i) >= h[p])
      (ans += sum[i][v]) %= mod, v = lca[i][v];
  return ans;
}

long long get_path(int v,int u) {
  int lc = get_lca(u, v);
  return (get_path_par(u, lc) + get_path_par(v, lc)) % mod;
}

long long pow2_sum(long long sw2, long long sw, long long x, long long s) {
  sw2 %= mod, sw %= mod, x %= mod, s %= mod;
  if(sw2 < 0) sw2 += mod;
  if(sw < 0) sw += mod;
  if(x < 0) x += mod;
  return (sw2 + 2LL * x * sw % mod + 1LL * x * x % mod * s % mod) % mod;
}

void dfs_up(int v = 1, int p = 0) {
  sz[v] = 1;

  for(auto x : tree[v])
    if(x.first != p)
    {
      dfs_up(x.first, v);
      sz[v] += sz[x.first];
      (down[v] += down[x.first] + x.second * sz[x.first]) %= mod;
      (down2[v] += pow2_sum(down2[x.first], down[x.first], x.second, sz[x.first])) %= mod;
    }
}

void dfs_down(int v = 1, int p = 0, long long upp = 0, long long upp2 = 0) {
  upp %= mod, upp2 %= mod;
  up[v] = upp;
  up2[v] = upp2;
  tot[v] = (up2[v] + down2[v]) % mod;

  for(auto x : tree[v])
    if(x.first != p)
    {
      long long ss = upp + down[v] - down[x.first] + 2LL * mod
        + 1LL * (sz[1] - 2 * sz[x.first]) * x.second % mod;
      ss %= mod;
      long long ss2 = 
        pow2_sum(upp2 + down2[v] + mod -
            pow2_sum(down2[x.first], down[x.first], x.second, sz[x.first]),
          upp + down[v] - down[x.first] - sz[x.first] * x.second % mod + 2LL * mod, 
          x.second, (sz[1] - sz[x.first]));
      dfs_down(x.first, v, ss, ss2);
    }
}

void initiate(int&n) {
  scanf("%d", &n);
  for(int i = 1; i<n; i++) {
    int x,y;
    long long z; scanf("%d %d %lld", &x, &y, &z);
    tree[x].push_back({y,z});
    tree[y].push_back({x,z});
  }
  init_lca(n);
  dfs_up();
  dfs_down();
}

int main() {
  int n;
  initiate(n);
  int q; scanf("%d", &q);
  while(q--) {
    int u,v; scanf("%d %d", &u, &v);
    long long ans = 0;
    if(u == v) ans = (down2[v] - up2[v] + mod) % mod;
    else if(is_anc(v, u)) {
      long long xx = pow2_sum(up2[v], up[v], get_path_par(u, v), sz[1] - sz[v]);
      (ans = tot[u] - 2LL * xx + 2LL * mod) %= mod;
    } else {
      long long x1 = pow2_sum(down2[v], down[v], get_path(u, v), sz[v]);
      (ans = 2LL * x1 - tot[u] + 2LL * mod) %= mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
