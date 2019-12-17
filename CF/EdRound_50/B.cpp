#include <bits/stdc++.h>
using namespace std;

int main() {
  int q; scanf("%d", &q);
  while(q--) {
    long long n, m, k; scanf("%lld %lld %lld", &n, &m, &k);
    long long c = abs(n - m);
    long long x = min(n, m);
    if(k < x + c) printf("-1\n");
    else {
      bool cc = (m + n) % 2;
      if(cc) {

      } else {
      
      }
    }
  }
  return 0;
}
