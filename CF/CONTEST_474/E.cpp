#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+6.66;
const int mod = 1e9+7;
vector<int> tree[MAXN];
long long odd[MAXN],even[MAXN],odd_u[MAXN],even_u[MAXN];
long long val[MAXN];
long long cnt[MAXN];

void dfs(int v,int p) {
  for(auto u : tree[v]) {
    if( u == p ) continue;
    dfs(u,v);
    even[v] += odd[u];
    odd[v] += even[u];
  }
  for(auto i : tree[v]) {
    long long w = ( even[i] * (even[v] - even[i]) % mod );
    (w += ( odd[i] * (odd[v] - odd[i]) ) %mod ) %=mod;
    (w = ( w - (odd[i] * (even[v] - even[i]))%mod + mod ) % mod);
    (w = ( w - ((odd[v] - odd[i]) * even[i])%mod + mod ) % mod);
    (cnt[v] += w)%=mod;
  }
  even[v] += 1;
}

void dfs_up(int v,int p,int o,int e) {
  even_u[v] = 1 + e;
  odd_u[v] = o;
  for(auto u : tree[v]) 
    if( u != p )
      dfs_up( u,v,e + even[v] - odd[u],o + odd[v] - even[u]) ;
}

int main() {
  int n;cin >> n;
  for(int i = 1;i<=n;i++) cin >> val[i];
  for(int i = 1;i<n;i++) {
    int x,y;cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  dfs(1,0);
  dfs_up(1,0,0,0);
  long long ans = 0;
  for(int i = 1;i<=n;i++) 
  {
    cout << odd[i] << " " << even[i] << " " << odd_u[i] << " " << even_u[i] << endl;
    long long w = ( even[i] * even_u[i] % mod );
    (w += ( odd[i] * odd_u[i] ) %mod ) %=mod;
    (w = ( w - (odd[i] * even_u[i])%mod + mod ) % mod);
    (w = ( w - (odd_u[i] * even[i])%mod + mod ) % mod);
    cout << cnt[i] << endl;
    ans = ( ans + cnt[i] + mod + w * val[i] %mod ) % mod;
  }
  cout << ans << endl;
  return 0;
}
