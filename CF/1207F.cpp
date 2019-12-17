#include <iostream>
using namespace std;

const int MaxN = 500000 + 6.66;
const int Sq = 800;
int sum[Sq][Sq];
int arr[MaxN];

int main() {
  int q; scanf("%d", &q);
  while(q--) {
    int t, x, y; scanf("%d %d %d", &t, &x, &y);
    if(t == 1) {
      arr[x] += y;
      for(int i = 1; i < Sq; i++) 
        sum[i][x % i] += y;
    } else {
      if(x < Sq) printf("%d\n", sum[x][y]);
      else {
        int s = 0;
        for(int i = y; i < MaxN; i += x) s += arr[i];
        printf("%d\n", s);
      }
    }
  }
  return 0;
}
