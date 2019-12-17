#include <bits/stdc++.h>
using namespace std;

const int MAXN = 750;
string str[MAXN];
namespace PosetSolver {
  vector<int> eds[2][MAXN];
  int match[2][MAXN];
  int M[2][MAXN];
  bool mark[MAXN];
  bool in[2][MAXN];
  
  bool dfs(int v) {
    mark[v] = true;
    for(auto w : eds[0][v]) 
      if( match[1][w] == -1 || ( mark[match[1][w]] == false && dfs(match[1][w]) ) ) {
        match[0][v] = w;
        match[1][w] = v;
        return true;
      }
    return false;
  }

  int MaximumMatching(int n) {
    int ans = 0;
    memset(match,-1,sizeof match);
    for(;;) {
      bool done = true;
      memset(mark,0,sizeof mark);
      for(int i = 0;i<n;i++)
        if(match[0][i] == -1 && mark[i] == 0 && dfs(i)) ans ++,done = false;
      if(done) break;
    }
    return ans;
  }

  vector<int> T;

  void dfs(int v,int s) {
    M[s][v] = 2;
    for(auto w : eds[s][v]) 
      if(!M[s][match[s^1][w]]) {
        M[s^1][w] = 1;
        dfs(match[s^1][w],s);
      }
  }

  vector<int> MaxAntichain(int n) {
    MaximumMatching(n);
    vector<int> ret;
    for(int i = 0;i<n;i++)
      for(int j = 0;j<2;j++)
        if(!M[j][i] && match[j][i] == -1) dfs(i,j);
    for(int i = 0;i<n;i++)
        if(!M[0][i])
          dfs(i,0);
    vector<int> rr;
    for(int i = 0;i<n;i++)
      if(M[0][i] == 2 && M[1][i] == 2) rr.push_back(i);
    return rr;
  }
};

const int MaxSz = 1e7 + 6.66;
const int MaxCh = 26;
int nx[MaxCh][MaxSz];
int par[MaxSz];
int Last;
int prv[MaxCh][MaxSz];
int ind[MaxSz];
int End[MAXN];
int revEnd[MaxSz];

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> str[i];
  for(int i = 0; i < n; i++) {
    int now = 0;
    for(auto x : str[i]) {
      if(nx[x - 'a'][now]) {
        now = nx[x - 'a'][now];
      } else {
        nx[x - 'a'][now] = ++Last;
        par[Last] = now;
        CH[Last] = x - 'a';
        now = Last;
      }
    }
    End[i] = now;
    revEnd[now] = i;
  }
  for(int i = 1; i <= Last; i++) {
    for(int j = 0; j < MaxCh; j++) {
      if(!nx[i][j]) continue;
      int N = nx[i][j];
      int c = (ind[N] = prv[i][j]);
      for(int k = 0; k < MaxCh; k++) {
          prv[N][k] = (nx[c][k] ? nx[c][k] : prv[c][k]);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    int x = End[i]; int y = ind[x];
    while(y) {
      if(revEnd[y])
        PosetSolver::eds[0][i].push_back(revEnd[y]),
          PosetSolver::eds[1][revEnd[y]].push_back(i);
      y = ind[y];
    }
  }
  // for(int i = 0;i<n;i++)
  // {
  //   for(auto S : szs) {
  //     if(S >= str[i].size()) continue;
  //     string ss = "";
  //     int j;
  //     for(j = 0;j<S;j++) ss += str[i][j];
  //     int tmp;
  //     do {
  //       if(strs.count(ss)) PosetSolver::eds[0][i].push_back(tmp = strs[ss]),PosetSolver::eds[1][tmp].push_back(i);
  //       ss += str[i][j++];
  //       ss.erase(0,1);
  //     } while( j < str[i].size());
  //     if(strs.count(ss)) PosetSolver::eds[0][i].push_back(tmp = strs[ss]),PosetSolver::eds[1][tmp].push_back(i);
  //   }
  // }
  vector<int> ans = PosetSolver::MaxAntichain(n);
  cout << ans.size() << endl;
  for(auto w : ans) cout << w+1 << " " ; cout << endl;
  return 0;
}
