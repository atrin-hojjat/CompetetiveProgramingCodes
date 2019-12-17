#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
long long dis[MaxN];
long long up[MaxN], tmp[MaxN];
int par[MaxN], last;
vector<pair<int, int>> tree[MaxN];
int ans[MaxN];

long long dfs_up(int v, int p = -1) {
  for(auto x : tree[v]) 
    if(x.first != p)
      tmp[v] = max(tmp[v], dfs_up(x.first, v) + x.second);
  return tmp[v];
}

void dfs_down(int v, int p = -1) {
  dis[v] = max(up[v], tmp[v]);
  long long mx = up[v];
  for(auto x : tree[v])
  {
    if(x.first == p) continue;
    up[x.first] = mx + x.second;
    mx = max(mx, tmp[x.first] + x.second);
  }
  reverse(tree[v].begin(), tree[v].end());
  mx = 0;
  for(auto x : tree[v]) {
    if(x.first == p) continue;
    up[x.first] = max(up[x.first], mx + x.second);
    mx = max(tmp[x.first] + x.second, mx);
    dfs_down(x.first, v);
  }
}

void dfs_ans(int x, long long l, int p = -1) {
  ans[x]++;
  int L = 0, R = last;
  par[last++] = x;
  while(L < R) {
    int mid = L + (R - L) / 2;
    if(abs(dis[par[mid]] - dis[x]) > l) L = mid + 1;
    else R = mid;
  }
  if(L > 0) ans[par[L - 1]]--;
  for(auto u : tree[x])
    if(u.first != p) dfs_ans(u.first, l, x);
  last--;
}

int dfs_par(int v, int p = -1) {
  for(auto x : tree[v])
    if(x.first != p) ans[v] += dfs_par(x.first, v);
  return ans[v];
}

int main() {
  int n; scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int x, y, z; scanf("%d %d %d", &x, &y, &z);
    tree[x].push_back({y, z});
    tree[y].push_back({x, z});
  }
  dfs_up(1);
  dfs_down(1);
  int root = 1;
  for(int i = 2; i <= n; i++) 
    if(dis[i] < dis[root]) root = i;
  int Q; scanf("%d", &Q);
  while(Q--) {
    long long l; scanf("%lld", &l);
    memset(ans, 0, sizeof ans);
    last = 0;
    dfs_ans(root, l);
    dfs_par(root);
    int mx = 0;
    for(int i = 1; i <= n; i++)
      mx = max(mx, ans[i]);
    printf("%d\n", mx);
  }
  return 0;
}
