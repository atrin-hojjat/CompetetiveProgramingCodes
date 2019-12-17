#include <bits/stdc++.h>
using namespace std;

#define NO { printf("NO\n"); exit(0); };

const int MaxN = 100 + 10 + 1;
int mat[MaxN][MaxN];
int a[MaxN], b[MaxN];

int main() {
  int n, m; scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  for(int i = 0; i < m; i++) scanf("%d", b + i);
  for(int bit = 31; bit > -1; bit--) {
#define A(x) ((a[x] >> bit) & 1) 
#define B(x) ((b[x] >> bit) & 1)
    int cntN = 0;
    int cntM = 0;
    for(int i = 0; i < n; i++) if(A(i)) cntN++;
    for(int i = 0; i < m; i++) if(B(i)) cntM++;
    int c1 = 0, c2 = 0;
    if(cntN % 2 != cntM % 2) NO;
    for(int i = 0; i < n; i++) {
      c1 += A(i);
      c2 = 0;
      for(int j = 0; j < m; j++) {
        c2 += B(j);
        if(A(i) == 0 && B(j) == 0) continue;
        if(cntN == 0) {
          if(i == 0) mat[i][j] |= 1 << bit;
        } else if(cntM == 0) {
          if(j == 0) mat[i][j] |= 1 << bit;
        } else if(A(i) && B(j)){
          if(cntN % 2) mat[i][j] |= 1 << bit;
          else if((c1 == cntN) != (c2 == cntM)) mat[i][j] |= 1 << bit;
        }
      }
    }
  }
  printf("YES\n");
  for(int i = 0; i < n; i++) 
    for(int j = 0; j < m; j++)
      printf("%d%c", mat[i][j], " \n"[j == m - 1]);
  return 0;
}
