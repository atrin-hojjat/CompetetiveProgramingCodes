#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 50 + 5;
int arr[MAXN][MAXN];
bool mark[MAXN];
int match[MAXN];
int match2[MAXN];

bool dfs(int v,int n,int k) {
  mark[v] = true;
  for(int i = 0;i<n;i++)
  {
    if(arr[v][i] > k) continue;
    if(match[i] == -1 || (!mark[match[i]] && dfs(match[i],n,k))) {
      match[i] = v;
      match2[v] = i;
      return true;
    }
  }
  return false;
}

bool create(int n,int k) {
  int sz = 0;
  for(int i = 0;i<MAXN;i++) match[i] = match2[i] = -1,mark[i] = false;
  while(true) {
    bool done = true;
    for(int i = 0;i<MAXN;i++)
      mark[i] = false;
    for(int i = 0;i<n;i++)
      if(!mark[i] && match2[i] == -1 && dfs(i,n,k))
        sz++,done = false;
    if(done) break;
  }
  return sz == n;
}

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
      cin >> arr[i][j];
  int l = -1e7-6.66,r = 1e7+6.66;
  while(l<r) {
    int mid = l + ((r-l)>>2);
    if(create(n,mid))
      r = mid;
    else l = mid + 1;
  }
  if(create(n,r)) {
    cout << r << endl;
    for(int i = 0;i<n;i++)
      cout << i+1 << " " << match2[i]+1 << endl;
  }
  return 0;
}
