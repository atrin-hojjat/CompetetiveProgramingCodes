#include <bits/stdc++.h>
using namespace std;

const int MAXN = 56;

class BigO {
public :
  BigO () {
#ifdef Atrin
#endif
    memset(ans,0,sizeof ans);
    memset(mark,0,sizeof mark);
    memset(scc,-1,sizeof scc);
    memset(sz,0,sizeof sz);
  }

  int minK(vector<string>&in) {
    generate_graph(in);
    SCC();
    return ANS();
  }

private :
  vector<int> ed[MAXN];
  vector<int> rev[MAXN];
  vector<int> topo;
  int scc[MAXN];
  int sz[MAXN];
  bool mark[MAXN];
  int ans[MAXN];
  int N = -1;

  void topo_dfs(int v) {
    mark[v] = true;
    for(auto w : ed[v]) if(!mark[w]) topo_dfs(w);
    topo.push_back(v);
  }

  void scc_dfs(int v,int I ) {
    mark[v] = false;
    scc[v] = I;
    for(auto w : rev[v]) if(mark[w]) scc_dfs(w,I);
  }

  void generate_graph(vector<string>&in) {
    N = in.size();
    for(int i = 0;i<in.size();i++)
      for(int j = 0;j<in.size();j++)
        if(in[i][j] == 'Y') ed[i].push_back(j),rev[j].push_back(i);
  }

  void SCC() {
    if(!~N) assert(false);
    for(int i = 0;i<N;i++) 
      if(!mark[i]) topo_dfs(i);
    reverse(topo.begin(),topo.end());
    for(auto w : topo) if(mark[w]) scc_dfs(w,w);
    for(auto w : topo) sz[scc[w]] ++;
  }

  bool NP() {
    for(auto w : topo) {
      int cnt = 0;
      for(auto z : ed[w]) cnt += (scc[z] == scc[w]);
      if(cnt>1) return true;
    }
    return false;
  }

  int ANS() {
    if(NP()) return -1;
    reverse(topo.begin(),topo.end());
    int RET = 0;
    for(auto w : topo) {
      ans[scc[w]] = max(ans[scc[w]],0);
      for(auto z : ed[w])
        if(scc[z] != scc[w]) ans[scc[w]] = max(ans[scc[z]] + (sz[scc[w]] > 1),ans[scc[w]]);
      RET = max(RET, ans[scc[w]]);
    }
    return RET;
  }
};

#ifdef Atrin
int main() {
  int n;cin >> n;
  vector<string> vv;
  for(int i = 0;i<n;i++) {
    string str;cin >> str;
    vv.push_back(str);
  }
  BigO *ww = new BigO();
  int ans = ww->minK(vv);
  cout << ans << endl;
  return 0;
}
#endif
