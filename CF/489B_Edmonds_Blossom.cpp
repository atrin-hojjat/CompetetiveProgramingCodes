#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10 + 1;
vector<int> ed[MAXN];
int a[MAXN];
int b[MAXN];
bool mark[MAXN];
int match_up[MAXN];
int match_down[MAXN];

bool dfs(int v) {
  mark[v] = true;
  for(auto w : ed[v])
    if(!~match_up[w] || ( !mark[match_up[w]] && dfs(match_up[w]) ) ) {
      match_down[v] = w;
      match_up[w] = v;
      return true;
    }
  return false;
}

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> a[i];
  int m;cin >> m;
  for(int i = 0;i<m;i++) cin >> b[i];
  for(int i = 0;i<n;i++)
    for(int j = 0;j<m;j++)
      if(abs(a[i] - b[j]) < 2)
        ed[i].push_back(j);
  memset(match_up,-1,sizeof match_up);
  memset(match_down,-1,sizeof match_down);
  int ans = 0;
  while(true) {
    for(int i = 0 ;i<n;i++) mark[i] = 0;
    bool done = true;
    for(int i = 0 ;i<n;i++) 
      if(!mark[i] && match_down[i] == -1 && dfs(i))
        ans++,done = false;
    if(done) break;
  }
  cout << ans << endl;
  return 0;
}
