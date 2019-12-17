#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3+6.66;
vector<int> g[MAXN];
vector<int> rev[MAXN];
vector<int> scc_adj[MAXN];
//set<int> scc_adj[MAXN];
vector<int> topo;
vector<int> scc_topo;
int scc[MAXN];
bool mark[MAXN];

void create_topo(int v) {
  mark[v] = true;
  for(auto w : g[v])
    if(!mark[w])
      create_topo(w);
  topo.push_back(v);
}

void create_scc(int v,int I) {
  mark[v] = false;
  scc[v] = I;
  for(auto w : rev[v])
    if(mark[w]) create_scc(w,I);
}

void dfs(int v) {
  mark[v] = true;
  for(auto u : scc_adj[v])
    if(!mark[u]) 
      dfs(u);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n;cin >> n;
  for(int i = 1;i<=n;i++) {
    int x;cin >> x;
    while(x) {
      g[i].push_back(x);
      rev[x].push_back(i);
      cin >> x;
    }
  }
  for(int i = 1;i<=n;i++)
    if(!mark[i])
      create_topo(i);
  reverse(topo.begin(),topo.end());
  int I = 1;
  for(auto w : topo)
    if(mark[w])
      create_scc(w,I),scc_topo.push_back(I++);
  for(auto w : topo)
    for(auto c : g[w])
      if(scc[w]!=scc[c])
        scc_adj[scc[w]].push_back(scc[c]);
  fill(mark,mark+MAXN,false);
  dfs(scc_topo[0]);
  for(int i = 1;i<I;i++)
    if(!mark[i]) {
      cout << 0 << endl;
      return 0;
    }
  for(int i = 1;i<=n;i++)
    if(scc[i] == scc_topo[0])
      cout << i << " ";
  cout << 0 << endl;
  return 0;
}
