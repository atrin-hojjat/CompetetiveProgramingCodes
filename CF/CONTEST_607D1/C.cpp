#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 2e5 + 6.66;
int sz[MaxN];
vector<pair<int, int>> tree[MaxN];
long long dp[MaxN];

void dfs1(int u, int par = -1) {
  sz[u] = 1;
  for(auto [v, w] : tree[u]) 
    if(v != par) dfs1(v, u), sz[u] += sz[v];

  for(auto [v, w] : tree[u]) {
    if(v == par) continue;
    if(sz[v] % 2) {
      dp[u] = dp[u] + w + dp[v];
    } else dp[u] += dp[v];
  }
}

int get_centriod(int v, int tot, int par = -1) {
  for(auto [u, w] : tree[v])
    if(u != par && sz[u] > tot / 2) return get_centriod(u, tot, v);
  return v;
}

long long dfs2(int v, int par = -1) {
  sz[v] = 1;
  long long ans = 0;
  for(auto [u, w] : tree[v])
    if(u != par) {
      ans += dfs2(u, v);
      sz[v] += sz[u];
      ans += 1ll * w * sz[u];
    }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    for(int i = 1; i < 2 * n; i++)
    {
      int a, b, c; cin >> a >> b >> c;
      tree[a].push_back({b, c});
      tree[b].push_back({a, c});
    }
    dfs1(1);
    long long G = dp[1];
    int cent = get_centriod(1, sz[1]);
    for(int i = 0; i <= 2 * n; i++) sz[i] = 0;
    long long B = dfs2(cent);
    cout << G << " " << B << endl;
    for(int i = 0; i <= 2 * n; i++) {
      tree[i].clear();
      dp[i] = dp[i] = 0;
      sz[i] = 0;
    }
  }
  return 0;
}
