#include <bits/stdc++.h>
using namespace std;

const int MaxN = 70 + 7;
const long long inf = 2e18 + 10;
int mu[MaxN];
bool mark[MaxN];

void prep() {
  for(int i = 2; i < MaxN; i++) mu[i] = -1;
  for(int i = 2; i < MaxN; i++) {
    if(mark[i]) continue;
    for(int j = i; j < MaxN; j += i) {
      mark[j] = true;
      if(j % (i * i) == 0) mu[j] = 0;
      else mu[j] *= -1;
    }
  }
}

long long pw(long long base, long long exp) {
  long long ans = 1;
  for(; exp; exp >>= 1, base = base < inf / base ? base * base : inf)
    if(exp & 1) ans = ans < inf / base ? ans * base : inf;
  return ans;
}

int main() {
  int T; scanf("%d", &T);
  prep();
  while(T--) {
    long long n; scanf("%lld", &n);
    long long ni = n;
    long long ans = n - 1;
    for(int i = 2; i < MaxN; i++) {
      if(ni == 1) break;
      long long l = 1, r = ni;
      while(l < r) {
        long long mid = l + (r - l + 1) / 2;
        if(pw(mid, i) > n) r = mid - 1;
        else l = mid;
      }
      ni = l;
      ans -= 1ll * (ni - 1) * mu[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
