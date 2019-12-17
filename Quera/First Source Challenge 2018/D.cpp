#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1000 + 100 + 10 + 1;
string arr[MaxN];
int cc[MaxN];
vector<int> dp[MaxN][MaxN];
vector<int> g[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, k; cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    cc[i] = arr[i].size();
  }
  for(int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
  }
  for(int i = 1; i <= k; i++) {
    for(int j = 0; j < n; j++)
      if(cc[j] == i) dp[j][i].push_back(-1);
      else if(cc[j] < i)
        for(auto u : g[j])
          if(dp[u][i - cc[j]].size()) dp[j][i].push_back(u);
  }
  bool exists = false;
  for(int i = 0; i < n; i++)
    exists |= (dp[i][k].size() > 0);
  if(!exists) {
    cout << -1 << endl;
    return 0;
  }
  string ans;
  set<pair<int, int>> vs;
  for(int i = 9; i > 0; --i) {
    for(int j = 0; j < n; j++)
      if(dp[j][k].size() && arr[j][0] == '0' + i) vs.insert({j, 0});
    if(vs.size()) {
      ans += '0' + i;
      break;
    }
  }
  for(int I = 1; I <= k; I++) {
    set<pair<int, int>> nvs;
    for(int i = 9; i > -1; --i) {
      for(auto x : vs) {
        pair<int, int> nw = {x.first, x.second + 1};
        if(nw.second == cc[x.first]) {
          for(auto u : dp[x.first][k - I + nw.second])
            if(~u && arr[u][0] == '0' + i)
              nvs.insert({u, 0});
        } else {
          if(arr[nw.first][nw.second] == '0' + i)
            nvs.insert(nw);
        }
      }
      if(nvs.size()) {
        ans += '0' + i;
        break;
      }
    }
    vs.swap(nvs);
  }
  cout << ans << endl;
  return 0;
}
