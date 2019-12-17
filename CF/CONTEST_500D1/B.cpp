#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
vector<int> eds[MaxN * 2];
int mark[MaxN * 2];

void dfs(int v) {
  mark[v] = true;
  for(auto x : eds[v])
    if(!mark[x]) dfs(x);
}

int main() {
  int N, M, Q; scanf("%d %d %d", &N, &M, &Q);
  for(int i = 0; i < Q; i++) {
    int x, y; scanf("%d %d", &x, &y);
    x--, y--;
    eds[x].push_back(N + y);
    eds[y + N].push_back(x);
  }
  int ans = 0;
  for(int i = 0; i < N; i++) if(!mark[i]) dfs(i), ans++;
  for(int i = 0; i < M; i++) if(!mark[N + i]) dfs(i + N), ans++;
  printf("%d\n", ans - 1);
  return 0;
}
