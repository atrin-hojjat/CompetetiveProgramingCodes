#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
const int mod = 1e6 + 3;
int phi[MaxN];

void prep() {
  for(int i = 0; i < MaxN; i++)  phi[i] = i;
  for(int i = 2; i < MaxN; i++)
  {
    if(phi[i] != i) continue;
    for(int j = i; j < MaxN; j++)
      phi[j] = 1ll * phi[j] / j * (j - 1);
  }
}

int& add(int&x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int main() {
  prep();
  int ans = 0;
  for(int i = 0; i < MaxN; i++)
    if(phi[i] == 60) add(ans, 1ll * i * i % mod);
  cout << ans << endl;
  return 0;
}
