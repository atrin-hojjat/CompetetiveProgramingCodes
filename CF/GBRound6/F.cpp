#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MaxN = 5e5 + 6.66;
vector<int> tree[MaxN];
int ans[MaxN];
vector<pair<int, int>> children[MaxN];

int dfs_up(int v, int par = -1) {
  int Mx = 0;
  if(tree[v].size() == 1 && par != -1) {
    return 0;
  }
  for(auto u : tree[v])
    if(u != par) {
      int t = 0;
      children[v].push_back({t = dfs_up(u, v) + 1, u});
      Mx = max(Mx, t);
    }
//  sort(children[v].begin(), children[v].end());
  return Mx;
}

void dfs_down(int v, int par = -1, int up = 0) {
  if(tree[v].size() - (bool) ~par == 0) return ;
  if(up) children[v].push_back({up, par});
  sort(children[v].begin(), children[v].end());
  // Odds
  for(int i = 0; i < children[v].size() - 1; i++) {
    int t, Z;
    (Z = children[v][i].first);
    t = Z + min(Z + 1, children[v][i + 1].first);
    ans[t] = max(ans[t], (int) children[v].size() - i);
    ans[2 * Z] = max(ans[2 * Z], (int) children[v] - i);
  }
  // Update Children
  for(auto &u : children[v]) u.first++;
  // Go Down
  for(auto u : tree[v]) 
    if(u != par) {
      dfs_down(u, v, children[v].back().second == u ? children[v][children[v].size() - 2].first : children[v].back().first);
    }
}

int main() {
  int n; cin >> n;
  for(int i = 1; i < n; i++)
  {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs_up(1);
  dfs_down(1);
  for(int i = MaxN - 3; ~i; i--)
    ans[i] = max(ans[i], ans[i + 2]);
  for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
  return 0;
}
