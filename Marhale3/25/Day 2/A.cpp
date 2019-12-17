#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
const int delta = 10159;
int dp1[MaxN];
int dp_ans[MaxN];
int pw2[MaxN];

int main() {
  int n; cin >> n;
  pw2[0] = 1;
  for(int i = 1; i < MaxN; i++)
    pw2[i] = 1ll * pw2[i - 1] * 2 % delta;
  dp1[0] = 1;
  for(int i = 1; i < MaxN; i++)
    dp1[i] = 3ll * dp1[i - 1] % delta;
  dp_ans[0] = 0;
  for(int i = 1; i < MaxN; i++) {
    dp_ans[i] = 3ll * dp_ans[i - 1] % delta;
    dp_ans[i] += 2ll * dp1[i - 1] * pw2[i - 1] % delta;
    if(dp_ans[i] >= delta) dp_ans[i] -= delta;
  }
  cout << dp_ans[1] << " " << dp_ans[2] << " " << " " << dp_ans[3] << endl;
  cout << 1ll * dp_ans[n] * dp_ans[n] % delta * dp_ans[n] % delta << endl;
  return 0;
}
