#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
int arr[MaxN];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  sort(arr, arr + n);
  int c = (n - 1) / 2;
  int pt = n - 1;
  int ans = 0;
  for(int i = n - 1; i > -1; --i) {
    while(pt > -1 && arr[pt] >= arr[i]) pt--;
    if(pt < 0) break;
    ans++;
    pt--;
  }
  printf("%d\n", ans);
  return 0;
}
