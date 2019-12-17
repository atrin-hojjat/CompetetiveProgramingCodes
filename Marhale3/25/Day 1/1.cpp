#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
const int delta = 10103;
int dp[MaxN];
int dp2[MaxN];

int _pow(int base, long long exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % delta)
    if(exp & 1) ans = 1ll * ans * base % delta;
  return ans;
}

void brute_force(int n) {
  int cc = (1 << 5) - 1;
  for(int i = 0; i < (1 << 25); i++) {
    int ans = -1;
    for(int x = 0; x < 5; x++) {
      int mask = (i >> (5 * x)) & cc;
      if(mask & (1 << 4)) {
        ans = -1;
        break;
      }
      if(mask == 0) {
        bool ok = true;
        for(int xx = x; xx < 5; xx++)
        {
          if((i >> (5 * xx)) & 1) {
            ok = false;
            break;
          }
        }
        if(ok) {
          dp2[x + 1]++;
          break;
        }
      }
    } 
  }
}

int main() {
  int n; cin >> n;
  int ans = 0;
  int sum;
  sum = dp[1] = 1;
  for(int i = 2; i <= n; i++) {
    dp[i] = _pow(2, 1ll * (n - 1) * (i - 1)) - sum;
    if(dp[i] < 0) dp[i] += delta;
//    cout << (1ll * dp[i] * _pow(2, 1ll * (n - 1) * (n - i)) % delta)  << " ";
    sum = 1ll * sum * _pow(2, n - 2) % delta;
    sum += dp[i];
    if(sum > delta) sum -= delta;
  }
//  cout << endl;
  for(int i = 1; i <= n; i++) {
//    ans += dp2[i] % delta;
    ans += 1ll * _pow(2, 1ll * (n - 1) * (n - i)) * dp[i] % delta;
    if(ans > delta) ans -= delta;
  }
  cout << ans << endl;
  return 0;
}
