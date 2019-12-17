#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 1e5 + 6.66;
map<int, int> m;
map<int, vector<int>> g;
pair<int, int> eds[MaxN];

int other(int v, int e) {
  if(eds[e].first == v) return eds[e].second;
  return eds[e].first;
}

pair<int, int> dfs(int v) {
  m[v] = 2;
  pair<int, int> ret = {-1, -1};
  for(auto e : g[v])
    if(m[other(v, e)] < 2) {
      pair<int, int> t = dfs(other(v, e));
      if(t.first == -1) 
        ret = {e, other(v, e)};
      else ret = t;
    }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    m.clear();
    g.clear();
    int edc = 1;
    for(int i = 0; i < n; i++) {
      int x, y; cin >> x >> y;
      m[x] = m[y] = 1;
      g[x].push_back(edc);
      g[y].push_back(edc);
      eds[edc++] = {x, y};
    }
    vector<pair<int, int>> vec;
    for(auto [v, mark] : m) 
      if(mark < 2) vec.push_back(dfs(v));
    cout << vec.size() - 1 << endl;
    for(int i = 1; i < vec.size(); i++)
      cout << vec[i].first << " " << vec[i].second << " "<< vec[0].second << endl;
  }
  return 0;
}
