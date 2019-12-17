#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  int a, b;
  scanf("%lld %lld %d %d", &n, &m, &a, &b);
  long long cost = 0;
  cost = min(a * (m - n % m), b * (n % m));
  printf("%lld\n", cost);
  return 0;
}
