#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+6.66;
const int SQ = 557;
vector<int> tree[MAXN];
long long dp[MAXN][SQ];
long long heap[MAXN][SQ];
long long ans = 0;

void dfs_dp_sq(int v,int p = -1) {
  for( auto w : tree[v] ) if( w != p ) dfs_dp_sq(w,v);
  vector<pair<int,int>> vv;
  for(int i = 1;i<SQ;i++) {
    vv.clear();
    for(auto w : tree[v]) if( w!=p ) vv.push_back(heap[w][i]);
    sort(vv.begin(),vv.end());
    heap[v][i] = 1 + (vv.size() >= i ? vv[i-1] : 0);
  }
  for(int i = 1;i<SQ;i++) dp[v][i] = heap[v][i];
  for(int i = 1;i<SQ;i++) for(auto w : tree[v]) dp[v][i] = max(dp[v][i],dp[w][i]);
}

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) 
  {
    int x,y;cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  dfs_dp_sq(1);
  return 0;
}
