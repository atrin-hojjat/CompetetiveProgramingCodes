#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

const int MaxN = 2e3 + 6.66;
bool mark[MaxN];
vector<int> ed[MaxN];
int match[MaxN];

bool dfs(int v) {
  mark[v] = true;
  for(auto x : ed[v])
    if(match[x] == -1 || (mark[match[x]] == false && dfs(match[x])))
    {
      match[x] = v;
      match[v] = x;
      return true;
    }
  return false;
}

void dfs2(int x, int n) {
  mark[x] = true;
  if(~match[x + n] && !mark[match[x + n]]) dfs2(match[x + n], n);
  if(~match[x] && !mark[match[x] - n]) dfs2(match[x] - n, n);
}

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int k; cin >> k;
    while(k--) {
      int t; cin >> t;
      ed[i].push_back(t + n);
      ed[t + n].push_back(i);
    }
  }
  memset(match, -1, sizeof match);
  while(true) {
    bool stop = true;
    for(int i = 0; i < 2 * n; i++) mark[i] = false;
    for(int i = 0; i < n; i++)
      if(!mark[i] && match[i] == -1 && dfs(i))
        stop = false;
    if(stop) break;
  }
  memset(mark, 0, sizeof mark);
  int cnt = 0;
  for(int i = 0; i < n; i++)
    if(!mark[i]) dfs2(i, n), cnt++;
  cout << cnt << endl;
  return 0;
}
