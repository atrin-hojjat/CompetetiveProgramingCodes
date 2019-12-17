#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10 + 1;
const int inf = 1e9+7;
int arr[MAXN];
int out[MAXN];
vector<int> rev[MAXN];
bool mark[MAXN];

void dfs(int v) {
  if(mark[v]) return;
  mark[v] = true;
  dfs(out[v]);
}

int main() {
#ifndef Atrin
	freopen("hoofball.in", "rt", stdin);
	freopen("hoofball.out", "wt", stdout);
#endif
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> arr[i];
  int mn = inf;
  if(n==1) {
    cout << 1 << endl;
    return 0;
  }
  for(int i = 0;i<n;i++,mn = inf) {
    int WW = inf;
    for(int j = 0;j<n;j++)
      if(i != j && abs(arr[i] - arr[j]) < mn)
        mn = abs(arr[i] - arr[j]),out[i] = j,WW = arr[j];
      else if(i != j && abs(arr[i] - arr[j]) == mn && WW > arr[j])
        WW = arr[j],out[i] = j;
    rev[out[i]].push_back(i);
  }
  int ans = 0;
  for(int i = 0;i<n;i++)
    if(rev[i].size() == 0 ) ans++,dfs(i);
  for(int i = 0;i<n;i++)
    if(!mark[i])dfs(i),ans++;
  cout << ans << endl;
  return 0;
}
