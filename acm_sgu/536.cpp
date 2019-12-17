#include <bits/stdc++.h>
using namespace std;

/* Start Time : 12:54
 * End Time : 1:40
 * Elapsed Time : 45 Minutes
 */

const int MaxN = 15 + 1;
const int Inf = 1e9 + 7;
int inf;
int dis[MaxN][MaxN];
int dp[1 << MaxN][MaxN];
string tab[MaxN];
int id[MaxN][MaxN];
pair<int, int> point[MaxN];
int n,m;

void rem(int mask) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(tab[i][j] == '.') continue;
      if(tab[i][j] == '*') continue;
      if(mask & (1 << id[i][j])) continue;
      switch(tab[i][j]) {
        case 'R':
          for(int ii = i - 1; ii > -1; --ii) 
          {
            dis[ii][j] = -1;
            if(tab[ii][j] != '.') break;
          }
          for(int ii = i + 1; ii < n; ii++)
          {
            dis[ii][j] = -1;
            if(tab[ii][j] !='.') break;
          }
          for(int jj = j - 1; jj > -1; jj--)
          {
            dis[i][jj] = -1;
            if(tab[i][jj] != '.') break;
          }
          for(int jj = j + 1; jj < m; jj++)
          {
            dis[i][jj] = -1;
            if(tab[i][jj] != '.') break;
          }
          break;
        case 'K':
          for(int sg = -1; sg < 2; sg += 2)
            for(int x = 1; x <= 2; x++)
              for(int y = -1; y < 2; y += 2) {
                if(i + sg * x > -1 && i + sg * x < n &&
                    j + y * (3 - x) > -1 && j + y * (3 - x) < m)
                  dis[i + sg * x][j + y * (3 - x)] = -1;
              }
          break;
        case 'B':
          for(int sg1 = -1; sg1 < 2; sg1 += 2)
            for(int sg2 = -1; sg2 < 2; sg2 += 2)
            {
              int ii = i + sg1;
              int jj = j + sg2;
              while(ii > -1 && ii < n && jj > -1 && jj < m) {
                dis[ii][jj] = -1;
                if(tab[ii][jj] != '.') break;
                ii += sg1;
                jj += sg2;
              }
            }
          break;
      }
    }
  }
}

void bfs(int mask, int on) {
  memset(dis, 63, sizeof dis);
  rem(mask);
  queue<pair<int, int>> q;
  q.push(point[on]);
  if(dis[point[on].first][point[on].second] == -1) return;
  dis[point[on].first][point[on].second] = 0;
  while(q.size()) {
    pair<int, int> p = q.front(); q.pop();
    for(int i = -1; i < 2; i++)
      for(int j = -1; j < 2; j++) {
        if(i + p.first < n && i + p.first >=0 
            && j + p.second < m && j + p.second >= 0
            && dis[i + p.first][j + p.second] == inf)
          dis[i + p.first][j + p.second] = 1 + dis[p.first][p.second], q.push({i + p.first, j + p.second});
      }
  }
}

int main() {
  cin >> n >> m;
  int I = 0;
  pair<int, int> st;
  for(int i = 0; i < n; i++) {
    cin >> tab[i];
    for(int j = 0; j < m; j++) {
      if(tab[i][j] == '.') id[i][j] = -1;
      else point[I] = {i, j}, id[i][j] = I++;
      if(tab[i][j] == '*') st = {i, j};
    }
  }
  memset(dp, 63, sizeof dp);
  inf = dp[0][0];
  dp[1 << id[st.first][st.second]][id[st.first][st.second]] = 0;
  for(int mask = 0; mask < (1 << I); mask++) {
    if(!(mask & (1 << id[st.first][st.second]))) continue;
    for(int pt = 0; pt < I; pt++) {
      if(dp[mask][pt] == inf) continue;
      bfs(mask, pt);
      for(int j = 0; j < I; j++)
      {
        if(mask & (1 << j)) continue;
        int c = dis[point[j].first][point[j].second];
        if(c != -1 && c != inf)
          dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][pt] + dis[point[j].first][point[j].second]);
      }
    }
  }
  int ans = inf;
  for(int i = 0; i < I; i++) ans = min(ans, dp[(1 << I) - 1][i]);
  if(ans > -1 && ans < inf) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}
