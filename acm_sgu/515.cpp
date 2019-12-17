#include <bits/stdc++.h>

#define LOG cout << __LINE__ << endl;

using namespace std;

const int MAXN = 1e5+6.66;
const int inf = 2e9+6.66;
struct EDGE { 
  int x,w,t; 
  EDGE(int x,int w,int t) : x(x) , w(w),t(t) {};
};
vector<EDGE> g[MAXN];
bool mark[MAXN];
bool googool[MAXN];
int d[MAXN];
int par[MAXN];
pair<int,int> dp[MAXN];
vector<int> topo;

int get_start(int r) {
  fill(d,d+MAXN,inf);
//  memset(d,63,sizeof d);
  fill(mark,mark+MAXN,0);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> s;
  s.push({0,r});
  pair<int,int> mx = {0,r};
  d[r] = 0;
  while(s.size()) {
    pair<int,int> w = s.top();s.pop();
//    d[w.second] = min(d[w.second],w.first);
    if(mark[w.second]) continue;
    if(googool[w.second]) mx = max(mx,w);
    mark[w.second] = true;
    for(auto z : g[w.second])
      if(d[z.x] > w.first + z.w) {
        d[z.x] = w.first + z.w;
        s.push({d[z.x],z.x});
      }
  }
  return mx.second;
}

void generate_path(int s,int n) {
  get_start(s);
  vector<int> vv;
  for(int i = 1;i<=n;i++) vv.push_back(i);
  for(int i = 0;i<MAXN;i++) dp[i] = {-1,-1};
  sort(vv.begin(),vv.end(),[](int x,int y) { return (d[x]==d[y] ? googool[x] : d[x] > d[y] ); });
  int lst = inf;
  for(auto w : vv) {
    pair<int,int> ok = {-1,-1};
    for(auto c : g[w]) {
      if(d[c.x] - c.w == d[w] && d[c.x] <= lst&& ~dp[c.x].first)
        ok = {c.t,c.x};
    }
    if(~ok.first)
      dp[w] = ok;
    if(googool[w]) {
      if(lst == inf) dp[w] = {0,MAXN};
      lst = d[w];
    }
  }
  vector<int> ss;
  pair<int,int> w = dp[s];
  while(w.first>0) {
    ss.push_back(w.first);
    w = dp[w.second];
  }
  cout << ss.size() << endl;
  for(auto w : ss) cout << w << " " ;cout << endl;
}

int main() {
#ifndef Atrin
//  freopen("recover.in","rt",stdin);
//  freopen("recover.out","wt",stdout);
#endif
  int n,m;cin >> n >> m;
  for(int i = 0;i<m;i++) {
    int x,y,z;cin >> x >> y >> z;
    g[x].push_back(EDGE(y,z,i+1));
    g[y].push_back(EDGE(x,z,i+1));
  }
  int k;cin >> k;
  int zx = -1;
  for(int i = 0;i<k;i++) {
    int x;cin >> x;
    zx = x;
    googool[x] = true;
  }
  generate_path(get_start(zx),n);
  return 0;
}
