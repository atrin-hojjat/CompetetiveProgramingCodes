#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
int arr[MaxN];

int main() {
  int n; scanf("%d", &n);
  printf("YES\n");
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  int gc = arr[0];
  for(int i = 1; i < n; i++) gc = __gcd(gc, arr[i]);
  if(gc > 1) {
    printf("0\n");
    return 0;
  } else {
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < n + 1; i++) {
      if(arr[i] % 2 == 0) {
        if(cnt % 2) ans += (cnt + 1) / 2 + 1;
        else ans += cnt/2;
        cnt = 0;
        continue;
      }
      cnt++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
