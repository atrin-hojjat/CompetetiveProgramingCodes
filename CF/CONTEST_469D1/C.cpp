#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
vector<int> ed[MAXN];
vector<int> rev[MAXN];
vector<int> topo;
int sz[MAXN];
int scc[MAXN];
bool mark[MAXN];
bool sink[MAXN];
int mn[MAXN];

void add_edge(int x,int y) {
  ed[x].push_back(y);
  rev[y].push_back(x);
}

void add(int x,int y,int h) {
  if( (mn[x] + 1) %h == mn[y]) add_edge(x,y);
}

void topo_dfs(int v) {
  mark[v] = true;
  for(auto w : ed[v]) if(!mark[w]) topo_dfs(w);
  topo.push_back(v);
}

void scc_dfs(int v,int I) {
  mark[v] = false;
  scc[v] = I;
  sz[I] ++;
  for(auto w : rev[v]) if(mark[w]) scc_dfs(w,I);
}

bool check_sink(int v) {
  mark[v] = true;
  for(auto w : ed[v])
    if( scc[w] != scc[v] ) return sink[scc[v]] = false;
    else {
      if(mark[w]) continue;
      if(!check_sink(w)) return sink[scc[v]] = false;
    }
  return true;
}

int main() {
  int n,m,h;cin >> n >> m >>h;
  for(int i = 0;i<n;i++) cin >> mn[i];
  for(int i = 0;i<m;i++) {
    int x,y;cin >> x >> y;
    x--,y--;
    add(x,y,h);
    add(y,x,h);
  }
  for(int i = 0;i<n;i++) if(!mark[i]) topo_dfs(i);
  reverse(topo.begin(),topo.end());
  for(auto w : topo) if(mark[w]) scc_dfs(w,w);
  for(auto w : topo) if(!mark[w]) sink[scc[w]] = check_sink(w);
  pair<int,int> ans = {1e9 + 7,1e9+7};
  for(auto i : topo) if(sink[scc[i]]) ans = min(ans,{sz[scc[i]],scc[i]});
  cout << ans.first << endl;
  for(int i = 0;i<n;i++)  if(scc[i] == ans.second) cout << i+1 << " ";cout << endl;
  return 0;
}
