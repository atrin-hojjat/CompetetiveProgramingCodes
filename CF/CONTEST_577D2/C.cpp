#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 2e5 + 6.66;
int a[MaxN];

int main() {
  int n; scanf("%d", &n);
  int k; scanf("%d", &k);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  a[n] = 2e9 + 6.66;
  int mid = n / 2;
  int ptr = n / 2;
  while(ptr < n && a[ptr] == a[ptr + 1]) ptr++;
  while(k / (ptr - mid + 1) > 0 && ptr < n) {
    int ad = min(a[ptr + 1] - a[ptr], k / (ptr - mid + 1));
    if(ad <= 0) break;
    a[mid] += ad;
    k -= ad * (ptr - mid + 1);
    a[ptr] = a[mid];
    while(ptr < n && a[ptr] == a[ptr + 1]) ptr++;
  }
  int ad = min(a[ptr + 1] - a[ptr], k / (ptr - mid + 1));
  if(ad > 0) a[mid] += ad, k -= ad;
  while(ptr < n && a[ptr] == a[ptr + 1]) ptr++;
  printf("%d\n", a[mid]);
  return 0;
}
