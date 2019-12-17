#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+6.66;
int ans[MAXN];
int par[MAXN][10];

int f(int n) {
  int ans = 1;
  while(n) {
    if(n%10)ans *= n%10;
    n/=10;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  for(int i = 0;i<10;i++) ans[i] = i;
  for(int j = 10;j<MAXN;j++) ans[j] = ans[f(j)];
  for(int i = 1;i<MAXN;i++) {
    for(int j = 0;j<10;j++) par[i][j] = par[i-1][j];
    par[i][ans[i]]++;
  }
  int Q;cin >> Q;
  while(Q--) {
    int l,r,k;cin >> l >> r >> k;
    cout << par[r][k] - par[l-1][k] << endl;
  }
  return 0;
}
