#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
vector<pair<int, long long>> g[MaxN];
long long mark[MaxN];
bool mark2[MaxN];
long long mn[2];
vector<long long> odd_c;
int st_c;

int odd_cycle(int v = 1, int p = 0, int s = 1) {
  mark[v] = s;
  s = s % 2 + 1;
  for(auto x : g[v]) {
    if(x.first == p) continue;
    if(mark[x.first] == 0) {
      int z = odd_cycle(x.first, v, s);
      if(z != -1) {
        if(z) {
          odd_c.push_back(x.second);
          if(z == v) return 0;
        }
        return z;
      }
    } else if(mark[x.first] != s) {
      odd_c.push_back(x.second);
      st_c = x.first;
      return x.first;
    }
  }
  return -1;
}

bool check_dfs(int v, int val) {
  if(val <= 0) return false;
  mark[v] = val;
  for(auto x : g[v]) {
    if(mark[x.first]) {
      if(x.second != mark[x.first] + val) return false;
    } else if(!check_dfs(x.first, x.second - val)) return false;
  }
  return true;
}

bool bi_dfs(int v, long long val, bool sign) {
  mn[sign] = min(mn[sign], val);
  mark[v] = val;
  mark2[v] = true;
  for(auto x : g[v]) {
    if(mark2[x.first]) {
      if(x.second != mark[x.first] + val) return false;
      continue;
    }
    if(!bi_dfs(x.first, x.second - val, !sign)) return false;
  }
  return true;
}

int main() {
  int n, m; scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    int u, v; 
    long long w;
    scanf("%d %d %lld", &u, &v, &w);
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  if(~odd_cycle()) {
    long long sign = 1;
    long long sum = 0;
    for(auto x : odd_c) {
      sum += sign * x;
      sign *= -1;
    }
    memset(mark, 0, sizeof mark);
    printf("%d\n", sum % 2 == 0 && sum > 1 && check_dfs(st_c, sum / 2));
    return 0;
  }
  mn[0] = mn[1] = 15e15 + 7;
  memset(mark, 0, sizeof mark);
  if(!bi_dfs(1, 0, 0)) printf("0\n");
  else if(mn[1] <= 0 && mn[0] <= 0) printf("%d\n", 0);
  else printf("%lld\n", max(0LL, mn[1] + mn[0] - 1));
  return 0;
}
