#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 6.66;
int a[MAXN];

int main() {
  int n,k; scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  for(int i = 2; i <= sqrt(k) || k > 1; i++) {
    if(k % i) continue;
    int pw = 1;
    while(k % i == 0) k /= i,pw *= i;
    bool ok = false;
    for(int j = 0; j < n; j++)
      if(a[j] % pw == 0) { ok = true; break; }
    if(!ok) { printf("No\n"); return 0; }
  }
  printf("Yes\n");
  return 0;
}
