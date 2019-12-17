#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 2000 + 200 + 20 + 2;
const int mod = 998244353;
int dp[MaxN][MaxN];

int main() {
  string str; cin >> str;
  int n = str.size();
  for(int len = 1; len <= n; len++) {
    for(int l = 0; l + len < n; l++) {
      int r = l + len;
      if(str[r] == '(') dp[l][r] = dp[l][r - 1];
    }
  }

  return 0;
}
