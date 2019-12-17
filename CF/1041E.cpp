#include <bits/stdc++.h>
using namespace std;

#define No { printf("NO\n"); exit(0); }

const int MaxN = 1000 + 100 + 10 + 1;
vector<pair<int, int>> eds;
int cnt[MaxN];

int main() {
  int n; scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int x, y; scanf("%d %d", &x, &y);
    if(y != n) No;
    cnt[x]++;
  }
  int pt1 = 1;
  for(int i = 1; i < n; i++) {
    if(cnt[i] == 0) continue;
    int cc = 1, ls = n;
    while(cc < cnt[i] && pt1 < i) {
      if(cnt[pt1]) { pt1++; continue; }
      eds.push_back({ls, pt1});
      ls = pt1;
      pt1++, cc++;
    }
    if(cc == cnt[i]) {
      eds.push_back({ls, i});
    } else No;
  }
  printf("YES\n");
  for(auto x : eds) printf("%d %d\n", x.first, x.second);
  return 0;
}
