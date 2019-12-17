#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100 + 10 + 1;
const int delta = 10159;
int mod;
int mark[MaxN][MaxN];
int in[2][MaxN][MaxN];

int _pow(int base, int exp, int m = mod) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % m)
    if(exp & 1) ans = 1ll * ans * base % m;
  return ans;
}

int main() {
  int n, cc; cin >> n >> mod >> cc;
  in[0][1][n] = in[0][1][1] = in[0][n][1] = in[0][n][n] = 1;
  vector<pair<int, int>> move;
  move.push_back({-1, 0});
  move.push_back({1, 0});
  move.push_back({0, -1});
  move.push_back({0, 1});
  long long ans = 0;
  int t = 0;
  for(t = 1; t < 10 * n; t++) {
    bool now = t % 2;
    // Morning
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        in[now][i][j] = in[!now][i][j];
    //Noon
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
      {
        if(mark[i][j]) continue;
        if(!in[!now][i][j]) continue;
        for(auto x : move) {
          int ii = i + x.first;
          int jj = j + x.second;
          if(!mark[ii][jj])
          {
            in[now][ii][jj] += 1;//in[!now][i][j];
            if(in[now][ii][jj] > mod + cc)
              in[now][ii][jj] = mod + cc;
          }
        }
      }
    bool changed = false;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if(!mark[i][j] && in[now][i][j] != in[!now][i][j]) changed = true;
    //Afternoon
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if(!mark[i][j] && in[now][i][j] >= 1ll * cc + 1ll * _pow(7, i) * _pow(3, j) % mod)
        {
          mark[i][j] = t;
        }
    if(!changed) break;
  }
  cout << __LINE__ << endl;
  if(t < 10 * n) t++;
  int CC = 0;
  bool now = t % 2;
  while(true) {
    bool can = false;
    long long nx_mn = mod + cc;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++) {
        if(mark[i][j])
          continue;
        int around = 0;
        for(auto x : move) {
          int ii = x.first + i;
          int jj = x.second + j;
          if(ii > 0 && ii < n + 1 && jj > 0 && jj < n + 1 && mark[ii][jj] == 0 && in[!now][ii][jj])
          {
            around++;
          }
        }
        if(around) {
          can = true;
          nx_mn = min(nx_mn, 1ll * (1ll * _pow(7, i) * _pow(3, j) % mod + cc - in[!now][i][j]+ around - 1) / around);
        }
      }
    if(!can) break;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        in[now][i][j] = in[!now][i][j];
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
      {
        if(mark[i][j]) continue;
        if(!in[!now][i][j]) continue;
        for(auto x : move) {
          int ii = i + x.first;
          int jj = j + x.second;
          if(!mark[ii][jj])
          {
            in[now][ii][jj] += nx_mn;//in[!now][i][j];
            if(in[now][ii][jj] > mod + cc)
              in[now][ii][jj] = mod + cc;
          }
        }
      }
    int cnt = 0;
    t += nx_mn;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if(!mark[i][j] && in[now][i][j] >= 1ll * cc + 1ll * _pow(7, i) * _pow(3, j) % mod)
        {
          mark[i][j] = t - 1;
          cnt++;
        }
    CC++;
    cout << CC << endl;
    now = !now;
  }
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      ans += mark[i][j];
  cout << ans << endl;
  ans %= delta;
  cout << 1ll * ans * ans % delta * ans % delta << endl;
  return 0;
}
