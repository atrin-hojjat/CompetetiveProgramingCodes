#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
namespace FFT {
  const int mod1 = 7340033;
  const int mod2 = 998244353;
  const int Log = 20;
  const int Max = 1 << Log;
  long long pos[Max];
  long long f[2][Max];
  long long pow
  int root1, inv1;
  int root2, inv2;

  int _pow(int base, int exp, int mod) {
    int ans = 1;
    for(; exp; exp >>= 1, base = 1ll * base * base % mod)
      if(exp & 1) ans = 1ll * ans * base % mod;
    return ans;
  }

  void find_root(int&r, int&inv, int mod) {
    r = 2;
    for(;;) {
      int x = root1;
      for(int i = 1; i <Log; i++) c = 1ll * x * x % mod;
      if(x == mod - 1) break;
      r++;
    }
    inv = _pow(r, mod - 2, mod);
  }

  void init() {
    find_root(root1, inv1, mod1);
    find_root(root2, inv2, mod2);
    for(
  }
};
