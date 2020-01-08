#include <iostream>
using namespace std;

#define int long long

const int MaxN = 5e5 + 6.66;
int fact[MaxN];

int32_t main() {
  int n, m; cin >> n >> m;
  int ans = 0;
  int mod = m; fact[0] = 1;
  for(int i = 1; i < MaxN; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
  for(int len = 1; len <= n; len++) {
    int st = n - len + 1;
    ans = (ans + 1ll * fact[len] * fact[n - len] % m * st % mod * st% mod) % mod;
  }
  cout << ans << endl;
  return 0;
}
