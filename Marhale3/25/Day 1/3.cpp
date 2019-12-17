#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5000 + 500 + 50 + 5;
const int delta = 1e9 + 7;
const int delta2 = 10103;
int fact[MaxN];
int ifact[MaxN];

int _pow(int base, int exp, int mod = delta) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod) 
    if(exp & 1) ans = 1ll * ans * base % mod;
  return ans;
}

void prep() {
  fact[0] = 1;
  for(int i = 1; i < MaxN; i++) fact[i] = 1ll * fact[i - 1] * i  % delta;
  ifact[MaxN - 1] = _pow(fact[MaxN - 1], delta - 2);
  for(int i = MaxN - 1; i > 0; i--) ifact[i - 1] = 1ll * ifact[i] * i % delta;
}

int main() {
  int n, t, k;
  cin >> n >> t >> k;
  prep();
  int ans = 1;
  for(int i = 0; i < t; i++) {
    ans = 1ll * ans * (_pow(2, n) - i + delta) % delta;
  }
  ans = 1ll * ans * ifact[t] % delta;
  int f = 1;
  for(int i = 0; i < k - t + 1; i++) {
    f = 1ll * f * (_pow(2, n) - i - t + delta) % delta;
  }
  ans = 1ll * ans * f % delta * ifact[k - t + 1] % delta;
  cout << ans % delta2 << endl;
  return 0;
}
