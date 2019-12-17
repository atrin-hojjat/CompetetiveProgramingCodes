#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MaxN = 1e6 + 6.66;
const int inf = 1e9 + 6;
vector<int> tab[MaxN];
vector<int> dis[MaxN];


void bfs(int n, int m, vector<pair<int, int>> st, vector<int>* res) {
  queue<pair<int, int>> q;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) res[i][j] = inf;
  auto OK = [] (int x, int y) -> bool { return x >= 0 && x < y; };
  for(auto [x, y] : st) res[x][y] = 0, q.push({x, y});
  while(q.size()) {
    auto [x, y] = q.front();
    q.pop();
    for(int i = -1; i < 2; i++)
      for(int j = -1; j < 2; j++)
        if(OK(x + i, n) && OK(y + j, m) && res[x + i][y + j] > res[x][y] + 1) {
          res[x + i][y + j] = res[x][y] + 1;
          q.push({x + i, y + j});
        }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  string* s = new string[2 + n];
  for(int i = 1; i <= n ;i++) cin >> s[i];
  for(int i = 0; i <= 1 + m; i++) s[0] += '.';
  s[n + 1] = s[0];
  for(int i = 1; i <= n; i++) s[i] = '.' + s[i] + '.';
  n += 2, m += 2;
  int L = 1, R = (n * m);
  for(int i = 0; i < n; i++) tab[i].resize(m);
  for(int i = 0; i < n; i++) dis[i].resize(m);
  vector<pair<int, int>> V;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(s[i][j] == '.') V.push_back({i, j});
  if(V.size() == R) {
    cout << 0 << endl;
    for(int i = 1; i < n - 1; i++, cout << "\n")
      for(int j = 1; j < m - 1; j++) cout << ".";
    cout << endl;
    return 0;
  }
  bfs(n, m, V, dis);
  while(L < R) {
    int mid = L + (R - L + 1) / 2;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        if(dis[i][j] >= mid) v.push_back({i, j});
    bfs(n, m, v, tab);
    bool ok = true;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) 
        if((s[i][j] == '.' && tab[i][j] < mid) || (s[i][j] == 'X' && tab[i][j] >= mid)) { ok = false; break; }
    if(ok) L = mid;
    else R = mid - 1;
  }
  cout << L - 1<< endl;
  for(int i = 1; i < n - 1; i++, cout << "\n")
    for(int j = 1; j < m - 1; j++)
      if(dis[i][j] >= L) cout << "X"; else cout << ".";
  return 0;
}
