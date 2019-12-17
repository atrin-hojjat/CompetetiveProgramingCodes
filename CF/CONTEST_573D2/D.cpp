#include <iostream>
using namespace std;

const int MaxN = 1e5 + 6.66;
int arr[MaxN];

int main() {
  int n; scanf("%d", &n);
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    sum += arr[i];
  }
  if(n == 1) {
    if(sum % 2) printf("sjfnb\n");
    else printf("cslnb\n");
    return 0;
  }
  sort(arr, arr + n);
  int cn = 0, CN = -1;
  for(int i = 1; i < n; i++) if(arr[i] == arr[i - 1]) { cn++; CN = i;} 
  if(cn > 1 || (~CN && arr[CN] == 0)) {
    printf("cslnb\n");
    return 0;
  } else if(cn == 1) {
    for(int i = 0; i < n; i++) if(arr[i] == arr[CN] - 1) { cn = -1; break; }
    if(cn == -1) { printf("cslnb\n"); return 0; }
  }
  sum -= 1ll * n * (n - 1) / 2;
  if(sum % 2 == 0) printf("cslnb\n");
  else printf("sjfnb\n");
  return 0;
}
