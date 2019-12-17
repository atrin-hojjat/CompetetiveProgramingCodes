#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
long long arr[MaxN];
map<long long, int> cnt;

long long mul(long long a, long long b) {
  if(a > 1e15l / b) return 1e15l;
  return a * b;
}

int main() {
  int N; scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%lld", arr + i);
  for(int i = 0; i < N; i++) {
    long long aa = arr[i];
    for(long long c = 2; c * c * c <= aa; c++) {
      if(arr[i] % c) continue;
      long long x = c * c * c;
      while(arr[i] % x == 0) arr[i] /= x;
    }
    cnt[arr[i]]++;
  }
  int ans = 0;
  for(auto x : cnt) {
    if(!x.second) continue;
    long long a = x.first;
    long long tmp = a;
    long long b = 1;
    for(long long x = 2; x * x * x <= 1e10l; x++) {
      if(tmp % x) continue;
      if(tmp % (x * x)) b = mul(b, x * x), tmp /= x;
      else b = mul(b, x), tmp /= x * x;
    }
    if(tmp > 1) b = mul(b, tmp * tmp);
    if(b > 1e10l) ans += x.second;
    else if(a == b) ans ++;
    else {
      ans += max(x.second, cnt[b]);
      cnt[b] = 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}
