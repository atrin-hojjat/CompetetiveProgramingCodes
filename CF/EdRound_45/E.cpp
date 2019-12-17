#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
const long long inf = 1e15 + 12;
bool mark[MaxN];
int ls[MaxN];
int price[MaxN];

int main() {
  int n, k, m; scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < m; i++) {
    int x; scanf("%d", &x);
    mark[x] = true;
  }
  mark[n] = true;
  for(int i = 1; i < k + 1; i++) 
    scanf("%d", price + i);
  int kk = 0;
  int len = 0;
  for(int i = 0; i < n; i++) {
    if(mark[i]) 
      kk = max(kk, ++len);
    else len = 0;
  }
  kk++;
  if(mark[0]) {
    printf("-1\n");
    return 0;
  }
  for(int i = 1; i < n + 2; i++) 
    if(mark[i]) ls[i] = ls[i - 1];
    else ls[i] = i;
  long long ans = inf;
  for(int i = max(1, kk); i <= k; i++) {
    int st = 0;
    int cnt = 0;
    while(st < n) {
      if(mark[st]) {
        st = ls[st] + i;
      } else st = st + i;
      cnt++;
    }
    ans = min(ans, 1ll * cnt * price[i]);
  }
  if(ans < inf) printf("%lld\n", ans);
  else printf("-1\n");
  return 0;
}
