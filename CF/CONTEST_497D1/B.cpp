#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
long long cnt[MaxN];

void prep() {
  for(int i = 1; i < MaxN; i++)
    for(int j = i; j < MaxN; j += i)
      cnt[j]++;
}

long long _2(int x) {
  return 1ll * x * (x - 1) / 2;
}

long long _3(int x) {
  return 2 * _2(x) + 2ll * x * (x - 1) * (x - 2) / 3;
}

long long _4(int A, int B, int C) {
  return 0;
  if(A == B || B == C || C == A) return 0;
  int ga = cnt[__gcd(A, __gcd(B, C))];
  int ab = cnt[__gcd(A, B)] - ga;
  int cb = cnt[__gcd(C, B)] - ga;
  int ac = cnt[__gcd(A, C)] - ga;
  return 0ll + 1ll * ga * (ab + cb + ac);
}

int main() {
  int Q; scanf("%d", &Q);
  prep();
  while(Q--) {
    int A, B, C; scanf("%d %d %d", &A, &B, &C);
    long long ans = 
      1ll * cnt[A] * cnt[B] * cnt[C] - cnt[C] * _2(cnt[__gcd(A, B)]) - cnt[B] * _2(cnt[__gcd(C, A)])
      - cnt[A] * _2(cnt[__gcd(B, C)]) + _3(cnt[__gcd(A, __gcd(B, C))]) + _4(A, B, C);
    printf("%lld\n", ans);
  }
  return 0;
}
