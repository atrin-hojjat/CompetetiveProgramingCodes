#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

const int MAXN = 1e5+6.66;
const int MAXK = 100 + 10 + 1;
long long dp[MAXK][MAXN];
vector<int> tree[MAXN];
int a[MAXN];
int last[MAXN];
int n,k;

void dfs(int v = 0,int p = 0) {
  for(auto u : tree[v]) if(u!=p) dfs(u,v);
  last[v] = 1;
  for(auto u : tree[v]) {
    if(u==p) continue;
    for(int i = min(k,last[v] + last[u]);i>-1;i--) {
      dp[i][v] = max(dp[i][v],dp[i][u]);
      for(int j = min(i-1,last[u]);j>-1;--j)
        if(dp[i-j][v] && dp[j][u])
          dp[i][v] = max(dp[i][v],dp[j][u] + dp[i-j][v]);
    }
    last[v] += last[u];
  }
  last[v] = min(k,last[v]);
  dp[1][v] = max(dp[1][v],(long long) a[v]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  cin >> n >> k;
  for(int i = 0;i<n;i++) cin >> a[i];
  for(int i = 1;i<n;++i) {
    int x,y;cin >> x >> y;
    tree[x].push_back(y) ;
    tree[y].push_back(x) ;
  }
  dfs();
  cout << dp[k][0] << endl;
  return 0;
}
