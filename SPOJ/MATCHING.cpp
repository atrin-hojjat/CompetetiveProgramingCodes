#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+6.66;
const int MAXP = 1.5e5 + 6.66;
vector<int> ed[MAXN];
int match[MAXN];
int match2[MAXN];
bool mark[MAXN];

bool dfs(int v) {
  mark[v] = true;
  for(auto w : ed[v])
   if(match[w]==-1 || (mark[match[w]]==false && dfs(match[w]))) {
     match[w] = v;
     match2[v] = w;
     return true;
   }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,m,p; cin >> n >> m >> p;
  for(int i = 0;i<p;i++) {
    int x,y;cin >> x >> y;
    ed[x].push_back(y);
  }
  int ans = 0;
  memset(match,-1,sizeof match);
  memset(match2,-1,sizeof match2);
  while(true) {
    bool done = true;
    for(int i = 0;i<n+3;i++) mark[i] = false;
    for(int i = 1;i<=n;i++)
      if(!mark[i] && match2[i] == -1 && dfs(i)) {
        ans += 1,done = false;
      }
    if(done) break;
  }
  cout << ans << endl;
  return 0;
}
