#include <bits/stdc++.h>
using namespace std;

const int mod = 10313;
const int delta = mod;

int& add(int&x, long long y) {
   y %= mod;
   x += y;
   if(x >= mod) x -= mod;
   return x;
}

int main() {
  int p = 13099;
//  cin >> p;
  int s = 1;
  int pi = 1;
  int inv2 = (mod + 1) / 2;
  for(int i = 1; i <= p; i++) {
    int s1 = 0, s2 = 0;
    for(int j = 0; j < p; j++) {
      if(i % 2 == 0) {
        add(s1, 1ll * pi * (pi + 1) * inv2 % mod * j * pi);
        add(s2, 1ll * (1ll * (2ll * j * pi + pi + 1) * pi * inv2 % mod) % mod * j * pi);
      } else {
        add(s1, 1ll * pi * (pi + 1) * inv2 % mod * j * pi);
        add(s2, 1ll * (1ll * (2ll * (p - j - 1) * pi + pi + 1) * pi % mod * inv2 % mod) % mod * j * pi);
      }
    }
    s = 1ll * p * s % mod + s1 + s2;
    s %= mod;
    pi = 1ll * pi * p % delta;
  }
  cout << s << endl;
  return 0;
}
