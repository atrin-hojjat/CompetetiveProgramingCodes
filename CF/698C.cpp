#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
long double dp[1<<MAXN][MAXN];
long double pos[MAXN];
long double sum[1<<MAXN];
long double sum2[1<<MAXN];
long double ans[1<<MAXN];

void init_sum(int N) {
  for(int i = 1;i<(1<<N);i++)
    sum[i] = pos[__builtin_ctz(i)] + sum[i^(i&-i)];
}

void calc_dp(int n,int k) {
  for(int i = 0;i<(1<<n);i++) {
    if(__builtin_popcount(i) > k) continue;
    for(int j = 0;j<n;j++)
      sum2[i] += (dp[i][j] += sum[i^(1<<j)] * pos[j]);
  }
}

void calc_ans(int n,int k) {
  for(int i = 0;i<(1<<n);i++) {
    if(__builtin_popcount(i) != k) continue;
    for(int i
  }
}

int main() {
  
}
