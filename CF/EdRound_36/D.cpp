#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500+10;
int mark[MAXN];
int id;
vector<pair<int,int>> adj[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,m;cin >> n >> m;
  for(int i = 0;i<m;i++) {
    int x,y;cin >> x >> y;
    adj[x].push_back(make_pair(y,i));
  }
  
  return 0;
}
