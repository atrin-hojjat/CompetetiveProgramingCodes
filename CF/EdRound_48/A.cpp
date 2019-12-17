#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; scanf("%d %d", &n, &m);
  int now = 0;
  for(int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    int c = (now + x) / m;
    now = (now + x) % m;
    printf("%d%c", c, " \n"[i == n - 1]);
  }
  return 0;
}
