#include <iostream>
using namespace std;

const int MaxN = 1e5 + 6.66;
long long arr[MaxN];

int main() {
  int m;
  long long n, k; scanf("%lld %d %lld", &n, &m, &k); 
  for(int i = 0; i < m; i++) scanf("%lld", arr + i);
  for(int i = 0; i < m; i++) arr[i]--;
  int I = 0;
  int op = 0;
  while(I < m) {
    int r = I;
    int c = (arr[I] - r) / k;
    I++;
    while((arr[I] - r) / k == c) I++;
    op++;
  }
  printf("%d\n", op);
  return 0;
}
