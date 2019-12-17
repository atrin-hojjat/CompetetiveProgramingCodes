#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b,c; scanf("%lld %lld %lld", &a, &b, &c);
  long long k; scanf("%lld", &k);
  long long ans = a - b;
  if(k&1)
    ans = b - a;
  printf("%lld\n",ans);
  return 0;
}
