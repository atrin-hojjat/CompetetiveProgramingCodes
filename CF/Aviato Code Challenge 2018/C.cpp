#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
vector<int> tree[MAXN];
vector<int> xx;

void dfs(int v, int par = 0) {
  for(auto u : tree[v])
    if(u != par) dfs(u, v);
  if(tree[v].size() == 1) xx.push_back(v);
}

int main() {
  int n; scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int x,y; scanf("%d %d", &x, &y);
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  int cnt = 0;
  int pl = -1;
  int cc = 1;
  for(int i = 1; i < n + 1; i++)
    if(tree[i].size() > 2) {
      if(cnt) {
        printf("No\n");
        return 0;
      }
      cnt = 1;
      pl = i;
    } else if(tree[i].size() == 1) cc = i;
  if(~pl) {
    printf("Yes\n");
    dfs(pl);
    printf("%lu\n", xx.size());
    for(auto x : xx) printf("%d %d\n", pl, x);
  } else {
    printf("Yes\n1\n");
    dfs(cc);
    printf("%d %d\n", cc, xx[0]);
  }
  return 0;
}
