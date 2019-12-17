#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200;
const int mod = 10303;
const int delta = mod;
int ps[MaxN];

int& add(int&x, long long y) {
  y %= mod;
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int main() {
  int n; cin >> n;
  int A1 = 1, B = 1, C = 1, E = 1;
  int D = 1;
  // A1 = ans, B = (11111..1), C = (1234....n!), E = (1111..110000...0), D = pow
  for(int i = 2; i <= n; i++) D = 1ll * D * i % mod;
  add(D, 3);
  // 2 :
  A1 = (2ll * D + 1) % mod;
  B = (D + 1) % mod;
  C = (D + 2) % mod;
  E = D;
  D = 1ll * D * D % mod;
  for(int i = 3; i <= n; i++) {
    int Na = 0, Nb = 0, Nc = 0, Nd = 1, Ne = 0;
    int IF = 1;
    for(int j = 1; j < i; j++) IF = 1ll * IF * j % mod;
    for(int j = 0, k = 0; j < i; j++, add(k, 1ll * IF * B % mod))
      Nc = (1ll * Nc * D % mod + C + k) % mod;
    for(int j = 0; j < i; j++) 
      Nb = (1ll * Nb * D % mod + B) % mod;
    for(int j = 0; j < i; j++) 
      Nd = 1ll * D * Nd % mod;
    Ne = B;
    Ne = (1ll * Ne * D % mod + E) % mod;
    for(int j = 0; j < i - 2; j++)
      Ne = Ne * D % mod ;
    int If = 1;
    int cc = 0;
    int Ix = 1;
    for(int I = 1; I <= i; I++) {
      If = 1ll * If * I % mod;
      (cc += If) %= mod;
      if(I == i - 1) Ix = If;
    }
    cc -= If;
    if(cc < 0) cc += mod;
    Na = (C + 1ll * B * (If - cc + mod) % mod) % mod;
    Na = 1ll * Na * D % mod;
    (Na += A1 + 1ll * E * (If - Ix + mod) % mod) %= mod;
    cout << Na << endl;
    If = 1, cc = 0;
    for(int I = 1; I <= i - 1; I++) {
      If = 1ll * If * I % mod;
      (cc += If) %= mod;
    }
    cc -= If;
    if(cc < 0) cc += mod;
    for(int j = 0; j < i - 2; j++)
      Na = (1ll * Na * D % mod + C + 1ll * B * (1ll * If * j % mod + If - cc + mod) % mod) % mod;
    A1 = Na, B = Nb, C = Nc, D = Nd, E = Ne;
    cout << i << " " << A1 << " " << B << " " << C << " " << D << " " << E << endl;
  }
  cout << A1 << endl;
  return 0;
}
