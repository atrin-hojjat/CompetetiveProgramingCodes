#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3e5 + 6.66;
const int Max = 1e6 + 6.66;
int dp[Max * 2];
int a[MaxN], b[MaxN];
vector<pair<int, int>> arr;

void alter(int x, int val) {
  x += 2;
  while(x < Max) 
    dp[x] = max(dp[x], val), x += x & -x;
}

int get(int x) {
  x += 2;
  int ans = 0;
  while(x) ans = max(dp[x], ans), x ^= x & -x;
  return ans;
}

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  int m; scanf("%d", &m);
  for(int i = 0; i < m; i++) scanf("%d", b + i);
  long long s1 = 0, s2 = 0;
  for(int i = 0; i < n; i++) s1 += a[i];
  for(int i = 0; i < m; i++) s1 -= b[i];
  if(s1 != s2) {
    printf("-1\n");
    return 0;
  }
  int i = 0, j = 0;
  while(i <= n || j <= m) {
    if(s1 > s2) {
      s2 += b[j];
      j++;
    } else if(s1 < s2) {
      s1 += a[i];
      i++;
    } else {
      arr.push_back({i, j});
      s1 += a[i], s2 += b[j];
      i++, j++;
    }
  }
  for(int i = 1; i < arr.size(); i++) {
    alter(i, get(i) + 1);
  }
  printf("%d\n", get(arr.size()));
  return 0;
}
