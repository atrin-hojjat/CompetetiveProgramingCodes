#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
int cnt[MAXN];
vector<int> child[MAXN];

void dfs(int v,int h) {
  cnt[h] ^= 1;
  for(auto w : child[v]) dfs(w,h+1);
}

int main() {
  int n;cin >> n;
  for(int i = 1;i<n;i++) {
    int x;cin >> x;
    child[--x].push_back(i);
  }
  dfs(0,0);
  int ans = 0;
  for(int i = 0;i<MAXN;i++) ans += cnt[i] ;
  cout << ans << endl;
  return 0;
}
