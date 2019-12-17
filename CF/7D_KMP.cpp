#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5e6 + 6.66;
string str;
int failure[2 * MaxN];
int dp[2 * MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> str;
  int n_main = str.size();
  int n = str.size() * 2;
  int cur = 0;
  for(int I = 1; I < n; I++) {
    int i = I;
    if(i >= n_main) i = n - i - 1;
    while(cur && str[i] != str[cur])
      cur = failure[cur];
    if(str[i] == str[cur]) cur++;
    failure[I + 1] = cur;
//    cout << cur << " ";
  }
//  cout << endl;
  cur = failure[n];
  while(cur) {
    if(cur <= n_main) dp[cur] = true;
    cur = failure[cur];
  }
  for(int i = 0; i <= n; i++) 
    if(dp[i]) dp[i] += dp[i / 2];
  int ans = 0;
  for(int i = 0; i <= n; i++) ans += dp[i];
  cout << ans << endl;
  return 0;
}
