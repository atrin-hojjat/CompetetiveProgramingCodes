#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MaxN = 2000 + 200 + 20 + 2;
vector<int> tree[MaxN];
int num[MaxN];
int C[MaxN];
vector<pair<int, int>> S[MaxN];

void dfs(int v) {
  if(tree[v].empty()) {
    if(C[v] != 0) {
      cout << "NO" << endl;
      exit(0);
    }
    num[v] = 1;
    S[v].push_back({1, v});
    return ;
  }
  for(auto u : tree[v]) dfs(u);
  int cnt = 0;
  if(C[v] == cnt) {
    S[v].push_back({num[v] = ++cnt, v});
  }
  for(auto u : tree[v]) {
    for(auto t : S[u]) {
      S[v].push_back({cnt + t.first, t.second});
      if(cnt + t.first == C[v]) {
        cnt++;
        num[v] = cnt + t.first;
        S[v].push_back({num[v], v});
      }
    }
    cnt += S[u].size();
    S[u].clear();
  }
  if(C[v] == cnt) {
    S[v].push_back({cnt + 1, v});
  } else if(C[v] > cnt) {
    cout << "NO" << endl;
    exit(0);
  }
  for(auto u : S[v]) num[u.second] = u.first;
}

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> C[i + 1];
    tree[x].push_back(i + 1);
  }
  dfs(0);
  cout << "YES" << endl;
  for(int i = 0; i < n; i++)
    cout << num[i + 1] << " "; cout << endl;
  return 0;
}
