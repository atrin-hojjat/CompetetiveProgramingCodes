#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int Log = 18;
vector<int> divs[MaxN];
bool mark[MaxN];
int root[MaxN];
int trie[2][MaxN * Log * Log];
int mn[MaxN * Log * Log];
int ls;

void add(int r, int x) {
  if(root[r] == -1) root[r] = ls++;
  int node = root[r];
  mn[node] = min(mn[node], x);
  for(int i = Log - 1; i > -1; --i) {
    int cc = (x >> i) & 1;
    if(trie[cc][node] == -1)
      trie[cc][node] = ls++;
    node = trie[cc][node];
    mn[node] = min(mn[node], x);
  }
}

int get(int r, int x, int mx) {
  if(root[r] == -1 || mn[root[r]] > mx) return -1;
  int node = root[r];
  for(int i = Log - 1; i > -1; --i) {
    int cc = (x >> i) & 1;
    int nn = trie[1 ^ cc][node];
    if(nn == -1 || mn[nn] > mx)
      nn = trie[cc][node];
    node = nn;
  }
  return mn[node];
}

void prep() {
  for(int i = 1; i < MaxN; i++)
    for(int j = i; j < MaxN; j += i)
      divs[j].push_back(i);
}

int main() {
  memset(root, -1, sizeof root);
  memset(trie, -1, sizeof trie);
  memset(mn, 63, sizeof mn);
  prep();
  int q; scanf("%d", &q);
  for(;q--;){
    int t; scanf("%d", &t);
    if(t == 1) {
      int x; scanf("%d", &x);
      if(mark[x]) continue;
      mark[x] = true;
      for(auto w : divs[x])
        add(w, x);
    } else {
      int x, k, s; scanf("%d %d %d", &x, &k, &s);
      if(x % k) printf("-1\n");
      else {
        printf("%d\n", get(k, x, s - x));
      }
    }
  }
  return 0;
}
