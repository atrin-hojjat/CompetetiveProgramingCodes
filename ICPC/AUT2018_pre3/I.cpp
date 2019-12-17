#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int MaxN = 1000 + 100 + 10 + 1;
vector<pair<int, int>> cac[MaxN];
int mark[MaxN * 3];
int M[MaxN];
int wei[MaxN];
vector<vector<int>> vs;
int I =1;

pair<int, int> dfs(int u) {
  pair<int, int> ret = {-1, 0};
  for(auto x : tree[v]) {
    if(M[x.first]) {
      mark[x.second] = I;
      ret = {x.first, I++};
    } else {
      auto c = dfs(x.first);
      if(c.first == u) {
        mark[x.second] = c.second;
      } else if(c.first > 0) ret = c;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; 
  while(cin >> n) {
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
      int u, v, w; cin >> u >> v >> w;
      wei[i] = w;
      cac[u].push_back({v, i});
      cac[v].push_back({u, i});
    }

    dfs(1);

    unsigned int sum = 0, span;
    vector<int> arr[I];
    int pts[I];
    for(int i = 0; i < m; i++) 
      arr[mark[i]].push_back(wei[i]);
    set<pair<int, int>> s;
    for(int i = 0; i < I; i++)
    {
      sort(arr[i].begin(), arr[i].end());
      pts[i] = arr[i].size() - 1;
      for(int j = 0; j < arr[i].size() - (i != 0); i++)
        sum += arr[i];
      s.insert({arr.back() - arr[arr.size() - 2], i});
    }

    span = sum;

    int i;
    for(i = 0; s.size() && i < k; i++) {
      pair<int, int> t = *s.begin();
      s.erase(s.begin());
      span += t.first;
      sum += s
      if(pts[s.second] <= 1) continue;
      s.insert({arr[s.second][--pts[s.second]] - arr[s.second][pts[s.second] - 1], vs.size()});
    }

    if(i < k) {
      cout << 0 << endl;;
    } else cout << sum << endl;

    for(int i = 0; i <= n; i++) cac[i].clear();
    for(int i = 0; i <= m; i++) mark[i] = 0;
  }
  return 0;
}
