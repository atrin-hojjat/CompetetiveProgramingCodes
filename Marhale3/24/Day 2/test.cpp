#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 10303;
  int n; cin >> n;
  int fact[n + 1] = {};
  for(int i = 1; i <= n; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  int d = (fact[n] + 3) % mod;
  int s = 1;
  for(int i = 2; i <= n; i++) {
    int ans = 0, B, C, D, E;
    for(int j = 0; j < fact[i]; j++) {
      j`
    }
  }
  return 0;
}
