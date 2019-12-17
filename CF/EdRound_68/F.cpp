#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
const int MaxN = 2e5 + 6.66;
long long arr[MaxN];
int fact[MaxN], ifact[MaxN];

int _pow(int b, int e) {
  int ans = 1;
  for(; e; e >>= 1, b = 1ll * b * b % mod)
    if(e & 1) ans = 1ll * ans * b % mod;
  return ans;
}

int inv(int x) {
  return _pow(x, mod - 2);
}

void prep() {
  fact[0] = 1;
  for(int i = 1; i < MaxN; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
  ifact[MaxN - 1] = inv(fact[MaxN - 1]);
  for(int i = MaxN - 1; i > 0; i--) ifact[i - 1] = 1ll * ifact[i] * i % mod;
}

int C(int n, int r) {
  if(n < r || r < 0) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main() {
  int n; cin >> n; 
  long long T; cin >> T;
  prep();
  for(int i = 0; i < n; i++) cin >> arr[i];
  long long sum = 0, sum1 = 0;
  int exp = 0;
  int prv = -1;
  int I = 0;
  for(int i = 0; i < n; i++) {
    sum += arr[i] + 1;
    sum1 += arr[i];
    if(sum <= T) {
      exp++;
      continue;
    }
    if(sum1 > T) break;
    if(I == 0) {
      prv = 0;
      for(int j = 0; j <= T - sum1; j++) 
        (prv += C(i + 1, j)) %= mod;
      exp = 1ll * (0ll + exp + 1ll * prv * inv(_pow(2, i + 1)) % mod) % mod;
      I = 1;
    } else {
      for(int j = T - sum1 + arr[i]; j > T - sum1; j--)
        prv = (0ll + prv - C(i, j) + mod) % mod;
      prv = 1ll * (2ll * prv - C(i, T - sum1) + mod) % mod;
      exp = 1ll * (0ll + exp + 1ll * prv * inv(_pow(2, i + 1)) % mod) % mod;
    }
  }
  cout << exp << endl;
  return 0;
}
