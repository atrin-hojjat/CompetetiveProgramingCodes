#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+6.66;
vector<int> ed[MAXN];
vector<int> rev[MAXN];
int scc[MAXN];
long long cost[MAXN];
vector<int> topo;
long long sum[MAXN];
long long dp[MAXN];
vector<int> sccs;
bool mark[MAXN];

void topo_dfs(int x) {
  if(mark[x]) return ;
  mark[x] = true;
  for(auto w : ed[x])
    topo_dfs(w);
  topo.push_back(x);
}

void scc_dfs(int w,int I) {
  if(!mark[w]) return ;
  mark[w] = false;
  scc[w] = I;
  sum[I] += cost[w];
  for(auto z : rev[w])
    scc_dfs(z,I);
}

void create_scc(int n) {
  for(int i = 1;i<=n;i++)
    if(!mark[i])
      topo_dfs(i);
  int I = 0;
  reverse(topo.begin(),topo.end());
  for(auto w : topo)
    if(mark[w])
      scc_dfs(w,++I);
}

void create_dp(int n,int S,int E) {
  dp[scc[S]] = sum[scc[S]]+1;
  for(auto w : topo)
  {
    if(!dp[scc[w]]) continue;
    int s = scc[w];
    for(auto z : ed[w])
      if(scc[z] != scc[w])
        dp[scc[z]] = max(dp[s] + sum[scc[z]],dp[scc[z]]);
  }
}

int main() {
  int n,m;cin >> n >> m;
  int S,E;cin >> S >> E;
  for(int i = 1;i<=n;i++) cin >> cost[i];
  for(int i = 0;i<m;i++)
  {
    int x,y;cin >> x >> y;
    ed[x].push_back(y);
    rev[y].push_back(x);
  }
  create_scc(n);
  create_dp(n,S,E);
  cout << dp[scc[E]]-1 << endl;
  return 0;
}
