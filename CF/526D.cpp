#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
int failure[MaxN];
vector<int> children[MaxN];
int st[MaxN], fi[MaxN];
int partial[MaxN];
int ans[MaxN];
int now;

void dfs(int v) {
  st[v] = now++;
  for(auto x : children[v]) dfs(x);
  fi[v] = now;
}

bool is_par(int x, int y) {
  return st[x] <= st[y] && fi[y] <= fi[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  int cur = 0;
  for(int i = 1; i < n; i++) {
    while(cur && str[i] != str[cur]) 
      cur = failure[cur];
    cur += (str[i] == str[cur]);
    failure[i + 1] = cur;
  }
  for(int i = 1; i <= n; i++)
    children[failure[i]].push_back(i);
  dfs(0);
  for(int i = 1; i <= n/k; i++) {
    if(!is_par(i * k - i, i * k)) continue;
    int l = i * k, r = min(n, i * (k + 1));
    while(l < r) {
      int mid = l + (r - l + 1) / 2;
      if(is_par(mid - i * k, mid)) l = mid;
      else r = mid - 1;
    }
    partial[k * i - 1]++;
    partial[l]--;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += partial[i];
    if(ans > 0) cout << 1;
    else cout << 0;
  }
  cout << endl;
  return 0;
}
