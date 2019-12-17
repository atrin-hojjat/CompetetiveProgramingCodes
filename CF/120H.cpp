#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200 + 20 + 2;
map<string,int> match;
string match2[MAXN];
string str[MAXN];
bool mark[MAXN];

bool dfs(int v) {
  mark[v] = true;
  int S = str[v].length();
  string s = "";
#define DONE { match[s] = v;match2[v] = s; return true; }
#define CHECK if( match.count(s) == 0 || ( !mark[match[s]] && dfs(match[s]) ) ) DONE;
  for(int i = 0;i<S;i++) {
    s = str[v][i];
    CHECK;
    for(int j = i+1;j<S;j++) {
      s += str[v][j];
      string tmp = s;
      CHECK;
      for(int k = j+1;k<S;k++) {
        s += str[v][k];
        string tmp2 = s;
        CHECK;
        for(int w = k+1;w<S;w++) {
          s += str[v][w];
          CHECK;
          s = tmp2;
        }
        s = tmp;
      }
      s = str[v][i];
    }
  }
#undef CHECK
#undef DONE
  return false;
}

int main() {
#ifndef Atrin
  freopen("input.txt","rt",stdin);
  freopen("output.txt","wt",stdout);
#endif
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> str[i];
  int ans = 0;
  while(true) {
    bool done = true;
    memset(mark,0,sizeof mark);
    for(int i = 0;i<n;++i)
      if(!mark[i] && match2[i].length() == 0 && dfs(i))
        ans++,done = false;
    if(done) break;
  }
  if(ans == n) 
    for(int i = 0;i<n;i++) cout << match2[i] << endl;
  else cout << -1 << endl;
  return 0;
}
