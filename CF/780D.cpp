#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+6.66;
const int MAX = 1<<12;
const int O = 1<<11;
struct Team {
  string a,b;
  char name[2][3];

  Team() {
    a = "",b = "";
    for(int i = 0;i<2;i++)
      for(int j = 0;j<3;j++)
        name[i][j] = '\0';
  }

  Team(string a,string b) : a(a), b(b) {
    init ();
  }
/*
  char* operator [] (int n) {
    return &name[n][0];
  }*/

  void init() {
    for(int i = 0;i<3;i++) name[1][i] = name[0][i] = a[i];
    name[1][2] = b[0];
  }
} teams[MAXN];
vector<int> ed[MAX];
vector<int> rev[MAX];
vector<int> topo;
int scc[MAX];
int ans[MAX];
bool mark[MAX];

istream& operator>> (istream&x,Team&w) {
  x >> w.a >> w.b;
  w.init ();
  return x;
}

bool check_eq(char a[3],char b[3]) {
  for(int i = 0;i<3;i++)
    if(a[i] != b[i])
      return false;
  return true;
}

inline int other(int x,int w = 0) {
  if(w) return x;
  return x ^ O;
}

void add_condition(int a,int b = -1) {
  if(!~b) b = a;
  ed[other(a)].push_back(b);
  ed[other(b)].push_back(a);
  rev[a].push_back(other(b));
  rev[b].push_back(other(a));
}

void build(int n) {
  for(int i = 0;i<n;i++) {
    for(int j = 0;j<n;j++) {
      if(i==j) continue;
      if( check_eq(teams[i].name[0],teams[j].name[0]) ) 
        add_condition(i,other(j));
      for(int x = 0;x<2;x++)
        for(int y = 0;y<2;y++) 
          if( check_eq(teams[i].name[x],teams[j].name[y]) )
            add_condition(other(i,x),other(j,y));
    }
  }
}

void topo_dfs(int v) {
  if(mark[v]) return ;
  mark[v] = true;
  for(auto w : ed[v]) topo_dfs(w);
  topo.push_back(v);
}

void scc_dfs(int v,int I) {
  if(!mark[v]) return ;
  mark[v] = false;
  scc[v] = I;
  for(auto u : rev[v]) scc_dfs(u,I);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n; cin >> n;
  for(int i = 0;i<n;i++) cin >> teams[i];
  build(n);
  for(int i = 0;i<n;i++) {
    if(!mark[i]) topo_dfs(i);
    if(!mark[other(i)]) topo_dfs(other(i));
  }
  reverse(topo.begin(),topo.end());
  int I = 0;
  for(auto w : topo) if(mark[w]) scc_dfs(w,I++);
  reverse(topo.begin(),topo.end());
  for(int i = 0;i<n;i++) 
    if(scc[i] == scc[other(i)]) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  for(auto w : topo) {
    if(ans[scc[w]]) continue;
    ans[scc[w]] = 1;
    ans[scc[other(w)]] = 2;
  }
  for(int i = 0;i<n;i++,cout << endl)
    for(int j = 0;j<3;j++) 
      cout << teams[i].name[ans[scc[i]]>>1][j];
  return 0;
}
