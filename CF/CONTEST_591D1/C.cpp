#include <iostream>
#include <set>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxN = 5e5 + 6.66;
long long dp[MaxN], dp_n[MaxN];
vector<pair<int, int>> tree[MaxN];
int k;

void dfs(int v, int p = 0) {
  int n = 0;
  
  for(auto x : tree[v])
    if(x.first != p) dfs(x.first, v), n++;
  int II = 0;
  for(auto x : tree[v])
  {
    if(x.first == p) {
      tree[v].erase(tree[v].begin() + II);
      break;
    }
    II++;
  }

  long long tot = 0;

  for(auto x : tree[v]) 
    if(x.first != p) {
      tot += dp[x.first];
    }
  sort(tree[v].begin(), tree[v].end(), [](pair<int, int> a, pair<int, int> b) {
        long long ad = dp_n[a.first] + a.second - dp[a.first];
        long long bd = dp_n[b.first] + b.second - dp[b.first];
        return ad > bd;
      });
  long long t1 = tot;
  auto x = tree[v].begin();
  int I = 0;
  auto get__ = [](pair<int, int> x) {
    return dp_n[x.first] + x.second - dp[x.first];
  };
  long long par = 0;
  while(I < k - 1 && x != tree[v].end()) {
    I++;
    par += get__(*x);
    tot = max(tot, t1 + par);
    x++;
  }
  dp_n[v] = tot;
  if(x != tree[v].end()) {
    par += get__(*x);
    tot = max(tot, t1 + par);
    if(I < k - 1) dp_n[v] = max(dp_n[v], tot);
  }
  dp[v] = tot;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int Q; cin >> Q;
  while(Q--) {
    int n; cin >> n >> k;
    for(int i = 1; i < n; i++) {
      int u, v, w; cin >> u >> v >> w;
      tree[v].push_back({u, w});
      tree[u].push_back({v, w});
    }
    dfs(1, 0);
    cout << max(dp[1], dp_n[1]) << endl;
    for(int i = 0; i <= n; i++) tree[i].clear();
  }
  return 0;
}
