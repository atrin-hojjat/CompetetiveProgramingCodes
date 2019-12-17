#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+6.66;
vector<int> G[MAXN];
vector<int> B[MAXN];
int matchG[MAXN];
int matchB[MAXN];
bool mark[MAXN];
bool M[2][MAXN];
bool ans[2][MAXN];
vector<int> GG[2][MAXN];

bool dfs(int v) {
  mark[v] = true;
  for(auto w : G[v])
    if(matchB[w] == -1 || ( !mark[matchB[w]] && dfs(matchB[w]) ) ) {
      matchB[w] = v;
      matchG[v] = w;
      return true;
    }
  return false;
}

void test_g(int v,int ch) {
  M[ch][v] = true;
  ans[ch][v] = true;
  if(ch == 1) {
    if(matchG[v]!=-1) test_g(matchG[v],ch^1);
  } else
    for(auto w : GG[ch][v])
      if(!M[1^ch][w]) test_g(w,1^ch);
}

void test_b(int v,int ch) {
  M[ch][v] = true;
  ans[ch][v] = true;
  if(ch == 0 ) {
    if(matchB[v]!=-1) test_b(matchB[v],ch^1);
  } else 
    for(auto w : GG[ch][v])
      if(!M[1^ch][w]) test_b(w,1^ch);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,m,k;cin >> n >> m >> k;
  for(int i = 0;i<k;i++) {
    int x,y;cin >> x >> y;
    x--,y--;
    G[y].push_back(x);
    GG[1][y].push_back(x);
    B[x].push_back(y);
    GG[0][x].push_back(y);
  }
  memset(matchG,-1,sizeof matchG);
  memset(matchB,-1,sizeof matchB);
  int mx = 0;
  for(;;) {
    bool done = true;
    memset(mark,0,sizeof mark);
    for(int i = 0;i<m;i++)
      if( mark[i] == false && matchG[i] == -1 && dfs(i) )
        mx ++,done = false;
    if(done) break;
  }
  vector<int> vv;
  memset(M,0,sizeof M);
  memset(ans,0,sizeof ans);
  for(int i = 0;i<n;i++)
    if(!M[0][i] && matchB[i] == -1) test_g(i,0);
  for(int i = 0;i<n;i++)
    if(!ans[0][i]) vv.push_back(i);
  memset(M,0,sizeof M);
  memset(ans,0,sizeof ans);
  for(int i = 0;i<m;i++)
    if(!M[1][i] && matchG[i] == -1) test_b(i,1);
  for(int i = 0;i<m;i++) 
    if(!ans[1][i]) vv.push_back(i);
  for(auto w : vv) cout << w + 1 << endl;
  return 0;
}
