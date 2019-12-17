#include <iostream>
using namespace std;

const int MaxN = 1e5 + 6.66;
int a[MaxN];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  int od = 0;
  for(int i = 0; i < n; i++) od += a[i] % 2;
  if(od % 2) { printf("NO\n"); return 0; }
  long long sum = 0;
  for(int i = 0; i < n; i++) sum += a[i];
  for(int i = 0; i < n; i++)
    if(a[i] > sum / 2) {
      printf("NO\n");
      return 0;
    }
  printf("YES\n");
  return 0;
}

