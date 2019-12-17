#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100 + 10 + 1;
bool mark[MaxN];
vector<int> tree[MaxN];
vector<int> lp;
int deg[MaxN];

pair<int, int> lp_dfs(int v,int par) {
  pair<int, int> ret = {0, v};
  for(auto u : tree[v])
    if(u != par) 
    {
      pair<int, int> w = lp_dfs(u, v);
      ret = max(ret, {w.first + 1, w.second});
    }
  return ret;
}

bool fill_dfs(int v, int par, int other) {
  if(v == other) {
    lp.push_back(v);
    return true;
  }
  for(auto u : tree[v])
    if(u != par && fill_dfs(u, v, other))
    {
      lp.push_back(v);
      return true;
    }
  return false;
}

void get_longest_path() {
  pair<int, int> tt = lp_dfs(1, 0);
  pair<int, int> ww = lp_dfs(tt.second, 0);
  lp.clear();
  fill_dfs(tt.second, 0, ww.second);
}

void deg_dfs(int v, int par, int h = 0) {
  deg[h] = max(deg[h], (int) tree[v].size());
  for(auto x : tree[v])
    if(x != par) deg_dfs(x, v, h + 1);
}

int main() {
  int n; scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int x,y;
    scanf("%d %d", &x, &y);
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  get_longest_path();
  unsigned long long len = (lp.size() + 1) / 2, leaves = 1e19L + 1ll;
  if(lp.size() % 2) {
    int cent = -1;
    unsigned long long lvs = 1;
    for(auto x : tree[cent = lp[lp.size() / 2]]) {
      deg_dfs(cent, x);
      deg_dfs(x, cent);
      for(int i = 0; i < MaxN; i++)
        if(deg[i] > 1) lvs *= deg[i] - 1;
      lvs <<= 1;
      leaves = min(leaves, lvs);
      lvs = 1;
      memset(deg, 0, sizeof deg);
    }
    deg_dfs(cent, 0);
    deg[0]++;
    for(int i = 0; i < MaxN; i++)
      if(deg[i] > 1) lvs *= deg[i] - 1;
    leaves = min(leaves, lvs);
  } else {
    int cent1 = lp[lp.size() / 2];
    int cent2 = lp[lp.size() / 2 - 1];
    deg_dfs(cent1, cent2);
    deg_dfs(cent2, cent1);
    unsigned long long lvs = 1;
    for(int i = 0; i < MaxN; i++)
      if(deg[i] > 1) lvs *= deg[i] - 1;
    lvs <<= 1;
    leaves = min(leaves, lvs);
  }
  printf("%llu %llu\n", len, leaves);
  return 0;
}
