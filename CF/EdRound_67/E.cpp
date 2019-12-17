#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 2e5 + 6.66;
long long dp_down[MaxN];
long long dp[MaxN];
int cnt[MaxN];
vector<int> tree[MaxN];
int n;

int dfs_cnt(int v, int p = -1) {
  cnt[v] = 1;
  for(auto x : tree[v])
    if(x != p) cnt[v] += dfs_cnt(x, v);
  return cnt[v];
}

long long dfs_down(int v, int p = -1) {
  dp_down[v] = cnt[v];
  for(auto x : tree[v])
    if(x != p) dp_down[v] += dfs_down(x, v);
  return dp_down[v];
}

void dfs_up(int v, int p = -1, long long val = 0) {
  dp[v] = dp_down[v] + n - cnt[v] + val;
  for(auto x : tree[v]) {
    if(x == p) continue;
    long long Val = n - cnt[x] + dp_down[v] - cnt[v] - dp_down[x] + val;
    dfs_up(x, v, Val);
  }
}

int main() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    tree[v].push_back(u);
    tree[u].push_back(v);
  }
  dfs_cnt(1);
  dfs_down(1);
  dfs_up(1);
  long long ans = 0;
  for(int i = 0; i < n; i++) ans = max(ans, dp[i + 1]);
  cout << ans << endl;
  return 0;
}
