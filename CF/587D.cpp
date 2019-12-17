#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5e4 + 6.66;
const int Max = MaxN * 8;
struct Edge {
  int b, e, c, t;
};
Edge edges[MaxN];
vector<int> eds[Max];
vector<int> revs[Max];
bool mark[Max];
int scc[Max];
int prv[MaxN];
vector<int> topo;
map<int, int> prv_col[MaxN];
int ans[Max];

istream& operator>>(istream&x, Edge&y) {
  x >> y.b >> y.e >> y.c >> y.t;
  return x;
}

int Get(int x) { return x <<3; }
int Not(int x) { return x ^ 1; }
int Pr1(int x) { return x ^ 2; }
int Pr2(int x) { return x ^ 4; }
int PG1(int x) { return Pr1(Get(x)); }
int PG2(int x) { return Pr2(Get(x)); }

void add_edge(int v, int u) {
  eds[v].push_back(u);
  revs[u].push_back(v);
}

void add_clause(int v, int u = -1) {
  if(u == -1) u = v;
  else add_edge(Not(v), u);
  add_edge(Not(u), v);
}

void add_par_clause(int px, int ss, int v) {
  if(~prv[px]) {
    add_clause(Not(prv[px]), Not(v));
    add_clause(Not(prv[px]), ss);
  }
  add_clause(Not(v), ss);
  prv[px] = ss;
}

void build(int n, int m, int k) {
  for(int i = 0; i < m; i++) {
    add_par_clause(edges[i].b, PG1(i), Get(i));
    add_par_clause(edges[i].e, PG2(i), Get(i));
    if(prv_col[edges[i].b].count(edges[i].c)) add_clause(Get(i), prv_col[edges[i].b][edges[i].c]);
    if(prv_col[edges[i].e].count(edges[i].c)) add_clause(Get(i), prv_col[edges[i].e][edges[i].c]);
    prv_col[edges[i].b][edges[i].c] = prv_col[edges[i].e][edges[i].c] = Get(i);
    if(edges[i].t > k)
      add_clause(Not(Get(i)));
  }
}

void clear() {
  for(int i = 0; i < Max; i++) eds[i].clear();
  for(int i = 0; i < Max; i++) revs[i].clear();
  for(int i = 0; i < MaxN; i++) prv_col[i].clear();
  topo.clear();
  memset(prv, -1, sizeof prv);
  memset(mark, 0, sizeof mark);
  memset(scc, 0, sizeof scc);
}

void topo_dfs(int v) {
  if(mark[v]) return ;
  mark[v] = true;
  for(auto x : eds[v]) topo_dfs(x);
  topo.push_back(v);
}

void scc_dfs(int v, int w) {
  if(!mark[v]) return ;
  scc[v] = w;
  mark[v] = false;
  for(auto x : revs[v]) scc_dfs(x, w);
}

bool solve(int n, int m, int k) {
  clear();
  build(n, m, k);
  for(int i = 0; i < m; i++) 
    for(int j = Get(i); j < Get(i + 1); j++)
      if(!mark[j]) topo_dfs(j);
  reverse(topo.begin(), topo.end());
  int I = 0;
  for(auto c : topo) if(mark[c]) scc_dfs(c, I++);
  for(auto c : topo) 
    if(scc[c] == scc[Not(c)]) return false;
  return true;
}

void generate(int n, int m, int k) {
  if(!solve(n, m, k)) {
    cout << "No" << endl;
    return ;
  }
  for(auto x : topo) {
    if(mark[scc[x]]) continue;
    mark[scc[x]] = mark[scc[Not(x)]] = true;
    ans[scc[x]] = 0;
    ans[scc[Not(x)]] = 1;
  }
  vector<int> Ans;
  for(int i = 0; i < m; i++)
    if(ans[scc[Get(i)]]) Ans.push_back(i + 1);
  printf("Yes\n%d %lu\n", k, Ans.size());
  for(auto w : Ans) printf("%d%c", w, " \n"[w == Ans.back()]);
}

bool Ok(int n, int m) {
  for(int i = 0; i < m; i++)
    prv_col[edges[i].b][edges[i].c]++, prv_col[edges[i].e][edges[i].c]++;
  for(int i = 0; i < MaxN; i++)
    for(auto x : prv_col[i])
      if(x.second > 2) return false;
  return true;
}

int main() {
  int n, m; scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
    scanf("%d %d %d %d", &edges[i].b, &edges[i].e, &edges[i].c, &edges[i].t);
  if(!Ok(n, m)) {
    cout << "No" << endl;
    return 0;
  }
  int l = 0, r = 1e9 + 7;
  while(l < r) {
    int mid = l + (r - l) / 2;
    if(solve(n, m, mid)) r = mid;
    else l = mid + 1;
  }
  generate(n, m, l);
  return 0;
}
