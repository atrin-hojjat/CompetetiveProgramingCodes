#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
using namespace std;

const int MaxN = 2e5 + 6.66;
vector<int> tree[MaxN];
int color[MaxN];
int P[MaxN];
int par[MaxN];
int sz[MaxN];
int Sz[MaxN];
int SZ[MaxN];
int h[MaxN];
vector<int> arr;

int get_par(int v) {
  return par[v] ? par[v] = get_par(par[v]) : v;
}

void merge(int u, int v) {
  v = get_par(v), u = get_par(u);
  if(v == u) return ;
  if(h[v] < h[u]) swap(u, v);
  sz[u] += sz[v];
  par[v] = u;
}

void dfs(int v, int p = -1) {
  arr.push_back(-v);
  sz[v] = Sz[v] = 1, SZ[v] = 1;
  for(auto x : tree[v])
    if(x != p) {
      h[x] = h[v] + 1;
      dfs(x, v);
      if(color[x] == color[v]) merge(x, v);
      Sz[v] += Sz[x];
      SZ[v] += SZ[x];
    }
  arr.push_back(v);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  int cnt = 0;
  while(cin >> n){
    vector<int> qs[n + 1];
    for(int i = 1; i <= n; i++) cin >> color[i];
    for(int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      tree[v].push_back(u), tree[u].push_back(v);
    }
    dfs(1);
    vector<int> pedar;
    long long ans = 1ll * n * (n - 1) / 2 * n;
    for(auto x : arr) {
      if(get_par(abs(x)) != abs(x)) continue;
      if(x < 0) {
        if(pedar.size()) Sz[pedar.back()] = 0;
        pedar.push_back(-x);
        qs[color[-x]].push_back(-x);
        continue;
      }
      pedar.pop_back();
      qs[color[x]].pop_back();
      if(qs[color[x]].size()) {
        Sz[qs[color[x]].back()] += SZ[x];
      } else P[color[x]] += SZ[x];
      int s = 0;
      if(pedar.size()) s = SZ[x] - Sz[pedar.back()];
      ans -= 1ll * s * (s - 1) / 2;
    }
    for(int i = 1; i <= n; i++) {
      int x = SZ[1] - P[i];
      ans -= 1ll * x * (x - 1) / 2;
    }
    cout << "Case #" << ++cnt << ": " << ans << endl;
    arr.clear();
    for(int i = 0; i < n + 1; i++) tree[i].clear();
    for(int i = 0; i < n + 1; i++) sz[i] = SZ[i] = Sz[i] = par[i] = P[i] = color[i] = h[i] = 0;
  }
  return 0;
}
