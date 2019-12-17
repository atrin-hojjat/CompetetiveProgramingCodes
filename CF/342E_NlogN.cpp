#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const int LOGMAXN = 20;
const int inf = 1e9+7;
vector<int> tree[MAXN];
int par[MAXN][LOGMAXN];
int dis[MAXN][LOGMAXN];
int neas[MAXN];
int sz[MAXN];
bool mark[MAXN];

int size_dfs(int v,int p = 0) {
  sz[v] = 1;
  for(auto u : tree[v])
    if(!mark[u] && u!=p)
      sz[v] += size_dfs(u,v);
  return sz[v];
}

int get_centroid(int v,int t,int p = 0) {
  for(auto u : tree[v])
    if(!mark[u] && u!=p && sz[u]>t) 
      return get_centroid(u,t,v);
  return v;
}

void dis_dfs(int v,int cent,int layer,int p = -1,int d = 0) {
  dis[v][layer] = d;
  par[v][layer] = cent;
  for(auto w : tree[v])
    if(!mark[w] && w!=p)
      dis_dfs(w,cent,layer,v,d+1);
}

void decompose(int v = 1,int layer = 0) {
  int cent = get_centroid(v,size_dfs(v)/2);
  dis_dfs(cent,cent,layer);
  mark[cent] = true;
  neas[cent] = inf;
  for(auto w : tree[cent])
    if(!mark[w])
      decompose(w,layer+1);
}

void update(int v) {
  neas[v] = 0;
  for(int l = 0;par[v][l] != v && l<LOGMAXN;l++)
    neas[par[v][l]] = min(neas[par[v][l]],dis[v][l]);
}

int get(int v) {
  int ans = neas[v];
  for(int l = 0;par[v][l] != v && l<LOGMAXN;l++) 
    ans = min(ans, neas[par[v][l]]+ dis[v][l]);
  return ans;
}

int main() {
  int n,m;cin >> n >> m;
  for(int i = 1 ;i<n;i++) {
    int x,y;cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  decompose();
  update(1);
  while(m--) {
    int a,b;cin >> a >> b;
    if(a-1)
      cout << get(b) << endl;
    else 
      update(b);
  }
  return 0;
}
