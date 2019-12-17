#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
map<long long, int> cmp;
int add[MaxN * 2];
int rem[MaxN * 2];
long long ans[MaxN];
long long arr[MaxN * 2];
long long a[MaxN * 2];

int compress(int n) {
  for(int i = 0; i < 2 * n; i++) cmp[arr[i]] = 0;
  int I = 0;
  for(auto&x : cmp) a[I] = x.first, x.second = I++;
  return cmp.size();
}

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%lld %lld", arr + 2 * i, arr + 2 * i + 1);
  int N = compress(n);
  for(int i = 0; i < n; i++) {
    rem[cmp[arr[i * 2 + 1]]]++;
    add[cmp[arr[i * 2]]]++;
  }
  int k = add[0];
  ans[k]++;
  k -= rem[0];
  for(int i = 1; i < N; i++) {
    ans[k] += a[i] - a[i - 1] - 1;
    k += add[i];
    ans[k]++;
    k -= rem[i];
  }
  for(int i = 1; i <= n; i++) printf("%lld%c", ans[i], " \n"[n == i]);
  return 0;
}
