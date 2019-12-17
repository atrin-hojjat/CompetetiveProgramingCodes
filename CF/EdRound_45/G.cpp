#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
vector<int> tree[MaxN];
map<int,long long> ans;
int val[MaxN];
map<int, int> gcds[MaxN];

void dfs_up(int v, int par) {
  gcds[v][val[v]]++;
  for(auto x : tree[v])
    if(x != par) {
      dfs_up(x, v);
      for(auto w : gcds[x])
        gcds[v][__gcd(w.first, val[v])] += w.second;
    }
  for(auto x : gcds[v]) ans[x.first] += x.second;
}

void dfs_down(int v, int par) {
  for(auto w : gcds[par]) {
    if(!w.second) continue;
    int ww = __gcd(val[v], w.first);
    ans[ww] += w.second;
    gcds[v][ww] += w.second;
  }
  gcds[v][val[v]]--;
  for(auto x : tree[v])
    if(x != par) {
      for(auto w : gcds[x])
      {
        if(!w.second) continue;
        int cc = __gcd(w.first, val[v]);
        gcds[v][cc] -= w.second;
      }
      dfs_down(x, v);
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> val[i + 1];
  for(int i = 1; i < n; i++) {
    int x,y; cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  dfs_up(1, 0);
  dfs_down(1, 0);
  for(auto w : ans)
    if(w.second) cout << w.first << " " << w.second << endl;
  return 0;
}
