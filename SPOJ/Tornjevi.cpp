#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100+10+1;
const int MAX = (1<<18) + 6.66;
const int dir[4] = {0,1<<17|1<<16,1<<16,1<<17};
string tab[MAXN];
vector<pair<int,int>> wdc[MAX];
vector<int> ed[MAX];
vector<int> rev[MAX];
vector<int> topo;
bool mark[MAX];
int scc[MAX];
int ans[MAX];

inline int get(int i,int j) {
  return i*MAXN + j;
}

inline int other(int i) {
  return i ^ ( (1<<17) | (1<<16) );
}

void add_condition(int i,int j = -1) {
  if(!~j) j = i;
  ed[other(i)].push_back(j);
  if(i!=j)ed[other(j)].push_back(i);
  rev[i].push_back(other(j));
  if(i!=j)rev[j].push_back(other(i));
}

void build(int n,int m) {
  struct FOR {
   int st1,et1,ch1;
   int st2,et2,ch2;

   FOR(int st1,int et1,int ch1,int st2,int et2,int ch2) :
     st1(st1),et1(et1),ch1(ch1),st2(st2),et2(et2),ch2(ch2) {};
  } fors[4] = {{0,n,1,0,m,1},{0,n,1,m-1,-1,-1},{0,m,1,n-1,-1,-1},{0,m,1,0,n,1}};
  for(int k = 0;k<4;k++) {
    for(int i = fors[k].st1;i!=fors[k].et1;i+=fors[k].ch1) {
      int prv = -1;
      bool nex = false;
      vector<int> nxx;
      for(int j = fors[k].st2;j!=fors[k].et2;j+= fors[k].ch2) {
        if(k > 1) swap(i,j);
        switch(tab[i][j]) {
          case '#':
            prv = -1;
            nex = false;
            nxx.clear();
            break;
          case 'n':
            nex = true;
            nxx.push_back(get(i,j));
            break;
          case 'T':
            if(~prv) add_condition(get(i,j)|dir[k^1]);
            if(nex) {
             for(auto w : nxx) {
               wdc[w].push_back({get(i,j),k});
             }
             nex = false;
             nxx.clear();
            }
           prv = 0;
            break;
        }
        if(k > 1) swap(i,j);
      }
    }
  }
  for(int i = 0;i<n;i++) {
    for(int j = 0;j<m;j++) {
      if(tab[i][j] != 'n') continue;
      int upd1,upd2;
      int ok1 = 0,ok2 = 0;
      for(auto www : wdc[get(i,j)]) {
        int a,b;tie(a,b) = www;
        if(b<2) ok1 ^=1,upd1 = a | dir[b];
        else ok2 ^=1,upd2 = a|dir[b];
      }
      if(ok1 && ok2) {
        add_condition(upd1,upd2);
      } else if (ok1) {
        add_condition(upd1);
      } else if( ok2) {
        add_condition(upd2);
      } else {
        assert(false);
        exit(0);
      }
    }
  }
}

void topo_dfs(int i) {
  mark[i] = true;
  for(auto w : ed[i])
    if(!mark[w])
      topo_dfs(w);
  topo.push_back(i);
}

void scc_dfs(int i,int I) {
  mark[i] = false;
  scc[i] = I;
  for(auto w : rev[i])
    if(mark[w])
      scc_dfs(w,I);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,m;cin >> n >> m;
  for(int i = 0;i<n;i++) cin >> tab[i];
  build(n,m);
  for(int i = 0;i<n;i++)
    for(int j = 0;j<m;j++)
      for(int k = 0;k<4;k++)
        if(!mark[get(i,j)|dir[k]])
          topo_dfs(get(i,j)|dir[k]);
  reverse(topo.begin(),topo.end());
  int I = 0;
  for(auto w : topo)
    if(mark[w])
      scc_dfs(w,++I);
  for(auto w : topo) {
    if(scc[w] == scc[other(w)]) {
      assert(false);
      exit(0);
    }
  }
  for(auto w : topo) {
    if(ans[scc[w]]) continue;
    ans[scc[w]] = 2;
    ans[scc[other(w)]] = 1;
  }
  for(int i = 0;i<n;i++,cout << endl) {
    for(int j = 0;j<m;j++) {

      if(tab[i][j] == 'T') {
        int anss = 0;
        if(ans[scc[get(i,j)|dir[1]]]==1) {
          if(ans[scc[get(i,j)|dir[2]]]==1)
            anss = 2;
          else 
            anss = 3;
        } else {
          if(ans[scc[get(i,j)|dir[2]]]==1)
            anss = 1;
          else 
            anss = 4;
        }
        cout << anss;
      } else cout << tab[i][j];
    }
  }
  return 0;
}
