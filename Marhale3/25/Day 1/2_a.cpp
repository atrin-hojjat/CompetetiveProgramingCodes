#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5e4 + 6.66;
const int Max = 40000;
const int delta = 10103;
vector<int> children[MaxN];
bool mark[MaxN];
bool beu[MaxN];
int par_sum[MaxN];
int n = Max;

void prep() {
  for(int i = n; i > 1; --i) {
    for(int j = i + i; j <= n; j += i) {
      if(mark[j]) continue;
      mark[j] = true;
      children[i].push_back(j);
    }
  }
  for(int i = 2; i <= n; i++) {
    if(mark[i]) continue;
    if(i <= n / i) beu[i * i] = true;
  }
}

int main() {
  prep();
  int I = 0;
  for(int i = 2; i <= n; i++)
    if(beu[i]) {
      par_sum[I++] += children[i].size();
    }
  sort(par_sum, par_sum + I);
  for(int i = 1; i < I; i++) par_sum[i] += par_sum[i - 1];
  int ans = 0;
  for(int j = 1; j <= 150; j++) {
    int pos = upper_bound(par_sum, par_sum + I, j) - par_sum - 1;
    int kk = 1ll * (pos + 1) * par_sum[pos] % delta;
    ans += 1ll * kk * kk % delta;
    if(ans >= delta) ans -= delta;
  }
  cout << ans << endl;
  return 0;
}
