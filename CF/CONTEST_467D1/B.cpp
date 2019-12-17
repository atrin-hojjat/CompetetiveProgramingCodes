#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
vector<int> ed[MAXN];
vector<int> rev[MAXN];
vector<int> topo;
int scc[MAXN];
int col[MAXN];
int sz[MAXN];
bool mark[MAXN];
int root;
struct POS {
  bool x;
  int nx = -1;
  int nn = -1;
  POS() {
    x = false;
    nx = nn = -1;
  }
  POS(bool x,int nn) : x(x),nn(nn) {nx = -1;};

  void operator|=(POS w) {
    if(x) return ;
    if(w.x) {
      x = true;
      nx = w.nn;
    }
  }
};
bool CCC[MAXN];
bool draw[MAXN];
POS win[MAXN];
bool odd[MAXN];
POS lose[MAXN];

void topo_dfs(int v) {
  if(mark[v]) return ;
  mark[v] = true;
  for(auto w : ed[v]) topo_dfs(w);
  topo.push_back(v);
}

void scc_dfs(int v,int I ) {
  if(!mark[v]) return ;
  mark[v] = false;
  scc[v] = I;
  sz[I] ++;
  for(auto w : rev[v]) scc_dfs(w,I);
}

bool check_odd(int v,int c = 1) {
  if(col[v]) return false;
  col[v] = c;
  c ^= 1;c++;
  for(auto w : ed[v])
    if(scc[w] == scc[v]) {
      if(col[w] && col[v] == col[w]) return true;
      if(check_odd(w,c)) return true;
    }
  return false;
}

void dfs_ans(int v) {
  if(mark[v]) return;
  mark[v] = true;
  for(auto w : ed[v]) {
    if(scc[w]!=scc[v]) continue;
    dfs_ans(w);
    win[v] |= lose[w],lose[v] |= win[w];
  }
}

bool path_to_root(int v) {
  if(v==root) return true;
  if(CCC[v]) return false;
  CCC[v] = true;
  for(auto w : ed[v]) 
  {
    if(path_to_root(w)) {cout << v+1 << " " ;return true;}
  }
  return false;
}

bool check_odd_print(int v,int c = 1) {
  if(col[v]) return false;
  col[v] = c;
  c ^= 1;c++;
  for(auto w : ed[v])
    if(scc[w] == scc[v]) {
      if(col[w] && col[v] == col[w]) {cout << w+1 << " " ;return true;}
      if(check_odd(w,c)) {cout << w+1 << " " ;return true;}
    }
  return false;
}

int main() {
  int n,m;cin >> n >> m;
  for(int i = 0;i<n;i++) {
    int k;cin >> k;
    while(k--) {
      int x;cin >> x;
      x--;
      ed[i].push_back(x);
      rev[x].push_back(i);
    }
  }
  int st;cin >> st;
  for(int i = 0;i<n;i++) topo_dfs(i);
  reverse(topo.begin(),topo.end());
  int I = 0;
  for(int i : topo) if(mark[i]) scc_dfs(i,i);
  for(auto w : topo) if(!col[w]) odd[scc[w]] = check_odd(w);
  for(int i = 0;i<MAXN;i++) lose[i] = win[i] = POS(false,i);
  for(auto w : topo) {
    if(sz[scc[w]] == 1 && ed[w].size() == 0) lose[scc[w]] = POS(true,w);
    if(sz[scc[w]] > 1) draw[scc[w]] = true;
  }
  reverse(topo.begin(),topo.end()) ;
  for(auto i : topo) {
    for(auto w : ed[i])
      if(scc[w] != scc[i])  
        draw[scc[i]] |= draw[scc[w]];
    for(auto w : ed[i])
      if(scc[w] != scc[i])
      {
        if(odd[scc[w]]) win[i] |= lose[scc[w]],lose[i] |= win[scc[w]];
        else win[i] |= lose[w],lose[i] |= win[w];
      }
    if(scc[i] == i)
      dfs_ans(i);
  }
  st --;
  if(win[st].x) {
    cout << "Win" << endl;
    while(~st) {
      cout << st+1 << " " ;
      st = win[st].nx;
      if(st==-1) break;
      cout << st+1 << " " ;
      st = lose[st].nx;
    }
    cout << endl;
    return 0;
  } else if(lose[st].x) {
    vector<int> ans ;
    while(~st) {
      ans.push_back(st);
      st = win[st].nx;
      if(st==-1) break;
      ans.push_back(st);
      st = lose[st].nx;
    }
    memset(col,0,sizeof col);
    for(auto w : ans) {
      if(odd[scc[w]]) {
        cout << "Win" << endl;
        for(auto xx : ans) {
          if(xx==w) break;
          cout << xx+1 << " " ;
        }
        root = w;
        check_odd_print(w);
        bool ss = false;
        for(auto xx : ans) {
          if(xx!=w && ss == false) continue;
          ss == true;
          cout << xx + 1<< " ";
        }
        cout << endl;
        return 0;
      }
    }
  }
  if(draw[scc[st]]) cout << "Draw" << endl;
  else cout << "Lose" << endl;
}
