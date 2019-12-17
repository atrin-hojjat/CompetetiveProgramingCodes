#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+6.66;
const int MAX = 4*MAXN;
const int O = 1<<1;
//vector<int> ed[MAX];
//vector<int> rev[MAX];
int **contiries;
struct _edge_ {
  int s,e;
  int ps;//,pe;
  _edge_() { s = e = ps = /*pe =*/ -1; };
  _edge_(int s,int e,int ps,int pe) : s(s),e(e),ps(ps)/*,pe(pe)*/ {};
} eds[ 8 * MAXN ];
int TOP = 0,SZ = 0;
int top[MAX]/*,topr[MAX]*/;
int topo[MAX];
int scc[MAX];

inline int get_par(int x) {
  return x ^ 2; }
inline int other(int x) {
  return x ^ 1; }
inline int self(int x) { 
  return x << 2 ; };

void add_edge(int x,int y) {
//  ed[x].push_back(y);
//  rev[y].push_back(x);
  eds[TOP] = _edge_(x,y,top[x],top[y]);
  top[x] /*= topr[y] */= TOP++;
}

void add_condition(int x,int y) {
  add_edge(other(x),y);
  add_edge(other(y),x);
}

void build(int n,int m,int k) {
  for(int i = 0;i<m;i++) {
    int x,y;cin >> x >> y;
    add_condition(self(x),self(y));
  }
  contiries = new int*[k];
  for(int i = 0;i<k;i++) {
    int c;cin >> c;
    contiries[i] = new int[c+1]();
    contiries[i][0] = c;
    for(int j = 1;j<=c;j++) cin >> contiries[i][j];
  }
  for(int i = 0;i<k;i++) {
    int prv = -1;
    for(int j = 1;j<=contiries[i][0];j++) {
      int w = contiries[i][j]; 
      add_condition(other(self(w)),get_par(self(w)));
      if(~prv) {
        add_condition(other(get_par(self(prv))),other(self(w)));
        add_condition(other(get_par(self(prv))),get_par(self(w)));
      }
      prv = w;
    }
  }
}

void topo_dfs(int v) {
  scc[v] = 0;
//  mark[v] = true;
  int ZZ = top[v];
  while(~ZZ) {
    int w = eds[ZZ].e;
    if(scc[w]) topo_dfs(w);
    ZZ = eds[ZZ].ps;
  }
//  for(auto w : ed[v]) if(!mark[w]) topo_dfs(w);
  topo[SZ++] = v;
}

void scc_dfs(int v,int I) {
//  mark[v] = false;
  scc[v] = I;
//  for(auto w : rev[v]) if(mark[w]) scc_dfs(w,I);
  int ZZ = top[v];
  while(~ZZ) {
    int w = eds[ZZ].s;
    if(!scc[w]) scc_dfs(w,I);
    ZZ = eds[ZZ].ps;
  }
}

void switch_edges() {
  memset(top,-1,sizeof top);
  for(int i = 0;i<TOP;i++) {
    eds[i].ps = top[eds[i].e];
    top[eds[i].e] = i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,m,k;cin >> n >> m >> k;
  memset(top,-1,sizeof top);
//  memset(topr,-1,sizeof topr);
  build(n,m,k);
  memset(scc,63,sizeof scc);
  for(int i = 1;i<=n;i++) {
    if(scc[self(i)]) topo_dfs(self(i));
    if(scc[other(self(i))]) topo_dfs(other(self(i)));
    if(scc[get_par(self(i))]) topo_dfs(get_par(self(i)));
    if(scc[other(get_par(self(i)))]) topo_dfs(other(get_par(self(i))));
  }
  switch_edges();
  reverse(topo,topo + SZ);
  for(int i = 0;i<SZ;i++) if(!scc[topo[i]]) scc_dfs(topo[i],topo[i]);
  reverse(topo,topo + SZ);
  for(int i = 0;i<SZ;i++)
    if(scc[topo[i]] == scc[other(topo[i])]) {
      cout << "NIE" << endl;
      return 0;
    }
//  memset(ans,-1,sizeof ans);
  memset(top,0,sizeof top);
  cout << "TAK" << endl;
  for(int w = 0;w<SZ;w++) {
    int i = topo[w];
    if(top[scc[i]]) continue;
    top[scc[i]] = 1;
    top[scc[other(i)]] = 2;
  }
  for(int i = 0;i<k;i++) {
    bool ok = false;
    for(int j = 1;j<=contiries[i][0];j++)
      if(top[scc[self(contiries[i][j])]] == 1) { cout << contiries[i][j] << " " ;ok = true; break; };
    if(!ok) cout << contiries[i][1] << " ";
  }
  cout << endl;
  return 0;
}
