#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 50 + 5;
const long long inf = 111111111111111LL;//1e14 + 1e13 + 1e12; 
struct Edge {
  int b,e;
  long long A,B;
  Edge() {
    b = e = -1;
    A = B = inf;
  }
  Edge(int e,int b,int A,int B) : A(A), B(B),b(b),e(e) {};

  int other(int x) {
    return b == x ? e : b;
  }
};
vector<Edge> g[MAXN];
long long dis[MAXN][MAXN];
long long DD[3][MAXN];
bool mark[MAXN];
int P[3];

istream& operator>>(istream&i,Edge&e) {
  return i >> e.b >> e.e >> e.A >> e.B;
}

void Dijkstra(int i) {
  memset(mark,0,sizeof mark);
  int st = P[i];
  DD[i][st] = 0;
  priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
  q.push({0,st});
  while(q.size()) {
    int v = q.top().second;
    long long d = q.top().first;
    q.pop();
    if(mark[v]) continue;
    mark[v] = true;

    for(auto e : g[v]) {
      int u = e.other(v);
      if(DD[i][u] > DD[i][v] + e.A + e.B) {
        DD[i][u] = DD[i][v] + e.A + e.B;
        q.push({DD[i][u],u});
      }
    }
  }
}

int main() {
  int n,m;cin >> n >> m;
  cin >> P[0] >> P[1] >> P[2];
  for(int i = 0;i<MAXN;i++)
    DD[0][i] = DD[1][i] = DD[2][i] = inf;
  for(int i = 0;i<MAXN;i++) for(int j = 0;j<MAXN;j++) dis[i][j] = inf;
  for(int i = 0;i<MAXN;i++) dis[i][i] = 0;
  for(int i = 0;i<m;i++) {
    Edge e;
    cin >> e;
    g[e.e].push_back(e);
    g[e.b].push_back(e);
    dis[e.b][e.e] = dis[e.e][e.b] = e.A;
  }
  for(int k = 0;k<n;k++)
    for(int i = 0;i<n;i++)
      for(int j = 0;j<n;j++)
        dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
  for(int i = 0;i<3;i++)Dijkstra(i);
  long long ans = inf;
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
      for(int k = 0;k<n;k++)
        if(DD[0][i] < inf) {
          long long w;
          ans = min(ans,w = DD[0][i] + DD[1][j] + DD[2][k] + dis[i][j] + dis[j][k] + dis[k][i]);
          cout << i << " " << j << " " << k << " " << w  << 
            " " << dis[i][j] << " " << dis[j][k] << " " << dis[k][i] << endl;
        }
  cout << ans << endl;
}
