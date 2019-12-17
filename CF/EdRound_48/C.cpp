#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3e5 + 6.66;
int arr[2][MaxN];
long long sum[MaxN];
long long sum2[2][MaxN];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < n; j++) scanf("%d", arr[i] + j);
  long long s1 = 0, s2 = 0, ans = 0;
  for(int i = 0; i < n; i++) s1 += 1ll * arr[0][i] * i + 1ll * arr[1][i] * (2 * n - i - 1);
  for(int i = n - 1; i > -1; --i) sum[i] = sum[i + 1] + arr[0][i] + arr[1][i];
  for(int i = n - 1; i > -1; --i) sum2[0][i] = sum2[0][i + 1] + sum[i + 1] + 1ll * (2 * (n - i) - 1) * arr[1][i];
  for(int i = n - 1; i > -1; --i) sum2[1][i] = sum2[1][i + 1] + sum[i + 1] + 1ll * (2 * (n - i) - 1) * arr[0][i];
  ans = s1;
  for(int i = 0; i < n; i++) {
    if(i % 2 == 0) s2 += 2ll * arr[0][i] * i + 1ll * arr[1][i] * (2 * i + 1);
    else s2 += 2ll * arr[1][i] * i + 1ll * arr[0][i] * (2 * i + 1);
    ans = max(ans, s2 + 2ll * (i + 1) * sum[i + 1] + sum2[(i + 1) % 2][i + 1]);
  }
  ans = max(ans, s2);
  cout << ans << endl;
  return 0;
}
