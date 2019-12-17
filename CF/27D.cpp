#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100+10+1;
vector<int> g[MAXN*2];
vector<int> topol;
pair<int,int> roads[MAXN];
int scc[2*MAXN];
int col[2*MAXN];

inline bool between(pair<int,int> x,int y) {
  return y>x.first && y<x.second;
}

inline bool equal(pair<int,int> i,pair<int,int> j) {
  if(i.first == j.first || 
      i.first == j.second ||
      i.second == j.first ||
      i.second == j.second ) return true;
  return false;
}

inline int other(int x) {
  return (x+MAXN) % (2*MAXN);
}

void add_edge(int i,int j) {
  g[other(i)].push_back(j);
  g[other(j)].push_back(i);
  g[i].push_back(other(j));
  g[j].push_back(other(i));
}

void build(int n,int m) {
  for(int i = 0;i<m;i++) {
    cin >> roads[i].first >> roads[i].second;
    if(roads[i].first > roads[i].second) swap(roads[i].first,roads[i].second);
    for(int j = 0;j<i;j++) {
      if( !equal(roads[i],roads[j]) && 
          between(roads[i],roads[j].first) != between(roads[i],roads[j].second) )
        add_edge(i,j);
    }
  }
}

bool check(int n) {
  for(int i = 0;i<n;i++)
    if(scc[i]==scc[other(i)])
      return false;
  return true;
}

void dfs_topol(int v,int I) {
  scc[v] = I;
  for(auto w : g[v])
    if(!scc[w])
      dfs_topol(w,I);
  topol.push_back(v);
}

int main() {
  int n,m;cin >> n >> m;
  build(n,m);
  int I = 0;
  for(int i = 0;i<m;i++) {
    if(!scc[i])
      dfs_topol(i,++I);
    if(!scc[other(i)])
      dfs_topol(other(i),++I);
  }
  if(!check(m)) {
    cout << "Impossible" << endl;
    return 0;
  }
  for(auto w : topol) {
    if(col[scc[w]]) continue;
    col[scc[w]] = 1;
    col[scc[other(w)]] = 2;
  }
  for(int i = 0;i<m;i++)
    cout << (col[scc[i]]==1?"o" : "i" ) ;
  cout << endl;
  return 0;
}
