#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MaxN = 1e5 + 6.66;
set<int> obs[4][MaxN];

void check(pair<int, int> &x, pair<pair<int, int>, pair<int, int>> box) {
  x.first = max(x.first, box.first.first);
  x.first = min(x.first, box.second.first);
  x.second = max(x.second, box.first.second);
  x.second = min(x.second, box.second.second);
}

int main() {
  int n, m, k; cin >> n >> m >> k;
  for(int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    obs[0][x].insert(y);
    obs[1][y].insert(x);
    obs[2][x].insert(-y);
    obs[3][y].insert(-x);
  }
  for(int i = 0; i <= n; i++) 
    obs[0][i + 1].insert(0), obs[0][i + 1].insert(m + 1);
  for(int i = 0; i <= m; i++)
    obs[1][i + 1].insert(0), obs[1][i + 1].insert(n + 1);
  for(int i = 0; i <= n; i++) 
    obs[2][i + 1].insert(0), obs[2][i + 1].insert(-m - 1);
  for(int i = 0; i <= m; i++)
    obs[3][i + 1].insert(0), obs[3][i + 1].insert(-n - 1);
  pair<pair<int, int>, pair<int, int>> box = {{0, 0}, {1 + n, 1 + m}};
  pair<int, int> pos = {1, 1};
  pair<int, int> st = pos;
  int dir = 0;
  long long cnt = 1;
  int nomove = 0;
  while(true) {
    pair<int, int> nx = pos;
    if(dir < 2) {
      auto x = obs[dir][dir == 1 ? pos.second : pos.first].upper_bound(dir == 1 ? pos.first : pos.second);
      dir == 1 ? nx = {-1 + min(*x, box.second.first), pos.second} : nx = {pos.first, -1 + min(*x, box.second.second)};
      if(nomove && nx == pos) break;
      //check(nx, box);
      {
        //dir = (dir + 3) % 4;
        dir == 1 ? box.second.second = pos.second : box.first.first = pos.first;
        //box.second.second = max(box.first.second, box.second.second);
        //dir = (dir + 1) % 4;
      }
    } else {
      auto x = obs[dir][dir == 3 ? pos.second : pos.first].upper_bound(dir == 3 ? -pos.first : -pos.second);
      dir == 3 ? nx = {1 - min(-box.first.first, *x), pos.second} : nx = {pos.first, 1 - min(-box.first.second, *x)};
      if(nomove && nx == pos) break;
      //check(nx, box);
      {
        //dir = (dir + 3) % 4;
        dir == 3 ? box.first.second = pos.second : box.second.first = pos.first;
        //box.second.first = max(box.second.first, box.first.first);
        //dir = (dir + 1) % 4;
      }
    }
    cnt += abs(nx.first - pos.first) + abs(nx.second - pos.second);
    if(nomove && nx == pos) break;
    dir = (dir + 1) % 4;
    pos = nx;
    nomove = 1;
  }
  if(cnt == 1ll * n * m - k) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
