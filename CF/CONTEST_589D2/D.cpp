#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 3e5 + 6.66;
int g[MaxN];
bool mark[MaxN];
int sz[5];
vector<int> graph[MaxN];

void dfs(int x) {
  mark[x] = true;
  for(auto u : graph[x])
    if(!mark[u]) dfs(u);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; i++)
  {
    int x, y; cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  if(m == 0) {
    cout << -1 << endl;
    return 0;
  }
  dfs(1);
  for(int i = 1; i < n + 1; i++)
    if(!mark[i]) {
      cout << -1 << endl;
      return 0;
    }
  for(auto x : graph[1]) g[x] = -1;
  int nx = 2;
  for(;nx < 1 + n && g[nx] != -1; nx++);
  if(nx <= n) {
    for(auto x : graph[nx]) if(g[x] == -1) g[x] = 1;
  } else {
    cout << -1 << endl;
    return 0;
  }
  for(int i = 1; i < n + 1; i++) {
    for(auto x : graph[i])
      if(g[x] == g[i]) {
        cout << -1 << endl;
        return 0;
      }
    sz[g[i] + 1]++;
  }
  for(int i = 1; i < n + 1; i++)
    if(sz[g[i] + 1] + graph[i].size() < n) {
      cout << -1 << endl;
      return 0;
    }
  for(int i = 0; i < 3; i++)
    if(sz[i] == 0) {cout << -1 << endl; return 0; }
  for(int i = 1; i < n + 1; i++) cout << g[i] + 2 << " "; cout << endl;
  return 0;
}
