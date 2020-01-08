#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

const int MaxN = 2e5 + 6.66;
int tri[3][MaxN];
vector<int> tree[MaxN];
map<pair<int, int>, set<int>> edges;

pair<int, int> get(int j, int i) {
  int a = tri[j][i];
  int b = tri[(j + 1) % 3][i];
  return {min(a, b), max(a, b)};
}

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n - 2; i++) {
      for(int j = 0; j < 3; j++)
        cin >> tri[j][i];
      for(int j = 0; j < 3; j++)
        for(auto u : edges[get(j, i)])
          tree[u].push_back(i), tree[i].push_back(u);
      for(auto j = 0; j < 3; j++)
        edges[get(j, i)].insert(i);
    }
    for(int i = 0; i < n - 2; i++) deg[i] = tree[i].size();
    queue<int> q;
    for(int i = 0; i < n - 2; i++)
      if(deg[i] == 1) q.push(i);
    while(q.size()) {
      int i = q.front(); q.pop();
      V.push_back(i);
      for(auto u : tree[i])
        if(--deg[u] == 1) q.push(u);
    }

    for(auto u : V) cout << u + 1 << " "; cout << endl;
    for(int i = 0; i < n; i++) tree[i].clear();
    edges.clear();
  }
  return 0;
}
