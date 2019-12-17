#include <bits/stdc++.h>
using namespace std;

#define NO {printf("0\n"); return 0; };

const int MAXN = 1e5 + 6.66;
int arr[MAXN];

int main() {
  int n,k; scanf("%d %d", &n, &k);
  int m = n * k;
  int l; scanf("%d", &l);
  for(int i = 0; i < m; i++) cin >> arr[i];
  sort(arr, arr + m);
  long long sum = arr[0];
  int last = upper_bound(arr, arr + m,  min((long long)1e9,0ll + l + sum)) - arr;
  if(last < n) NO;
  int prv = 0;
  for(int i = 1; i < n; i++) {
    int now = min(k * i, last - n + i);
    sum += arr[now];
  }
  printf("%lld\n", sum);
  return 0;
}
