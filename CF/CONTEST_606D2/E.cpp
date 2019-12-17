#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MaxN = 2e5 + 6.66;
int mark[MaxN];
int tx[MaxN];
vector<int> g[MaxN];
int A, B;

int dfs(int a, int b) {
  if(mark[a]) return 0;
  if(a == A) return 1;
  if(a == B) return 2;
  mark[a] = b;

  for(auto x : g[a])
    tx[b] |= dfs(x, b);
  return tx[b];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T; cin >> T;
  while(T--) {
    int n, m, a, b; cin >> n >> m >> A >> B;
    for(int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      g[v].push_back(u), g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
      if(!mark[i]) dfs(i, i);
    int _1 = 0, _2 = 0;
    for(int i = 1; i <= n; i++)
      if(tx[mark[i]] == 1) _1++;
      else if(tx[mark[i]] == 2)_2++;
    cout << 1ll * _1 * _2 << endl;
    for(int i = 0; i <= n; i++) g[i].clear(), mark[i] = false, tx[i] = 0;
  }
  return 0;
}
