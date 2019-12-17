#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+6.66;
vector<int> clause[MAXN];
int mark[MAXN];
vector<int> occu[MAXN<<1];
int cnt[MAXN<<1];
int dif[MAXN<<1];
int ans[MAXN];

void remove_ones(int n,int m) {
  auto CMP = [] (int x,int y) {
    x<<=1,y<<=1;
#define TT(x) (x>0)
    return ( TT(cnt[x]) + TT(cnt[x^1]) == TT(cnt[y]) + TT(cnt[y^1]) ? x < y 
        : TT(cnt[x]) + TT(cnt[x^1]) < TT(cnt[y]) + TT(cnt[y^1]) ) ;
#undef TT
  };
  set<int,decltype(CMP)> ss(CMP);
  for(int i = 0;i<n;i++) for(auto w : clause[i]) cnt[w]++;
  for(int i = 0;i<n;i++) for(auto w : clause[i]) occu[w].push_back(i);
  for(int i = 1;i<=m;i++) ss.insert(i);
  while(ss.size()) {
    int x = *ss.begin();
    ss.erase(ss.begin());
    if(cnt[x<<1] && cnt[x<<1|1]) break;
    
    if(cnt[x<<1]) ans[x] = 2;
    else ans[x] = 1;

    for(int i = 0 ;i<2;i++)
      for(auto w : occu[x<<1|i])
        if(!mark[w]) {
          mark[w] = 4;
          for(auto z : clause[w])
          {
            if( (z>>1) == x || ans[z>>1]) continue;
            ss.erase(ss.find(z>>1));
            cnt[z] --;
            ss.insert(z>>1);
          }
        }
  }
}

int find_cycle(int v,vector<int>& vv,int in = -1) {
  mark[v] = 1;
  for(auto w : clause[v]) {
    if(w == in || ans[w>>1]) continue;
    int u = dif[w];
    if(!~u) continue;
    if(mark[u] == 0) {
      int zz;
      if(~( zz = find_cycle(u,vv,w^1) ) ) {
        if(zz&1)vv.push_back(v),ans[w>>1] = (w&1 ? 1 : 2); 
        return zz ^ ( zz == (v<<1)); }
    } else if ( mark[u] == 1 )  { ans[w>>1] = (w&1? 1 : 2) ; vv.push_back(v); return (u<<1|1); }
  }
  mark[v] = 2;
  return -1;
}

bool solve_cnf(int n,int m) {
  remove_ones(n,m);
  for(int i = 0;i<n;i++) {
    if(mark[i]) continue;
    vector<int> cycle;
    find_cycle(i,cycle);
    if(!cycle.size()) { cout << "NO" << endl; return false; };
    queue<int> qq ;
    for(auto w : cycle) qq.push(w),mark[w] = 3;
    while(qq.size()) {
      int v = qq.front();
      qq.pop();
      for(auto w : clause[v]) {
        int u= dif[w];
        if(!~u) continue;
        if(mark[u] > 2) continue;
        mark[u] = 3;
        qq.push(u);
        ans[w>>1] = (w & 1 ? 2 : 1) ;
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,m; cin >> n >> m;
  for(int i = 0;i<n;i++) {
    int x;cin >> x;
    while(x--) {
      int w;cin >> w;
      int zz = ( abs(w) << 1 ) + (w<0);
      dif[zz^1] = i;
      clause[i].push_back(zz);
    }
  }
  if(solve_cnf(n,m)) {
    cout << "YES" << endl;
    for(int i = 1;i<=m;i++)
      cout << ((1+ans[i])%2) ;
    cout << endl;
  }
  return 0;
}
