#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
bool mark[MAXN];
int mx_prime[MAXN];
vector<int> gg[MAXN];
vector<pair<int, int>> ans;

void prep() {
  for(int i = 2; i < MAXN; i++)
    if(!mark[i])
      for(int j = i; j < MAXN; j += i)
        mx_prime[j] = i, mark[j] = true;
  memset(mark, 0, sizeof mark);
}

int main() {
  prep();
  int n; scanf("%d", &n);
  for(int i = 2; i <= n; i++)
    gg[mx_prime[i]].push_back(i);
  vector<int> rest;
  for(int i = 2; i <= n; i++) {
    if(gg[i].size() < 2) continue;
    bool k = gg[i].size() % 2;
    int prv = -1;
    for(auto x : gg[i]) {
      if(k && x == (i << 1)) continue;
      if(~prv) ans.push_back({prv, x}), prv = -1;
      else prv = x;
    }
    if(k) rest.push_back(gg[i][1]);
  }
  int prv = -1;
  for(auto x : rest)
    if(~prv) ans.push_back({prv, x}), prv = -1;
    else prv = x;
  printf("%lu\n", ans.size());
  for(auto x : ans) printf("%d %d\n", x.first, x.second);
  return 0;
}
