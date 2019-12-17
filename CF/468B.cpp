#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
vector<int> ed[MAXN*2];
vector<int> ed_rev[MAXN*2];
int scc[MAXN*2];
int ans[MAXN*2];
int arr[MAXN];
bool mark[MAXN*2];
map<int,int> pos;
vector<int> topol;

inline int other(int a) {
  return (a+MAXN)%(2*MAXN);
}

void add_condition(int a,int b) {
  ed[other(a)].push_back(b);
  ed[other(b)].push_back(a);
  ed_rev[b].push_back(other(a));
  ed_rev[a].push_back(other(b));
}

void build(int n,int a,int b) {
  for(int i = 0;i<n;i++) {
    int x = pos.count(a-arr[i]),y = pos.count(b-arr[i]);
    if( x + y == 0 ) {
      cout << "NO" << endl;
      exit(0);
    }
    if(x + y == 2) {
      add_condition(pos[a-arr[i]],other(pos[b-arr[i]]));
      add_condition(other(pos[a-arr[i]]),pos[b-arr[i]]);
      add_condition(other(i),pos[a-arr[i]]);
      add_condition(i,other(pos[b-arr[i]]));
    } else if( x ) {
      add_condition(pos[a-arr[i]],pos[a-arr[i]]);
      add_condition(i,i);
    } else if( y ) {
      add_condition(other(pos[b-arr[i]]),other(pos[b-arr[i]]));
      add_condition(other(i),other(i));
    }
  }
}

void dfs(int v) {
  if( mark[v] ) return ;
  mark[v] = true;
  for(auto w : ed[v]) dfs(w);
  topol.push_back(v);
}

void scc_dfs(int v,int I) {
  if( !mark[v] ) return ;
  mark[v] = false;
  scc[v] = I;
  for(auto w : ed_rev[v]) scc_dfs(w,I);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,A,B;cin >> n >> A >> B;
  for(int i = 0;i<n;i++) cin >> arr[i];
  for(int i = 0;i<n;i++) pos[arr[i]] = i;
  build(n,A,B);
  for(int i = 0;i<n;i++) {
    if(!mark[i]) dfs(i);
    if(!mark[other(i)]) dfs(other(i));
  }
  reverse(topol.begin(),topol.end());
  int I = 0;
  for(auto w : topol)
    if(mark[w])
      scc_dfs(w,++I);
  for(int i = 0;i<n;i++) {
    if(scc[i] == scc[other(i)]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  for(auto w : topol) {
    if(!ans[scc[w]]) ans[scc[w]] = 2;
    if(!ans[scc[other(w)]]) ans[scc[other(w)]] = 1;
  }
  cout << "YES" << endl;
  for(int i = 0;i<n;i++) 
    cout << (1+ans[scc[i]])%2 << " ";
  cout << endl;
  return 0;
}
