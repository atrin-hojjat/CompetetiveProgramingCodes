#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200 + 20 + 2;
vector<int> G[2][MAXN];
int match[2][MAXN];
int a[MAXN];
bool mark[MAXN];
bool M[2][MAXN];
map<int,bool> ch[2];

bool dfs(int v) {
  mark[v] = true;
  for(auto w : G[0][v])
    if(match[1][w] == -1 || ( mark[match[1][w]] == false && dfs(match[1][w]) ) ) 
    {
      match[1][w] = v;
      match[0][v] = w;
      return true;
    }
  return false;
}

void DFS(int v,int i) {
  ch[i][v] = true;
  M[i][v] = true;
  for(auto w : G[i][v])
    if(!M[i][match[i^1][w]]) M[i^1][w] = true,DFS(match[i^1][w],i);
}

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> a[i];
  for(int i = 0;i<n;i++) for(int j = i+1;j<n;j++) if(~a[i] && ~a[j] && a[i] == a[j]) a[j] = -1;
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;++j)
      if(i!= j && ~a[i] && ~a[j] && a[i] % a[j] == 0)
      {
        G[0][j].push_back(i);
        G[1][i].push_back(j);
      }
  int ANS = 0;
  memset(match,-1,sizeof match);
  for(;;) {
    bool done = true;
    memset(mark,0,sizeof mark);
    for(int i = 0;i<n;i++)
    {
      if(a[i] == -1) {continue;}
      if(mark[i] == false && match[0][i] == -1 && dfs(i))
        ANS ++,done = false;
    }
    if(done) break;
  }
  for(int i = 0;i<n;i++) {
    if(a[i] == -1) continue;
    if(match[0][i] == -1) DFS(i,0);
    if(match[1][i] == -1) DFS(i,1);
  }
  for(int i = 0;i<n;i++) {
    if(!M[0][i]) DFS(i,0);
    if(!M[1][i]) DFS(i,0);
  }
  vector<int> ans;
  for(int i = 0;i<n;i++)
    if(ch[0][i] && ch[1][i]) ans.push_back(i);
  cout << ans.size() << endl;
  for(auto w : ans) cout << a[w] << " " ;
  cout << endl;
  return 0;
}
