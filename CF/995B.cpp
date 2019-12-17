#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200 + 20 + 2;
int arr[MaxN];
int mark[MaxN];
int cnt[MaxN];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < 2 * n; i++) scanf("%d", arr + i);
  double ans = 0;
  for(int i = 0; i < 2 * n; i++) {
    if(mark[arr[i]]) continue;
    mark[arr[i]] = true;
    memset(cnt, 0, sizeof cnt);
    for(int j = i + 1; j < 2 * n; j++) {
      if(arr[i] == arr[j]) break;
      cnt[arr[j]]++;
    }
    for(int i = 1; i <= n; i++) 
      if(cnt[i] > 1) ans += cnt[i];
      else ans += 0.5l * cnt[i];
  }
  printf("%d\n", (long long) ans);
  return 0;
}
