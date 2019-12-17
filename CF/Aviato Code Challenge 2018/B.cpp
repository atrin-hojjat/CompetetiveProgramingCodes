#include <bits/stdc++.h>
using namespace std;

map<int,int> income;

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x,y; scanf("%d %d", &x, &y);
    income[x] = y;
  }
  int m; scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    int x,y; scanf("%d %d", &x, &y);
    if(income.count(x)) income[x] = max(income[x], y);
    else income[x] = y;
  }
  long long ans = 0;
  for(auto x : income) ans += x.second;
  printf("%lld\n", ans);
  return 0;
}
