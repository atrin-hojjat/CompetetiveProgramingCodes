#include <iostream>
#include <set>
using namespace std;

const int MaxN = 2e5 + 6.66;
const int mod = 998244353;

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % mod)
    if(exp & 1) ans = 1ll * ans * base % mod;
  return ans;
}

#define int long long

int pi[MaxN];
int sum[MaxN];
int sum2[MaxN];
int arr[MaxN];
int Sum;
bool check[MaxN];
set<int> nxt;
set<int> prv;

int calc(int a, int b) {
  b--;
  int s1 = sum2[b - 1];
  int s2 = sum[b  - 1];
  if(a > 1) s2 -= sum[a - 2], s1 -= sum2[a - 2];
  if(s1 < 0) s1 += mod;
  if(s2 < 0) s2 += mod;
  int C = s2;
  s2 = 1ll * s2 * (a - 1) % mod;
  int s3 = s1 - s2;
  s3 %= mod;
  if(s3 < 0) s3 += mod;
  int S = pi[b - 1];
  if(a > 1) S = 1ll * S * _pow(pi[a - 2], mod - 2) % mod, C = 1ll * C * _pow(pi[a - 2], mod - 2) % mod, s3 = 1ll * s3 * _pow(pi[a - 2], mod - 2) % mod;
  S = 1ll * (b - a + 1) * S % mod;
  int c = 1 + mod - C;
  return 1ll * (0ll + S + s3) % mod * _pow(c, mod - 2) % mod;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int X = _pow(100, mod - 2);
  int n, q; cin >> n >> q;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < n; i++) arr[i] = 1ll * arr[i] * X % mod;
  pi[0] = arr[0];
  for(int i = 1; i < n; i++) pi[i] = 1ll * pi[i - 1] * arr[i] % mod;
  for(int i = 0; i < n; i++) {
    sum[i] = (1 - arr[i] + mod);
    if(sum[i] > mod) sum[i] -= mod;
    if(i > 0) sum[i] = 1ll * sum[i] * pi[i - 1] % mod, sum[i] = (sum[i] + sum[i - 1]) % mod;
  }
  for(int i = 0; i < n; i++) {
    sum2[i] = 1ll * (1 - arr[i] + mod) * (i + 1) % mod;
    if(i > 0) sum2[i] = 1ll * sum2[i] * pi[i - 1] % mod, sum2[i] = (sum2[i] + sum2[i - 1]) % mod;
  }
//  Sum = 1ll * (0ll + 1ll * n * pi[n - 1] % mod + sum2[n - 1]) % mod * _pow(1 + mod - sum[n - 1], mod - 2) % mod;
  Sum = calc(1, n + 1);
  prv.insert(-1);
  nxt.insert(n + 1);
  for(int i = 0; i < q; i++) {
    int x; cin >> x;
    if(check[x]) {
      check[x] = false;
      prv.erase(-x);
      nxt.erase(x);
      int N = *nxt.lower_bound(x);
      int P = -*prv.upper_bound(-x);
      Sum = Sum - calc(P, x) - calc(x, N) + calc(P, N);
      Sum %= mod;
      if(Sum < 0) Sum += mod;
    } else {
      check[x] = true;
      int P = -*prv.upper_bound(-x);
      int N = *nxt.lower_bound(x);
      prv.insert(-x);
      nxt.insert(x);
      Sum = Sum + calc(P, x) + calc(x, N) - calc(P, N);
      if(Sum < 0) Sum += mod;
      Sum %= mod;
    }
    cout << Sum << endl;
  }
  return 0;
}
