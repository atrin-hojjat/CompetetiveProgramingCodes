#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100 + 10 + 1;
struct DP {
  bool nx = false;
  int nx_i = -1, nx_j = -1, nx_k = -1;
  int val = -1;
} dp[MaxN][MaxN][MaxN];
string str1, str2, virus;
int failure[MaxN];
int nx[26][MaxN];

void add(int i1, int j1, int k1, int i2, int j2, int k2, bool nx = false) {
  DP x = dp[i1][j1][k1];
  if(!~x.val) return ;
  if(x.nx) {
    x.nx_i = i1;
    x.nx_j = j1;
    x.nx_k = k1;
    x.nx = false;
  }
  if(x.val + nx > dp[i2][j2][k2].val)
  {
    dp[i2][j2][k2] = x;
    dp[i2][j2][k2].nx = nx;
    dp[i2][j2][k2].val += nx;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> str1 >> str2 >> virus;
  int n1 = str1.size(), n2 = str2.size(), nv = virus.size();
  {
    reverse(virus.begin(), virus.end());
    int cur = 0;
    nx[virus[0] - 'A'][0] = 1;
    for(int i = 1; i <= nv; i++) {
      for(int c = 0; c < 26; c++) {
        if(i != nv && virus[i] - 'A' == c)
          nx[c][i] = i + 1;
        else nx[c][i] = nx[c][cur];
      }
      while(cur && virus[cur] != virus[i]) cur = failure[cur];
      if(virus[cur] == virus[i]) cur += 1;
      failure[i + 1] = cur;
    }
  }
  {
    dp[n1][n2][0] = {false, -1, -1, -1, 0};
    for(int i = n1; ~i; i--) {
      for(int j = n2; ~j; j--) {
        for(int k = 0; k < nv; k++) {
          add(i + 1, j, k, i, j, k);
          add(i, j + 1, k, i, j, k);
          if(i < n1 && j < n2 && //dp[i + 1][j + 1][k].val > -1 &&
              str1[i] == str2[j] && nx[str1[i] - 'A'][k] != nv) {
//            cout << k << " " << nx[str1[i] - 'A'][k] << " " << str1[i] << endl;
            add(i + 1, j + 1, k, i, j, nx[str1[i] - 'A'][k], true);
          }
        }
      }
    }
  }
  {
    for(int k = 1; k < nv; k++) add(0, 0, k, 0, 0, 0, false);
    DP x = dp[0][0][0];
//    cout << x.nx << " " << x.val << " " << x.nx_i << " " << x.nx_j << " " << x.nx_k << endl;
    if(x.val == 0) {
      cout << 0 << endl;
      return 0;
    }
    string ans = "";
    int xx = 0;
    for(;;) {
      if(x.nx) ans += str1[xx];
      xx = x.nx_i;
      if(xx == -1) break;
      x = dp[x.nx_i][x.nx_j][x.nx_k];
//      cout << x.nx << " " << x.val << " " << x.nx_i << " " << x.nx_j << " " << x.nx_k << endl;
    }
    cout << ans << endl;
  }
  return 0;
}
