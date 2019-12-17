#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1 << 25;
const int delta = 10369;
bool mark[MaxN];
long long mul[MaxN];

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % delta)
    if(exp & 1) ans = 1ll * base * ans % delta;
  return ans;
}

int main() {
  int n; cin >> n;
  long long ans = 0;

  for(int k = 1; k <= n / 2; k++) {
    mul[k] = 1;
    long long now = 1;
    int len = k;
    while(len + k <= n) {
      len += k;
      now <<= k;
      now |= 1;
      now %= delta;
      mul[k] = 1ll * mul[k] * now % delta;
    }
  }

  for(long long i = 1; i < (1 << (n >> 1)); i++) {
    if(mark[i]) continue;
    int x = 64 - __builtin_clzll(i);
    int x1 = x;
    long long ii = 0;
    ans += n / x - 1;
    while(x <= n / 2) {
      ii <<= x1;
      ii |= i;
      mark[ii] = true;
      x += x1;
    }
  }
  cout << ans % delta << endl;
  return 0;
}
