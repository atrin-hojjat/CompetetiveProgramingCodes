#include <bits/stdc++.h>
using namespace std;

const int delta = 10771;//1e6 + 3;
const long long mod = 1ll * delta * delta;
long long dp[6][1 << 12];
vector<vector<int>> vs;
vector<int> now;
int NN;

// 0 1 2 3 
// A T C G

void generate(int n = 0, int T = -1) {
  if(n == 0) {
    now = vector<int>(NN);
  }
  if(n == NN) {
    vs.push_back(now);
    return ;
  }
  for(int i = 0; i < 4; i++)
    if(i != T) {
      now[n] = i;
      generate(n + 1, i);
    }
}

bool additional(int i, int j) {
  switch(i) {
    case 0:
      return vs[j][1] == 0;
    case 1:
      return vs[j][4] == 3;
    case 2:
      return vs[j][0] == 1;
    case 3:
      return vs[j][5] == 3;
    case 4:
      return true;
    case 5:
      return vs[j][1] == 2;
    default:
      return false;
  }
}

long long& add(long long &x, long long y) {
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int main() {
  cin >> NN;
  generate();
  long long Ans = 0;
  for(int i = 0; i < NN; i++) {
    for(int j = 0; j < (int) vs.size(); j++) {
      if(additional(i, j) == false) continue;
      if(i == 0) dp[i][j] = 1;
      else {
        for(int k = 0; k < (int) vs.size(); k++) {
          if(additional(i - 1, k) == false) continue;
          bool ok = false;
          for(int c = 1; c < NN; c++) {
            ok |= (vs[k][c] == vs[j][c]) || (vs[k][c - 1] == vs[j][c - 1])
              || (vs[k][c - 1] == vs[j][c]) || (vs[k][c] == vs[j][c - 1]);
          }
          if(!ok) add(dp[i][j], dp[i - 1][k]);
        }
      }
      if(i == NN - 1) add(Ans, dp[i][j]);
    }
  }
  cout << Ans << endl;
  return 0;
}
