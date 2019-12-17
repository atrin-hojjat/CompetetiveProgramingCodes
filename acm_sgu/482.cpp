#include <bits/stdc++.h>
using namespace std;

const int MaxN = 50 + 6.66;
const int MaxH = 100 + 1;
const int MaxP = MaxH * MaxN + 2 * MaxN;
const int Max = 25;
short ps[1 << Max];
short sum[1 << Max];
int H[MaxN];
pair<int,int> dp1[MaxH][MaxP];
pair<int,int> dp2[MaxH][MaxP];

void init_perimeter(int n, int*h, short*p, short*sum) {
  for(int mask = 1; mask < (1 << n); mask++) {
    sum[mask] = sum[mask ^ (mask & -mask)] + h[__builtin_ctz(mask)];
    p[mask] = 2 + h[__builtin_ctz(mask)];
    if(__builtin_popcount(mask) == 1) p[mask] += h[__builtin_ctz(mask)];
    else {
      int i = __builtin_ctz(mask);
      int j = __builtin_ctz(mask ^ (mask & -mask));
      p[mask] += p[mask ^ (mask & -mask)] ;
      p[mask] -= h[j];
      p[mask] += abs(h[j] - h[i]);
    }
  }
}

int main() {
  int n; scanf("%d", &n);
  int n1 = min(Max, n);
  int n2 = n - n1;
  for(int i = 0; i < n; i++) scanf("%d", H + i);
  int P = 2 * n;
  for(int i = 1; i < n; i++) P += abs(H[i] - H[i - 1]);
  P += H[0] + H[n - 1];
  init_perimeter(n2, H, ps, sum);
  for(int i = 0; i < MaxH; i++)
    for(int j = 0; j < MaxP; j++) dp1[i][j] = dp2[i][j] = {-1, -1};
  int M = (1 << n2) - 1;
  for(int mask = 0; mask < (1 << n2); mask++) {
    int hh = (mask ? H[31 - __builtin_ctz(mask)] : 0);
    dp1[hh][ps[mask]] = max(dp1[hh][ps[mask]], {sum[M & ~mask], mask});
  }
  for(int h = 0; h < MaxH; h++)
    for(int p = MaxP - 2; p > -1; --p)
      dp1[h][p] = max(dp1[h][p], dp1[h][p + 1]);
  for(int h = 0; h < MaxH; h++)
    for(int per = 0; per < MaxP; per++) {
      for(int h2 = 0; h2 < MaxH; h2++) {
        int c = abs(h2 - h) - h2 - h;
        int pp = max((P + 1)/2 - (per - c), 0);
        if(pp > -1 && pp < MaxP) dp2[h][per] = max(dp2[h][per], dp1[h2][pp]);
      }
    }
  int ans = dp2[0][0].first;
  int mx_mask = 0;
  M = (1 << n1) - 1;
  init_perimeter(n1, H + n2, ps, sum);
  for(int mask = 1; mask < (1 << n1); mask++) {
    int aa = sum[M & ~mask];
    pair<int, int> cc = dp2[H[n2 + __builtin_ctz(mask)]][ps[mask]];
    if(~cc.first && ans < cc.first + aa)
    {
      ans = cc.first + aa;
      mx_mask = mask;
    }
  }
  if(ans == -1) {
    printf("0\n0\n");
    return 0;
  }
  printf("%d\n", ans);
  vector<int> Ans;
  int mm = M & ~mx_mask;
  while(mm) {
    Ans.push_back(n2 + __builtin_ctz(mm));
    mm ^= mm & -mm;
  }
  M = (1 << n2) - 1;
  int mask2 = M & ~dp2[H[n2 + __builtin_ctz(mx_mask)]][ps[mx_mask]].second;
  while(mask2) {
    Ans.push_back(__builtin_ctz(mask2));
    mask2 ^= mask2 & -mask2;
  }
  sort(Ans.begin(), Ans.end());
  printf("%lu\n", Ans.size());
  for(auto x : Ans) printf("%d%c", x + 1, " \n"[x == Ans.back()]);
  return 0;
}
