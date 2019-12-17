#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+6.66;
vector<int> adj[MAXN];
bool mark[MAXN];
vector<int> topo;

void create_topo(int v) {
  mark[v] = true;
  for(auto w : adj[v])
    if(!mark[w])
      create_topo(w);
  topo.push_back(v);
}

void dfs(int v) {
  mark[v] = false;
  for(auto cc : adj[v])
    if(mark[cc]) dfs(cc);
}

int main() {
  int T;cin >> T;
  for(int I = 1 ;I<=T;I++) {
    int n,m;cin >> n >> m;
    for(int i = 0;i<=n;i++) adj[i].clear();
    topo.clear();
    for(int i = 0;i<m;i++) {
      int x,y;cin >> x >> y;
      adj[x].push_back(y);
    }
    for(int i = 1 ;i<=n;i++)
      if(!mark[i]) create_topo(i);
    reverse(topo.begin(),topo.end());
    int ans = 0;
    for(auto wx : topo)
      if(mark[wx])
        dfs(wx),ans++;
    cout << "Case " << I << ": "<< ans << endl;
  }
  return 0;
}
