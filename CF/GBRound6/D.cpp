#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

const int MaxN = 1e5 + 6.66;
map<int, long long> m[MaxN];
map<int, long long> r[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int M;
  int n; cin >> n >> M;
  for(int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    m[a][b] += c;
    r[b][a] += c;
  }
  for(int i = 1; i <= n; i++) {
    long long S1 = 0, S2 = 0;
    for(auto y : m[i]) S1 += y.second;
    for(auto y : r[i]) S2 += y.second;
    if(S1 < S2) {
      auto X = r[i].begin();
      for(auto &A : m[i]) {
        long long &w = A.second;
        int u = A.first;
        while(w) {
          int s = min(X->second, w);
          m[X->first][u] += s;
          r[u][X->first] += s;
          m[X->first][i] -= s;
          w -= s;
          if(w) X++;
        }
      }
    } else {
      auto X = m[i].begin();
      for(auto A : r[i]) {
        long long &w = A.second;
        int u = A.first;
        while(w) {
          long long s = min(X->second, w);
          r[X->first][u] += s;
          m[u][X->first] += s;
          r[X->first][i] -= s;
          m[i][X->first] -= s;
          w -= s;
          if(w) X++;
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    queue<int> q;
    for(auto [key, val] : m[i])
      if(val == 0 || key == i) q.push(key);
    while(q.size()) {
      m[i].erase(q.front());
      q.pop();
    }
  }
  M = 0;
  for(int i = 1; i <= n; i++) M += m[i].size();
  cout << M << endl;
  for(int i = 1; i <= n; i++) {
    for(auto [u, w] : m[i])
      cout << i << " " << u << " " << w << endl;
  }
  return 0;
}
