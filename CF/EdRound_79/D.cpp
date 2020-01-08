#include <iostream>
#include <vector>
using namespace std;

#ifdef Atrin
const int MaxN = 10;
#else 
const int MaxN = 1e6 + 6.66;
#endif
const int mod = 998244353;
vector<int> arr[MaxN];
int fact[MaxN];
int ifact[MaxN];

long long _pow(long long base, long long exp) {
  long long ans = 1;
  for(; exp; exp >>= 1, base = base * base % mod)
    if(exp & 1) ans = ans * base % mod;
  return ans;
}

long long inv(long long x) { return _pow(x, mod - 2); }

void init() {
  fact[0] = 1;
  for(int i = 1; i < MaxN; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
  ifact[MaxN - 1] = inv(fact[MaxN - 1]);
  for(int i = MaxN - 1; i > 0; --i) ifact[i - 1] = 1ll * ifact[i] * i % mod;
}

int C(int n, int r) {
  if(n < r || r < 0) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main() {
  init();
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int k; cin >> k;
    for(int j = 0; j < k; j++) {
      int a; cin >> a;
      arr[a].push_back(k);
    }
  }
  long long ans = 0;
  for(int i = 0; i < MaxN; i++) {
    for(auto u : arr[i])
      (ans += 1ll * inv(1ll * n * n % mod) * inv(u) % mod * arr[i].size() % mod) %= mod;
  }
  cout << ans << endl;
  ////
  return 0;
}
