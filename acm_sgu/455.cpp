#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e6 + 6.66;

int main() {
  long long A, B, C;
  scanf("%lld %lld %lld", &A, &B, &C);
  long long fel = 1;
  for(int i = 1; i < 2000002; i++) fel = (fel * A + fel % B) % C;
  long long lel = fel;
  int ic;
  for(ic = 1; ic < 2000002; ic++) {
    lel = (lel * A + lel % B) % C;
    if(lel == fel) break;
  }
  fel = 1, lel = 1;
  for(int i = 0; i < ic; i++) lel = (lel * A + lel % B) % C;
  int id_f = 0;
  for(id_f = 0; id_f < 2000002; id_f++) {
    if(fel == lel) break;
    fel = (fel * A + fel % B) % C;
    lel = (lel * A + lel % B) % C;
  }
  if(id_f + ic <= 2e6) printf("%d\n", id_f + ic);
  else printf("-1\n");
  return 0;
}
