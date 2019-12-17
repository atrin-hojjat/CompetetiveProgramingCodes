#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 2e5 + 6.66;
int par[MaxN];
int mx[MaxN];
vector<int> g[MaxN];

int get_par(int v) {
  return par[v] ? par[v] = get_par(par[v]) : v;
}

void merge(int u, int v) {
  v = get_par(v);
  u = get_par(u);
  if(u == v) return ;
  if(v > u) swap(u, v);
  par[u] = v;
  mx[v] = max(mx[v], mx[u]);
}

void dfs(int v) {
  for(auto x : g[v])
    if(get_par(x) != get_par(v)) {merge(x, v); dfs(x);};
}

int main() {
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1; i <= n; i++) mx[i] = i;
  for(int i = 1; i <= n; i++) dfs(i);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int r = i;
    while(i < mx[get_par(r)]) {
      i++;
      if(get_par(i) == get_par(r)) continue;
      ans++;
      merge(i, r);
    }
  }
  cout << ans << endl;
  return 0;
}
