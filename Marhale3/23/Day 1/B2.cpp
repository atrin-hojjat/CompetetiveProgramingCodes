#include <bits/stdc++.h>
using namespace std;

const int mod = 10253;
struct S {
  int vals[7];

  S() { memset(vals, 0, sizeof vals); }

  S operator + (pair<int, pair<int, int>> a) {
    S res = *this;
    res.vals[a.first]++;
    res.vals[a.second.first]++;
    res.vals[a.second.second]++;
    return res;
  }
} ;
int dp[2][1 << 14];
int Ans;

void _plus(int&x) {
  x++;
  if(x == mod) x = 0;
}

int main() {
  bool now = true;
  dp[0][0] = 1;
  for(int i = 0; i < 7; i++) {
    memset(dp[now], 0, sizeof dp[now]);
    for(int x = 0; x < 7; x++)
      for(int y = x + 1; y < 7; y++)
        for(int z = y + 1; z < 7; z++) {
          for(int i = 0; i < (1 << 14); i++) {
            int xx = (i >> (2 * x)) % 4;
            if(xx == 3) continue;
            xx = (i >> (2 * y)) % 4;
            if(xx == 3) continue;
            xx = (i >> (2 * z)) % 4;
            if(xx == 3) continue;
            (dp[now][i + (1 << (2 * x)) + (1 << (2 * y)) + (1 << (2 * z))]+= dp[not now][i])%=mod;
          }
        }
    now = not now;
  }
  int ans = 0;
  ans = (1 << 14) - 1;
  cout << dp[not now][ans] << endl;
  return 0;
}
