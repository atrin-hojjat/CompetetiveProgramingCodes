#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+6.66;
const int inf = 36501;
namespace Graph {
  struct Edge {
    int from,to;
    int prv;//,vrp;

    Edge() {
      from = to = 0;
      prv = /*vrp =*/ -1;
    }
    
    Edge(int from,int to,int prv/*,int vrp*/) : from(from),to(to),prv(prv)/*,vrp(vrp) */{ }
  } eds[MAXN];

  int scc[MAXN],I = 0;
  int POS = 0;
//  vector<int> topol;
  int topol[MAXN];
  int head[MAXN];
//  int rhead[MAXN];
  int pos = 0;
  function<void(int,int)> dfs,sfd;
  void loop(int ,function<void(int,int)>&);
  void rev_loop(int ,function<void(int,int)>&); 

  void init() {
    memset (head,-1,sizeof head);
//    memset (rhead,-1,sizeof rhead);
    dfs = [&](int v,int p) -> void {
      if(scc[v]) return ;
      scc[v] = 1;
      Graph::loop(v,dfs);
      topol[POS++] = v;
    };
    sfd = [&](int v,int p) -> void {
      if(scc[v]) return ;
      scc[v] = I;
      Graph::rev_loop(v,sfd);
    };
  }

  void add_edge(int v,int u) {
    eds[pos] = {v,u,head[v]/*,rhead[u]*/};
    head[v] = pos;
    /*rhead[u] = pos;*/
    pos++;
  }

  void reverse_edges() {
    memset(head,-1,sizeof head);
    for(int i = 0;i<pos;i++)
    {
      eds[i].prv = head[eds[i].to];
      head[eds[i].to] = i;
      swap(eds[i].to,eds[i].from);
    }
  }

  void loop(int v,function<void(int,int)>&f) {
    for(int x = head[v];~x;x = eds[x].prv) f(eds[x].to,v);
  }

  void rev_loop(int v,function<void(int,int)>&f) {
    for(int x = head[v];~x;x = eds[x].prv) f(eds[x].to,v);
//    for(int x = rhead[v];~x;x = eds[x].vrp) f(eds[x].from,v);
  }

  void fill_topol(int n) {
    for(int i = 0;i<n;i++) 
      dfs(i,i);
//    reverse(topol.begin(),topol.end());
    reverse(topol,topol+POS);
  }

  void fill_scc() {
    reverse_edges();
    I = 1;
    memset(scc,0,sizeof scc);
    for(int i = 0,w = topol[i];i<POS;w = topol[++i])
//    for(auto w : topol)
      sfd(w,w),I++;
    reverse_edges();
  }
};
int dp[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,m;cin >> n >> m;
  Graph::init();
  for(int i = 0;i<m;i++) {
    int x,y;cin >> x >> y;
    x--,y--;
    Graph::add_edge(x,y);
  }
  Graph::fill_topol(n+1);
  Graph::fill_scc();
  reverse(Graph::topol,Graph::topol+Graph::POS);
//  reverse(Graph::topol.begin(),Graph::topol.end());
  dp[Graph::scc[n]] = 1;
  int XX = 0;
  function<void(int,int)> dp_filler = [n,&XX](int v,int p) {
    int a = Graph::scc[p],b = Graph::scc[v];
    if(dp[a] >= inf) return ;
    if(XX) {
      if(b == a) dp[a] = inf;
      else
        dp[a] += dp[b];
  //    cout << v << " " << p << " "<< b << " " << a << " " << dp[b] << " " << dp[b] << endl;
      dp[a] = min(dp[a],inf);
    } else 
      dp[a] |= dp[b];
  };
  for(int i = 0,w = Graph::topol[i];i<Graph::POS;w = Graph::topol[++i]) {
//  for(auto i : Graph::topol)
    Graph::loop(w,dp_filler);
    if(!dp[Graph::scc[w]]) Graph::topol[i] = -1;
  }
  XX = 1;
  memset(dp,0,sizeof dp);
  dp[Graph::scc[n]] = 1;
  for(int i = 0,w = Graph::topol[i];i<Graph::POS;w = Graph::topol[++i])
//  for(auto i : Graph::topol)
    if(~w) Graph::loop(w,dp_filler);
  int ans = 0,mx = 0;
  for(int i = 0;i<n;i++) 
    if(mx < dp[Graph::scc[i]]) 
      mx = dp[Graph::scc[i]],ans = 1;
    else if(mx == dp[Graph::scc[i]]) ans++;
  if(mx>=inf) cout << "zawsze" << endl;
  else cout << mx << endl;
  cout << ans << endl;
  for(int i = 0;i<n;i++)
    if(dp[Graph::scc[i]] == mx)
      cout << 1+i << " ";
  cout << endl;
  return 0;
}
