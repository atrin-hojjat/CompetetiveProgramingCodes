#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
int phi[MaxN];

int main() {
  for(int i = 0; i < MaxN; i++) phi[i] = i;
  for(int i = 2; i < MaxN; i++) {
    if(phi[i] != i) continue;
    for(int j = i; j < MaxN; j += i)
      phi[j] = phi[j] / i * (i - 1);
  }
  int T; cin >> T;
  while(T--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", phi[x]);
  }
  return 0;
}
