#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5e5 + 6.66;
int root[MaxN];
int mark[MaxN];
int h[MaxN];
int d[MaxN];
bool ed_mark[MaxN];
vector<int> tree[MaxN];
vector<pair<int, int>> g[MaxN];

int get_root(int v) {
  return root[v] ? root[v] = get_root(root[v]) : v;
}

void merge(int v, int u) {
  root[get_root(v)] = get_root(u);
}

void dfs_ed(int v, int p) {
  h[v] = h[p] + 1;
  d[v] = h[v];
  mark[v] = true;
  for(auto u : g[v]) {
    if(mark[u.second] == 0) {
      dfs_ed(u.second, v);
      d[v] = min(d[u.second], d[v]);
      if(d[u.second] > h[v])
        ed_mark[u.first] = true;
    } else if(u.second != p)
      d[v] = min(d[v], h[u.second]);
  }
}

void dfs_merge(int v) {
  mark[v] = true;
  for(auto x : g[v])
    if(!ed_mark[x.first] && ! mark[x.second]) {
      merge(x.second, v);
      dfs_merge(x.second);
    } else if(!mark[x.second]) {
      dfs_merge(x.second);
    }
}

void edge_dfs(int v) {
  mark[v] = true;
  for(auto x : g[v]) {
    if(ed_mark[x.first]) {
      tree[get_root(v)].push_back(get_root(x.second));
      tree[get_root(x.second)].push_back(get_root(v));
    }
    if(!mark[x.second]) edge_dfs(x.second);
  }
}

pair<int, int> lp_dfs(int v, int p) {
  pair<int, int> ans = {0, v};
  mark[v] = true;
  for(auto x : tree[v])
    if(!mark[x])
      ans = max(ans, lp_dfs(x, v));
  ans.first++;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back({i, y});
    g[y].push_back({i, x});
  }
  dfs_ed(1,0);
  memset(mark, 0, sizeof mark);
  dfs_merge(1);
  memset(mark, 0, sizeof mark);
  edge_dfs(1);
  memset(mark, 0, sizeof mark);
  pair<int, int> ans = lp_dfs(get_root(1), -1);
  memset(mark, 0, sizeof mark);
  ans = lp_dfs(ans.second, -1);
  cout << ans.first - 1 << endl;
  return 0;
}
