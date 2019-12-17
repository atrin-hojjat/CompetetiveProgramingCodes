#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int MaxN = 1e5 + 6.66;
int par[MaxN];
bool mark[MaxN];
map<int, bool> g[MaxN];
set<int> unmatched;

int get_par(int v) {
  return par[v] == 0 ? v : par[v] = get_par(par[v]);
}

void merge(int v, int u) {
  par[u] = v;
}

void dfs(int v) {
  mark[v] = true;
  vector<int> T;
  for(auto x : unmatched) 
    if(g[v].count(x) == 0) T.push_back(x);
  for(auto x : T) unmatched.erase(x);
  for(auto x : T) merge(v, x), dfs(x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    if(x > y) swap(x, y);
    g[x][y] = true;
    g[y][x] = true;
  }
  int cnt = 0;
  for(int i = 2; i < n + 1; i++)
    unmatched.insert(i);
  for(int i = 1; i < 1 + n; i++)
    if(!mark[i]) dfs(i), cnt++;
  cout << cnt  - 1<< endl;
  return 0;
}
