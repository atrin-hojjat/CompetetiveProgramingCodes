#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
vector<int> adj[MAXN];
vector<int> jda[MAXN];
vector<int> scc_adj[MAXN];
vector<int> scc_jda[MAXN];
int scc[MAXN];
int sum[MAXN];
int dp[MAXN];
int to_one[MAXN];
bool mark[MAXN];
vector<int> topo;

void create_topo(int v) {
  mark[v] = true;
  for(auto u : adj[v])
    if(!mark[u])
      create_topo(u);
  topo.push_back(v);
}

void SCC(int v,int sc) {
  scc[v] = sc;
  mark[v] = false;
  for(auto u : jda[v])
    if(mark[u])
      SCC(u,sc);
}

void sum_scc(int v) {
  sum[scc[v]]++;
  mark[v] = true;
  for(auto u : adj[v])
    if(!mark[u] && scc[u] == scc[v])
      sum_scc(u);
    else if(scc[u] != scc[v]) {
      scc_adj[scc[v]].push_back(scc[u]);
      scc_jda[scc[u]].push_back(scc[v]);
    }
}

void count(int s) {
  for(auto w : scc_adj[s])
    if(to_one[w])
      to_one[s] = max(to_one[s],sum[s] + to_one[w]);
}

int get_ans(int v) {
  for(auto w : scc_jda[v])
    dp[v] = max(dp[v],to_one[w]);
  for(auto w : scc_adj[v])
    dp[v] = max(dp[v],dp[w]);
  if(dp[v]) dp[v] += sum[v];
  return dp[v];
}

int get_A(int s) {
  int ans = sum[s];
  for(auto w : scc_adj[s])
    ans = max(dp[w],ans);
  for(auto w : scc_jda[s])
    ans = max(ans, to_one[w]);
  return ans;
}

int main() {
#ifndef Atrin
  freopen("grass.in","rt",stdin);
  freopen("grass.out","wt",stdout);
#endif
  int n,m;cin >> n >> m;
  for(int i = 0;i<m;i++) {
    int x,y;cin >> x >> y;
    adj[x].push_back(y);
    jda[y].push_back(x);
  }
  for(int i = 1;i<=n;i++)
    if(!mark[i]) create_topo(i);
  reverse(topo.begin(),topo.end());
  int I = 0;
  vector<int> topo_scc;
  for(auto w : topo)
    if(mark[w]) SCC(w,++I),topo_scc.push_back(I);;
  for(auto w : topo)
    if(!mark[w]) sum_scc(w);
  reverse(topo_scc.begin(),topo_scc.end());
  to_one[scc[1]] = sum[scc[1]];
  for(auto w : topo_scc) if(w != scc[1]) count(w);
  for(auto w : topo_scc) if(w != scc[1]) get_ans(w);
  cout << get_A(scc[1]) << endl;
}
