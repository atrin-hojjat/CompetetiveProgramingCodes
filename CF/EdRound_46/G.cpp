#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3e5 + 6.66;
const int MaxLog = 20;
int up_ed[MaxN];
long long dp[MaxN];
long long dp_up[MaxN];
long long ret_dp[MaxN];
long long lca_sum[MaxLog][MaxN];
long long lca_rem[MaxLog][MaxN];
int lca[MaxLog][MaxN];
int arr[MaxN];
int h[MaxN];
vector<pair<int, int>> tree[MaxN];

long long dfs_up(int v, int par = 0, int up = 0, int hei = 0) {
  lca[0][v] = par;
  up_ed[v] = up;
  h[v] = hei;
  dp[v] = arr[v];
  for(auto x : tree[v])
    if(x.first != par)
      dp[v] += dfs_up(x.first, v, x.second, hei + 1);
  return ret_dp[v] = max(0LL, dp[v] - 2 * up);
}

void dfs_down(int v, int par = 0, long long up_val = 0) {
  dp_up[v] = up_val;
  long long suf_sum = arr[v] + up_val;
  for(auto u : tree[v])
    if(u.first != par) suf_sum += ret_dp[u.first];
  long long pre_sum = 0;
  for(auto u : tree[v]) {
    if(u.first == par) continue;
    suf_sum -= ret_dp[u.first];
    dfs_down(u.first, v, max(0LL, pre_sum + suf_sum - 2 * u.second));
    pre_sum += ret_dp[u.first];
  }
}

void init_lca(int n) {
  for(int i = 1; i <= n; i++) 
    lca_sum[0][i] = dp[i] - up_ed[i], lca_rem[0][i] = ret_dp[i];
  for(int i = 1; i < MaxLog; i++) 
    for(int j = 1; j <= n; j++) {
      lca[i][j] = lca[i - 1][lca[i - 1][j]];
      lca_sum[i][j] = lca_sum[i - 1][j] + lca_sum[i - 1][lca[i - 1][j]];
      lca_rem[i][j] = lca_rem[i - 1][j] + lca_rem[i - 1][lca[i - 1][j]];
    }
}

int get_par(int v, int x) {
  for(int i = 0; i < MaxLog; i++) 
    if(x & (1 << i)) v = lca[i][v];
  return v;
}

long long get(int u, int v) {
  long long ans = 0;
  if(h[v] > h[u]) swap(u, v);
  for(int i = MaxLog - 1; i > -1; --i)
    if(h[u] - h[v] >= (1 << i)) {
      ans += lca_sum[i][u] - lca_rem[i][u];
      u = lca[i][u];
    }
  if(u == v)
    return ans + dp[u] + dp_up[u];
  int v0 = v;
  for(int i = MaxLog - 1; i > -1; --i)
    if((1 << i) <= h[v] && lca[i][v] != lca[i][u]) {
      ans += lca_sum[i][u] + lca_sum[i][v] - lca_rem[i][u] - lca_rem[i][v];
      u = lca[i][u];
      v = lca[i][v];
    }
  ans += lca_sum[0][u] + lca_sum[0][v] - lca_rem[0][u] - lca_rem[0][v];
  int l = lca[0][v];
  return ans + dp[l] + dp_up[l];
}

void init(int n) {
  dfs_up(1);
  dfs_down(1);
  init_lca(n);
}

int main() {
  int n, q; scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) scanf("%d", arr + i);
  for(int rki = 1; rki < n; rki++) {
    int i, j, v; scanf("%d %d %d", &i, &j, &v);
    tree[i].push_back({j, v});
    tree[j].push_back({i, v});
  }
  init(n);
  while(q--) {
    int u, v; scanf("%d %d", &u, &v);
    printf("%lld\n", get(u, v));
  }
  return 0;
}
