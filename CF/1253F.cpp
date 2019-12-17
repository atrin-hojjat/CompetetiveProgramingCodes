#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 1e5 + 6.66;
const long long inf = 5e17 + 6.1;
const int Max = 22;
vector<pair<int, long long>> tree[MaxN];
vector<pair<int, int>> graph[MaxN];
int par[Max][MaxN];
long long Mx[Max][MaxN];
long long Dis[MaxN];
int Root[MaxN];
int Hei[MaxN];
bool mark[MaxN];
int last[MaxN];

int get_root(int u) {
  return Root[u] ? Root[u] = get_root(Root[u]) : u;
}

void dfs(int v = 1, int h = 0, int P = -1) {
  Hei[v] = h++;
  par[0][v] = P;
  for(auto [u, w] : tree[v])
    if(u != P) Mx[0][u] = w, dfs(u, h, v);
}

long long get(int u, int v) {
  if(Hei[u] > Hei[v]) swap(u, v);

  long long ans = 0;

  for(int i = Max - 1; i > -1; --i)
    if((Hei[v] - Hei[u]) & (1 << i)) ans = max(ans, Mx[i][v]), v = par[i][v];

  if(u == v) return ans;

  for(int i = Max - 1; i > -1; --i) 
    if((1 << i) <= Hei[u] && par[i][u] != par[i][v]) {
      ans = max(ans, max(Mx[i][u], Mx[i][v]));
      u = par[i][u];
      v = par[i][v];
    }
  return max(ans, max(Mx[0][u], Mx[0][v]));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, k, q; cin >> n >> m >> k >> q;
  for(int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  // Dijkstra Prim
  auto Compare = [] (int i, int j) {
    long long L1 = Dis[i];
    long long L2 = Dis[j];
    if(L1 == L2) return i < j;
    return L1 < L2;
  };
  set<int, decltype(Compare)> s(Compare);
  for(int i = 1; i <= k; i++) s.insert(i);
  for(int i = 1; i <= k; i++) last[i] = i;
  for(int i = k + 1; i <= n; i++) Dis[i] = inf;
  while(s.size()) {
    int i = *s.begin();
    s.erase(s.begin());
    if(mark[i]) continue;
    mark[i] = true;

    for(auto [u, w] : graph[i])
      if(!mark[u] && Dis[u] > Dis[i] + w) {
        s.erase(u);
        Dis[u] = Dis[i] + w;
        last[u] = last[i];
        s.insert(u);
      }
  }
  set<pair<long long, pair<int, int>>> S;
  for(int i = 1; i <= n; i++) 
    for(auto [u, w] : graph[i])
      if(last[u] != last[i]) S.insert({Dis[u] + Dis[i] + w, {last[u], last[i]}});
  for(auto [a, b] : S) {
    auto [x, y] = b;
    if(get_root(x) != get_root(y)) {
      Root[get_root(x)] = get_root(y);
      tree[x].push_back({y, a});
      tree[y].push_back({x, a});
    }
  }
  // LCA
  dfs();
  for(int i = 1; i < Max; i++)
    for(int j = 1; j <= k; j++) 
      if((1 << i) <= Hei[j]) {
        par[i][j] = par[i - 1][par[i - 1][j]];
        Mx[i][j] = max(Mx[i - 1][j], Mx[i - 1][par[i - 1][j]]);
      } else Mx[i][j] = Mx[i - 1][j], par[i][j] = 0;

  while(q--) {
    int a, b; cin >> a >> b;
    cout << get(a, b) << endl;
  }
  return 0;
}
